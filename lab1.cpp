#include <iostream>
#include <string>

int main()
{
int a = 0;
std::cout << a << std::endl;

short b;
long c;
char e; // egész tipus 1 bájt

uint16_t a1; // ezek nem részei az alap nyelvnek
int32_t a2;
uint8_t a3;

// include help: cppreference.com

double d1 = 3.14;
float f = 3.14f; //értékvesztés történhet kell az f a végére!!!

std::string s = "Hello, world!";
const char* s1 = "Hello, world!";

bool b1 = true;
bool b2 = false;

if (d1) {
}

int n = 10;
while (n--) {
std::cout << n << std::endl;
}

for (int i = 0; i < 10; ++i) {
std::cout << i << std::endl;
}

// reference ////////////////////////////////////////////////////////////////////////////////////////////////////


int aa = 12;
const int bb = 8;
const int& bb1 = bb;


int& aa1 = aa;

// pointer ////////////////////////////////////////////////////////////////////////////////////////////////////

int aaa = 12;

std::cout << "a: " << aaa << ", a címe: " << &aaa << std::endl;

int* ppp = &aaa; // pointer(*)-el rámutatok egy integerre


std::cout << "p: " << ppp << ", p altal mutatott helyen lévő érték: "
<< *ppp << std::endl;

int* ppp1 = nullptr;

int bbb = 5;
ppp1 = &bbb;

int ccc = 7;
ppp1 = &ccc;

int** ppp2 = &ppp;

const int bbb1 = 10;
const int* pb = &bbb1;

float fff = 3.14f;
const float* pf = &fff;

float* const pf1 = &fff;
*pf1 = 3.56f;

const int* const ppp3 = &aaa;

// memória (ilyet soha mert nincs garbage collector) //////////////////////////////////////////////////////////////////////////////////////////////////////

// int aaaa[10];
// int* bbbb = new int[10];

// delete[] bbbb;



}
