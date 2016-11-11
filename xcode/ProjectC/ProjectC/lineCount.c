//
//  lineCount.c
//  ProjectC
//
//  Created by Yossi Spektor on 09/11/2016.
//  Copyright © 2016 Yos Si. All rights reserved.
//

#include <stdio.h>

void main() {
    int c, nl;
    
    nl = 0;
    while ( (c = getchar()) != EOF) {
        if(c == '\n') {
            ++nl;
        }
    }
    printf("%d\n", nl);
}
