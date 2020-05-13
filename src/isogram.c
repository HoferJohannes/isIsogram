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

bool is_isogram(const char phrase[]){
    uint16_t i = 0;
    uint16_t count[255] = {0};

    while(phrase[i] != '\0'){
        if(phrase[i] >= 'A' && phrase[i] <= 'Z'){
            count[(phrase[i] + ('a'-'A'))] +=1;     //ignore capitalization 
        }
        else if (phrase[i] == ' ') {    //ignore blankspace
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
