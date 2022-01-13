#include<iostream>
#include "apple.h"

#ifdef __cplusplus
extern "C" {
#include "add.h"
}
#endif

Apple::Apple() : m_nColor(0)
{
}
 
void Apple::SetColor(int color)
{
    m_nColor = color;
}
 
int Apple::GetColor(void)
{
    return m_nColor;
}

int main(){
	int a = add(3, 4);
	Apple app;
	app.SetColor(a);
	std::cout<< app.GetColor()<< std::endl;

	return 0;
}
