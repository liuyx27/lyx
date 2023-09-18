#ifndef UNPACKAGE_H
#define UNPACKAGE_H

#include <QFile>
#include <QDebug>
#include <QDir>
#include <QDateTime>
#include <QStandardPaths>
#include <windows.h>

class Unpackage
{

public:
    /*
     * tarName  包名
     * des      解包路径
     * 1        原文件打开失败
     * 2        目标文件创建失败
     * 0        正常返回
     */
    static int unpackage(QString tarName, QString des)
    {
        QFile tar(tarName);
        if(!tar.open(QFile::ReadOnly))
        {
            qDebug() << "unpackage: source file open failed" << endl;
            return 1;
        }

        int flag, shortCutPathLength, pathLength, fileLength;
        QString relativePath, Path;
        //读取相对路径长度
        while (tar.read((char*)&flag, sizeof(flag)))
        {
            //快捷方式处理
            if(flag == 1)
            {
                tar.read((char*)&shortCutPathLength, sizeof(shortCutPathLength));
                char* Path_c = new char[shortCutPathLength + 1];
                tar.read(Path_c, shortCutPathLength);
                Path_c[shortCutPathLength] = '\0';
                Path = QString::fromStdString(std::string(Path_c));
                delete[] Path_c;
                //读取路径长度
                tar.read((char*)&pathLength, sizeof(pathLength));
                //读取相对路径
                char* relativePath_c = new char[pathLength + 1];
                tar.read(relativePath_c, pathLength);
                relativePath_c[pathLength] = '\0';
                relativePath = QString::fromStdString(std::string(relativePath_c));
                delete[] relativePath_c;
                //创建目录
                QString absPath = des + relativePath;
                QString dirName = absPath.remove(absPath.lastIndexOf("/"), absPath.length() - absPath.lastIndexOf("/"));
                QDir dir(dirName);
                if(!dir.exists())
                {
                    qDebug()<<"dirName"<<dirName<<endl;
                    dir.mkdir(dirName);
                }
                QString sName = des + relativePath + ".lnk";
                QFile::link(Path, sName);
            }
            //文件处理
            else
            {
                //读取路径长度
                tar.read((char*)&pathLength, sizeof(pathLength));
                //读取相对路径
                char* relativePath_c = new char[pathLength + 1];
                tar.read(relativePath_c, pathLength);
                relativePath_c[pathLength] = '\0';
                relativePath = QString::fromStdString(std::string(relativePath_c));
                delete[] relativePath_c;
                //创建目录
                QString absPath = des + relativePath;
                QString dirName = absPath.remove(absPath.lastIndexOf("/"), absPath.length() - absPath.lastIndexOf("/"));
                QDir dir(dirName);
                if(!dir.exists())
                {
                    dir.mkdir(dirName);
                }
                //读文件时间
                qint64 birthTime_s, lastModifiedTime_s, lastReadTime_s;
                QDateTime birthTime, lastModifiedTime, lastReadTime;
                tar.read((char*)&birthTime_s, sizeof(birthTime_s));
                tar.read((char*)&lastModifiedTime_s, sizeof(lastModifiedTime_s));
                tar.read((char*)&lastReadTime_s, sizeof(lastReadTime_s));
                birthTime = QDateTime::fromSecsSinceEpoch(birthTime_s);
                lastModifiedTime = QDateTime::fromSecsSinceEpoch(lastModifiedTime_s);
                lastReadTime = QDateTime::fromSecsSinceEpoch(lastReadTime_s);
                //读权限
                int W;
                bool isWriteAble;
                tar.read((char*)&W, sizeof(W));
                if(W == 1)
                {
                    isWriteAble = true;
                }
                else
                {
                    isWriteAble = false;
                }
                //读取文件长度
                tar.read((char*)&fileLength, sizeof(fileLength));
                //读取文件
                QFile data(des + relativePath);
                if(!data.open(QFile::WriteOnly))
                {
                    qDebug() << "unpackage: target file create failed" << endl;
                    return 2;
                }
                if(fileLength)
                {
                    //每次循环读1024B
                    char* buf = new char[1024];
                    for(int i = 0; i < fileLength / 1024; i++)
                    {
                        tar.read(buf, 1024);
                        data.write(buf, 1024);
                    }
                    delete[] buf;
                    //读剩余部分
                    char* leave = new char[fileLength % 1024];
                    tar.read(leave, fileLength % 1024);
                    data.write(leave, fileLength % 1024);
                    delete[] leave;
                }
                else
                {
                    data.write("");
                }
                //修改文件时间
                data.setFileTime(birthTime, QFileDevice::FileBirthTime);
                data.setFileTime(lastModifiedTime, QFileDevice::FileModificationTime);
                data.setFileTime(lastReadTime, QFileDevice::FileAccessTime);
                if(isWriteAble)
                {
                    data.setPermissions(QFile::WriteUser);
                }
                else
                {
                    wchar_t* fileName = (wchar_t*)reinterpret_cast<const wchar_t *>((des + relativePath).utf16());
                    SetFileAttributes((const wchar_t*)fileName, FILE_ATTRIBUTE_READONLY);
                }
                data.close();
            }
        }
        return 0;
    }
};

#endif // UNPACKAGE_H
