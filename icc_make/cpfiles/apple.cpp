#include "apple.h"

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
