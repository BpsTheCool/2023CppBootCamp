#pragma once
#include <string>

namespace sasan
{
    class Sharedptr
    {
    private:
        int *hData;
        int *accessCount;
    public:
        // Constructor
        Sharedptr(int *ptr);
        // De-Constructor
        ~Sharedptr();
        // Copy Constructor
        Sharedptr(Sharedptr& copiedFrom);
        // Move Constructor
        Sharedptr(Sharedptr&& movedFrom);
        // Reset function
        void reset();
        // To String function
        std::string toString() const;
        // Mimicking a de-referencing star operator on Sharedptr object
        int& operator *();
        // Assignment operator
        Sharedptr& operator =(const Sharedptr& assignedFrom);
    };

    int* make_shared(int input);
    
} // namespace sasan
