#include "AppleWrapper.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
int test_cplus(void)
{
    struct tagApple * pApple;
    pApple = GetInstance();
    SetColor(pApple, 1);
    printf("color = %d\n", GetColor(pApple));
    ReleaseInstance(&pApple);
    assert(pApple == 0);
    return 0;
}
