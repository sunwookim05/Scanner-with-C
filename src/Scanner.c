#include "main.h"
#include "System.h"
#include "Scanner.h"

void* nextChar(void){
    char c;
    scanf("%c", &c);
    getchar();
    return (char*)c;
}

void* nextByte(void){
    int8_t b;
    scanf("%hhd", &b);
    getchar();
    return (int8_t*)b;
}

void* nextShort(void){
    int16_t s;
    scanf("%hd", &s);
    getchar();
    return (int16_t*)s;
}

void* nextInt(void){
    int32_t i;
    scanf("%d", &i);
    getchar();
    return (int32_t*)i;
}

void* nextLong(void){
    int64_t l;
    scanf("%lld", &l);
    getchar();
    return (int64_t*)l;
}

void* nextUByte(void){
    uint8_t b;
    scanf("%hhu", &b);
    getchar();
    return (uint8_t*)b;
}

void* nextUShort(void){
    uint16_t s;
    scanf("%hu", &s);
    getchar();
    return (uint16_t*)s;
}

void* nextUInt(void){
    uint32_t i;
    scanf("%u", &i);
    getchar();
    return (uint32_t*)i;
}

void* nextULong(void){
    uint64_t l;
    scanf("%llu", &l);
    getchar();
    return (uint64_t*)l;
}

void* nextBoolean(void){
    String s = (String)calloc(0, sizeof(char) * 5);
    scanf("%s", s);
    if(atoi(s)|| !strncmp(s, "true", 4) || !strncmp(s, "True", 4) || !strncmp(s, "TRUE", 4)){
        free(s);
        return (boolean*)true;
    }else{
        free(s);
        return (boolean*)false;
    }
}

void* nextFloat(void){
    float f;
    scanf("%f", &f);
    getchar();
    return (float*)f;
}

void* nextDouble(void){
    double d;
    scanf("%lf", &d);
    getchar();
    return (double*)d;
}

void* nextLDouble(void){
    long double ld;
    scanf("%Lf", &ld);
    getchar();
    return (long double*)ld;
}

void* next(void){
    String s = (String)calloc(0, sizeof(char) * 4096);
    scanf("%s", s);
    s = (String)realloc(s, sizeof(char) * (strlen(s) + 1));
    getchar();
    return (String*)s;
}

void* nextLine(void){
    String s = (String)calloc(0, sizeof(char) * 4096);
    scanf("%[^\n]", s);
    getchar();
    return (String*)s;
}

/**
* Constructs a new {@code Scanner} that produces values scanned
* from the specified input stream. Bytes from the stream are converted
* into characters using the underlying platform's
*
* @param  source An input stream to be scanned
*/
Scanner new_Scanner(struct __stdin_t source){
    Scanner scanner = {
        .nextChar = (char(*)(void))nextChar,
        .nextByte = (int8_t(*)(void))nextByte,
        .nextShort = (int16_t(*)(void))nextShort,
        .nextInt = (int32_t(*)(void))nextInt,
        .nextLong = (int64_t(*)(void))nextLong,
        .nextUByte = (uint8_t(*)(void))nextUByte,
        .nextUShort = (uint16_t(*)(void))nextUShort,
        .nextUInt = (uint32_t(*)(void))nextUInt,
        .nextULong = (uint64_t(*)(void))nextULong,
        .nextBoolean = (boolean(*)(void))nextBoolean,
        .nextFloat = (float(*)(void))nextFloat,
        .nextDouble = (double(*)(void))nextDouble,
        .nextLDouble = (long double(*)(void))nextLDouble,
        .next = (String(*)(void))next,
        .nextLine = (String(*)(void))nextLine
    };
    return scanner;
}
