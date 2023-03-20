// Sasangp's implementation of sharedptr
// Copyright 2023

#pragma once

namespace sasan
{
    template <typename T>
    class sharedptr
    {
    private:
        T*   hData;
        int* accessCount;
    public:
        // Constructor
        sharedptr(T* ptr)
            : hData(ptr)
            , accessCount(new int(1))
        {}

        // De-Constructor
        ~sharedptr()
        {
            if((*accessCount) > 0)
            {
                (*accessCount)--;
                // Delete actual pointers if nobody points them.
                if((*accessCount) == 0)
                {
                    delete hData;
                    delete accessCount;
                }
            }
        }

        // Copy Constructor
        sharedptr(sharedptr& copiedFrom)
            : hData(copiedFrom.hData)
            , accessCount(copiedFrom.accessCount)
        {
            (*accessCount)++;
        }

        // Copy assignment operator
        sharedptr& operator =(const sharedptr& assignedFrom)
        {
            this->~sharedptr();
            hData = assignedFrom.hData;
            accessCount = assignedFrom.accessCount;
        }

        // Move Constructor
        sharedptr(sharedptr&& movedFrom)
            : hData(std::move(movedFrom.hData))
            , accessCount(std::move(movedFrom.accessCount))
        {
            movedFrom.reset();
        }

        // Move assignment operator
        sharedptr& operator =(sharedptr&& assignedFrom)
        {
            // De-validate this reference so it doesn't count in future shared copies
            this->~sharedptr();
            hData = std::move(assignedFrom.hData);
            accessCount = std::move(assignedFrom.accessCount);

            assignedFrom.reset();
        }
        
        // Mimicking a de-referencing operator on Sharedptr object
        T& operator *() const noexcept
        {
            return *hData;
        }

        // Member access operator
        T* operator ->() const noexcept
        {
            return hData;
        }

        // Reset function
        void reset()
        {
            hData = nullptr;
            accessCount = nullptr;
        }
    };

    template <typename T, typename... Args>
    T* make_shared(const Args&... args)
    {
        return new T{args...};
    }
    
} // namespace sasan