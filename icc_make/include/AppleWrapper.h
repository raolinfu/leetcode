#ifndef _APPLE_WRAPPER_H__
#define _APPLE_WRAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

struct tagApple; // Warning: 不能使用 extern 修饰

extern struct tagApple *GetInstance(void);
extern void ReleaseInstance(struct tagApple **ppInstance);
extern void SetColor(struct tagApple *pApple, int color);
extern int GetColor(struct tagApple *pApple);

#ifdef __cplusplus
};
#endif

#endif
