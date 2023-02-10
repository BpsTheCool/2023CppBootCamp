#ifndef SH_PTR_H
#define SH_PTR_H

#endif // SH_PTR_H

class sh_ptr
{
    int *m_counter;
    int *nomber;
public:
    sh_ptr(int* conter);
    sh_ptr(sh_ptr &conter);
    ~sh_ptr();
    int getShareptr();



};
