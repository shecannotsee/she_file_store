//
// Created by shecannotsee on 2022/11/29.
//

#ifndef SHEFILESTORE_TEST_DIR_INFO_TEST_H_
#define SHEFILESTORE_TEST_DIR_INFO_TEST_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <iostream>
#include <string>

namespace dir_info_test {

void main() {
  std::string path = "../test_dir";// ../file_1.txt
  // 打开目录
  DIR* p = opendir(path.c_str());/* success check */ {
    if (p == NULL) {
      std::cout << "open dir faild : "<< std::string(strerror(errno))<<std::endl;
    } else {
      std::cout << "open dir success.\n";
    }
  }

  // 读取目录信息
//  dirent64* dir = readdir64(p);/* success check */ {
//    if (dir == NULL) {
//      std::cout << "readdir faild : "<< std::string(strerror(errno))<<std::endl;
//    } else {
//      std::cout << "read dir message success.\n";
//    }
//  }

  /* 读取目录信息 */{
    dirent* dir;
    do {
      dir = readdir(p);
      if( strcmp( dir->d_name , "." ) == 0 || strcmp( dir->d_name , "..") == 0 )
        continue;
      else {
        std::cout << "dir->d_name : "   << dir->d_name        << " ============= ";
        std::cout << "dir->d_reclen : " << (int)dir->d_reclen << " ============= ";
        std::cout << "dir->d_type : "   << (int)dir->d_type   << " ============= ";
        if (dir->d_type==DT_DIR) {
          std::cout<< "dir";
        }
        else if (dir->d_type==DT_REG) {
          std::cout<<"file\t";
          /* 获取文件大小 */ {
            struct stat stat_buffer;
            std::cout << (path + "/" + std::string(dir->d_name)) << " : ";
            if (stat((path + "/" + std::string(dir->d_name)).c_str(), &stat_buffer) == 0) {
              std::cout << "stat_buffer.st_size : " << stat_buffer.st_size;
            }
          }
        }
        std::cout<<std::endl;
      }
    } while ( dir != NULL );
  }

  // 关闭目录
  {
    if (closedir(p) == -1) {
      std::cout << "close dir faild:" << std::string(strerror(errno)) << std::endl;
    } else /* closedir(p)==0 */{
      std::cout << "close dir success.\n";
    }
  }
};

};// namespace dir_info_test

#endif //SHEFILESTORE_TEST_DIR_INFO_TEST_H_
