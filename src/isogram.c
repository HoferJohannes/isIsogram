#include "isogram.h"
#include <stdint.h>

//count array[0-255] count of character in string
    /* forEach(character in phrase){
        count[charachter]++
    }
    if (anything in count > 1){
        return false
    }
    return true
*/

//ignore everything but characters (a-z, A-Z) and digits(0-9)
bool isIgnored(char c) {

    bool isLowerChar = (c >= 'a' && c <= 'z');
    bool isUpperChar = (c >= 'A' && c <= 'Z');
    bool isDigit = (c >= '0' && c <= '9');

    return !(isLowerChar || isUpperChar || isDigit);
}

char toLowerCase(char c){
    if(c >= 'A' && c <= 'Z'){
        return c - ('A' - 'a');
    }
    return c;
}

bool is_isogram(const char phrase[]){
    uint16_t i = 0;
    uint16_t count[255] = {0};

    while(phrase[i] != '\0'){
        toLowerCase(phrase[i]);
        if (phrase[i] == ' ') {    //ignore blankspace
        //do nothing
        }else {
            count[phrase[i]]++;         //count number of times character appears in string
        }
        i++;
    }
    for (uint16_t i = 0; i<255; i++) {      
        if(count[i] > 1){
        return false;
        }
    }
    return true;
}
