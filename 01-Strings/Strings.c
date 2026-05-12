#include "Strings.h"

bool IsEmpty(const char* s){
    return s == NULL || s[0] == '\0';
}

size_t GetLength(const char* s){
    if(s == NULL || s[0] == '\0') return 0;

    return 1 + GetLength(s + 1);
}

bool AreEqual(const char* s1, const char* s2){
    if(s1[0] != s2[0]) return false;
    if(s1[0] == '\0') return true;

    return AreEqual(s1 + 1, s2 + 1);
}

bool AreDecimalDigits(const char* s){
    if(IsEmpty(s)) return false;

    size_t i = 0;
    while(s[i] != '\0'){
        if(s[i] < '0' || s[i] > '9') return false;
        i++;
    }

    return true;
}

bool Contains(const char* s, char c){
    if(IsEmpty(s)) return false;

    size_t i = 0;
    while(s[i] != '\0'){
        if(s[i] == c) return true;
        i++;
    }

    return false;
}

int ToInteger (const char* s){
    if(IsEmpty(s)) return 0;

    int resultado = 0;
    size_t i = 0;
    while(s[i] != '\0'){
        if(s[i] < '0' || s[i] > '9') return 0; 
        resultado = (resultado * 10) + (s[i] - '0');
        i++;
    }

    return resultado;
}

void Concatenate(char* destino, const char* fuente){

    if(destino == NULL || fuente == NULL) return;
    size_t i = 0;
    while(destino[i] != '\0') i++;

    size_t j = 0;

    while(fuente[j] != '\0'){
        destino[i] = fuente[j];
        i++;
        j++;
    }

    destino[i] = '\0';
    return;
}

void Power(char* s, unsigned int n){
    if(IsEmpty(s)) return;

    if(n == 0){
        s[0] = '\0';
        return;
    }
    size_t lenOriginal = GetLength(s);
    unsigned int i;
    unsigned int j;

    for(i=1 ; i < n; i++){
        size_t lenActual = GetLength(s);

        for(j=0; j < lenOriginal; j++){
            s[lenActual + j] = s[j];
        }

        s[lenActual + lenOriginal] = '\0';
    }
    return;
}

void Reverse(char* s){
    if(IsEmpty(s)) return;

    size_t len = GetLength(s);
    char temp;

    for(size_t i = 0; i < len / 2; i++){
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }

    return;
}
bool StartsWith(const char* s, const char* prefix){
    if(IsEmpty(prefix)) return true;
    if(IsEmpty(s)) return false;
    if(s[0] != prefix[0]) return false;
    return StartsWith(s + 1, prefix + 1);
}