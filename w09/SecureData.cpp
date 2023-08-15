/*
*****************************************************************************
						  Workshop - #9 (Part-2)
Full Name  : Akash yadav
Student ID#: 172566218
Email      : ayadav35@myseneca.ca
Date       : 02/08/2023

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// Workshop 9 - Multi-Threading
// SecureData.cpp

#include "SecureData.h"
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

namespace w9 {

void splitText(char *text, int nbytes, char ***parts, int *partSize) {
  if (*parts) {
    delete[] * parts;
  }
  *parts = new char *[4]; // array to hold 4 character pointers(c style strings)
  int divNBytes = nbytes / 4;
  int divRemainder = nbytes % 4;

  size_t i = 0;

  for (; i < 3; i++) {
    (*parts)[i] = new char[divNBytes + 1];
    memcpy((*parts)[i], text + (i * divNBytes), divNBytes);
    (*parts)[i][divNBytes] = '\0';
    partSize[i] = divNBytes;
  }
  (*parts)[i] = new char[divNBytes + 1 + divRemainder];
  memcpy((*parts)[i], text + (i * divNBytes), divNBytes + divRemainder);
  (*parts)[i][divNBytes + divRemainder] = '\0';
  partSize[i] = divNBytes + divRemainder;
}

void mergeText(char *text, char **parts, int *partSize) {
  int offset = 0;
  for (size_t i = 0; i < 4; i++) {
    memcpy(text + offset, parts[i], partSize[i]);
    offset += partSize[i];
  }
}

void converter(char *t, char key, int n, const Cryptor &c) {

  for (int i = 0; i < n; i++)
    t[i] = c(t[i], key);
}

SecureData::SecureData(const char *file, char key, ostream *pOfs) {
  ofs = pOfs;

  // open text file
  fstream input(file, std::ios::in);
  if (!input)
    throw string("\n***Failed to open file ") + string(file) + string(" ***\n");

  // copy from file into memory
  input.seekg(0, std::ios::end);
  nbytes = (int)input.tellg() + 1;

  text = new char[nbytes];

  input.seekg(ios::beg);
  int i = 0;
  input >> noskipws;
  while (input.good())
    input >> text[i++];
  text[nbytes - 1] = '\0';
  *ofs << "\n"
       << nbytes - 1 << " bytes copied from file " << file
       << " into memory (null byte added)\n";
  encoded = false;

  // encode using key
  code(key);
  *ofs << "Data encrypted in memory\n";
}

SecureData::~SecureData() { delete[] text; }

void SecureData::display(std::ostream &os) const {
  if (text && !encoded)
    os << text << std::endl;
  else if (encoded)
    throw std::string("\n***Data is encoded***\n");
  else
    throw std::string("\n***No data stored***\n");
}

void SecureData::code(char key) {

   thread t1(converter, text, key, 500, Cryptor());
   thread t2(converter, text + 500, key, 500, Cryptor());
   thread t3(converter, text + 1000, key, 500, Cryptor());
   thread t4(converter, text + 1500, key, nbytes - 1500, Cryptor());

   t1.join();
   t2.join();
   t3.join();
   t4.join();

  encoded = !encoded;
}

void SecureData::backup(const char *file) {
  if (!text)
    throw std::string("\n***No data stored***\n");
  else if (!encoded)
    throw std::string("\n***Data is not encoded***\n");
  else {
    ofstream F(file, ios::binary);
    if (!F)
      throw string("\n***Failed to open file ") + string(file) +
          string(" ***\n");

    F.write(text, nbytes);
    F.close();
  }
}

void SecureData::restore(const char *file, char key) {
  ifstream F(file, ios::binary);
  if (!F)
    throw string("\n***Failed to open file ") + string(file) + string(" ***\n");

  delete[] text;
  F.seekg(0, std::ios::end);
  nbytes = (int)F.tellg();

  text = new char[nbytes];

  F.seekg(ios::beg);

  F.read(text, nbytes);
  F.close();

  *ofs << "\n"
       << nbytes << " bytes copied from binary file " << file
       << " into memory.\n";

  encoded = true;

  // decode using key
  code(key);

  *ofs << "Data decrypted in memory\n\n";
}

std::ostream &operator<<(std::ostream &os, const SecureData &sd) {
  sd.display(os);
  return os;
}
} // namespace w9
