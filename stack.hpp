#ifndef stack_h
#define stack_h

using namespace cop4530;

template <typename T>
Stack<T>::Stack()
{
theSize = 0;
theCapacity = 0;
array = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] array;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &rhs)
{
    theSize = rhs.theSize;
    theCapacity = rhs.theCapacity;
    array = new T[theCapacity];
    for(int i = 0; i < theSize;i++)
    {
        array[i] = rhs.array[i];
    }
}

template <typename T>
Stack<T>::Stack(Stack<T> &&rhs)
{
theSize = rhs.theSize;
	theCapacity = rhs.theCapacity;
	array = rhs.array;
	rhs.theSize = 0;
	rhs.theCapacity = 0;
	rhs.array = nullptr;
}


template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> &rhs)
{
     theSize = rhs.theSize;
  theCapacity = rhs.theCapacity;
	 array = new T[rhs.theCapacity];
	 for (int i = 0; i < theSize; i++)
	 {
		 array[i] = rhs.array[i];
	 }
	 return *this;
}

template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> &&rhs)
{
     theSize = rhs.theSize;
	 theCapacity = rhs.theCapacity;
	 array = new T[rhs.theCapacity];
	 for (int i = 0; i < theSize; i++)
	 {
		 array[i] = rhs.array[i];
	 }
	 return this;
}

template <typename T>
bool Stack<T>::empty() const
{
return (theSize == 0);
}

template <typename T>
void Stack<T>::clear()
{
    while(!array.empty())
    {
        array.pop();
    }
}

template <typename T>
T& Stack<T>::top()
{
    return array[theSize-1];
}

template <typename T>
const T& Stack<T>::top() const 
{
    return array[theSize-1];
}

template <typename T>
void Stack<T>::pop()
{
    if(theSize>0)
    {
        theSize--;
    }
}

template <typename T>
void Stack<T>::push(const T& x)
{
     if (theSize == theCapacity)
	   {
		   doubleCapacity();
	   }
		   array[theSize] = x;
		   theSize++;
}

template <typename T>
void Stack<T>::push(T&& x)
{
     if (theSize == theCapacity)
	   {
		   doubleCapacity();
	   }
		   array[theSize] = x;
		   theSize++;
}

template <typename T>
int Stack<T>::size() const
{
    return theSize;
}

template <typename T>
void Stack<T>::doubleCapacity()
{
     if (theCapacity == 0)
	   {
		   reserve(1);
	   }
	   else
	   {
		   reserve(theCapacity * 2);
	   }
}

 template<typename T>
   void Stack<T>::reserve(int newCapacity)
   {
	   if (newCapacity > theCapacity)
	   {
		   T* temp = new T[newCapacity];
		   for (int i = 0; i < theSize; i++)
		   {
			   temp[i] = array[i];
		   }
		   delete[] array;
		   array = temp;
		   theCapacity = newCapacity;
	   }
   }

    template <typename T>
    void Stack<T>::print(std::ostream& os, char ofc) const
    {
        for(int i = 0; i < theSize; i++)
        {
            os << array[i] << ofc;
        }
    }

    template <typename T>
    std::ostream& cop4530::operator<<(std::ostream& os, const Stack<T>& a)
    {
        a.print(os);
        return os;
    }

    template <typename T>
    bool cop4530::operator==(const Stack<T>& a, const Stack<T>& b)
    {
        if(a.size() != b.size())
        {return false;}

        Stack<T> c = a;
        Stack<T> d = b;
        
            while(!c.empty())
            {
                if(c.top() == d.top())
                {
                    c.pop();
                    d.pop();
                }
                else
                {
                    return false;
                }
            }
        

        return true;
        
    }

    template <typename T>
    bool cop4530::operator!=(const Stack<T>& a, const Stack<T>& b)
    {
      return !(a==b);  
    }

   template <typename T>
bool cop4530::operator<=(const Stack<T>& a, const Stack<T>& b)
{
    Stack<T> c = a;
    Stack<T> d = b;
    
    if(a.size() > b.size())
    {
        return false;
    }

    while(!c.empty())
    {
        if(c.top() <= d.top())
        {
            c.pop();
            d.pop();
        }
        else
        {
            return false;
        }
    }

    return true;
}



    









#endif