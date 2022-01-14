#ifndef __APPLE_H__
#define __APPLE_H__

class Apple
{
public:
    Apple();
    int GetColor(void);
    void SetColor(int color);
    
private:
    int m_nColor;
};
#endif
