#ifndef QTFILEREADER_H
#define QTFILEREADER_H

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cerrno>

namespace Quantum{
    std::string QTReadFile(const char* filename);
}

#endif