#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H


class MySharedPtr {
    int *m_ptr;
    int *m_ref_count;

    public:
    MySharedPtr(int *ptr);
    MySharedPtr(const MySharedPtr &copy);
    int& operator*() const;
    int* operator->() const;
    MySharedPtr& operator=(const MySharedPtr& copy);
    void getRefCountr();
   ~MySharedPtr();
};
#endif // SHAREDPOINTER_H
