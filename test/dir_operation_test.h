//
// Created by shecannotsee on 2022/11/29.
//

#ifndef SHEFILESTORE_TEST_DIR_OPERATION_TEST_H_
#define SHEFILESTORE_TEST_DIR_OPERATION_TEST_H_

#include <unistd.h>

#include <iostream>
#include <string>

#include <sys/stat.h>

namespace dir_operation_test {

void main() {
  std::string path = "../test_dir";
  /* get now path */ {
    char buffer[256];
    getcwd(buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
  }
  /* change path */ {
    char buffer[256];
    getcwd(buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
    if (chdir(path.c_str()) == 0) {
      getcwd(buffer, sizeof(buffer));
      std::cout << buffer << std::endl;
    } else {
      std::cout<<"chdir failed.\n";
    }
  }
  /* mkdir */ {
    if (mkdir((path+"/"+"dir_3").c_str(), /*目录权限*/0777) == 0) {
      std::cout<<"mkdir success."<<std::endl;
    } else {
      std::cout<<"mkdir failed."<<std::string(strerror(errno))<<std::endl;
    }
    if (rmdir((path+"/"+"dir_3").c_str())==0) {
      std::cout<<"rmdir success."<<std::endl;
    } else {
      std::cout<<"rmdir failed."<<std::string(strerror(errno))<<std::endl;
    }
  }

};

};// namespace dir_operation_test

#endif //SHEFILESTORE_TEST_DIR_OPERATION_TEST_H_
