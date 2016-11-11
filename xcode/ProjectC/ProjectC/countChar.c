//
//  main.c
//  ProjectC
//
//  Created by Yossi Spektor on 03/11/2016.
//  Copyright © 2016 Yos Si. All rights reserved.
//

#include <stdio.h>

void main() {
    long nc;
    
    nc = 0;
    while(getchar() != EOF) {
        ++nc;
    }
    printf("%ld\n", nc);

    
} //end of main
