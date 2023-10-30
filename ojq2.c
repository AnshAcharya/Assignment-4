#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);
    int i = 0;
    while(i < n)
    {
        while(i<n) {
            
            if(str[i] == '"') {
               i++;
                break;
            }
            if(str[i] == ',') {
                str[i] = '*';
            }
            i++;
            
        }
        while(i<n) {
            
            if(str[i] == '"') {
                i++;
                break;
            }
            i++;
            
        }
        
    }
    
  
   
    printf("%s", str);
    return 0;
}

