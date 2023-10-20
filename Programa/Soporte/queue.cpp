#include "List.cpp"

#ifndef QUEUE

#define QUEUE 1

template <typename T>
class Queue {
    protected:
        List<T> *queueList;

    public:
        Queue()
        {
            queueList = new List<T>();
        }

        // agregar al final
        void enqueue(T *pValue)
        {
            queueList->add(pValue);
        }

        T *dequeue()
        {
            return queueList->remove(0);
        }

        T *front()
        {
            T *result = NULL;
            if (!queueList->isEmpty())
            {
                result = queueList->find(0);
            }
            return result;
        }
};

#endif