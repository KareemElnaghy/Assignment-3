//
// Created by Kareem Elnaghy on 10/23/23.
//

#ifndef ADS_ASSIGNMENT_3_QUEUET_H
#define ADS_ASSIGNMENT_3_QUEUET_H


template <class Type>

class Queuet
{
public:

    Queuet(int nelements = 128);		// Constructor
    Queuet (const Queuet <Type> &);	// Copy Constructor
    ~Queuet();						// Destructor

    // Member Functions
    void enqueue(Type );			// Add to rear
    void dequeue(Type &);			// Remove from front
    void queueFront(Type &) const;	// retrieve front
    bool queueIsEmpty() const;	// Test for Empty queue
    bool queueIsFull() const;		// Test for Full queue
    int  queueLength() const;		// Queue Length

private:
    Type *queue;					// pointer to dynamic array
    int front, rear, count, MaxSize;

};


#endif //ADS_ASSIGNMENT_3_QUEUET_H
