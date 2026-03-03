# Access specifiers
    private
    public
    protected
default calss --> private
default struct --> public


# Encapsulation:
    
    wrapping-up of data & member functions into a single class is called encapsulation.
    main motive is to hide the sensative data. ( fields set in private or protected. )

# this pointer

    this -> prop === *(this).prop
    this is going to point the current object which is getting calling.

# Inheritance :

    Properties & member functions of base class are passed on to the derived class. 
    Mainly used for code reusability.
    
    
    class A {}
    
    class B: public A {}

    when B object got created :
    constructor = A(base constructor) then B (derived constructor)
    distructor  = B (derived distructor) then A (base distructor)

    constructor:
    B(int x , int y , int z) : A(x, y) {}
    
types of inheritance :
    1. single inheritance
    2. mulit-level inheritance
    3. multiple inheritance ( class C: public A , public B {} )
    4. Hirarical inheritance ( Class B : public A {}    class C : public A {} )
    5. Hybrid inheritance ( combinataion of more than one type)

# Polymorphism 

    polymorpism is the ability of the objects to take on different forms or behave in different ways
    depends on the context in which they are used.

    1. compiletime polimorphism (function overloading & constructor overloading & operator overloading )
    2. runtime polymorphism (dynamic polymorphism)
        function overriding --> depends on inheritance.  
                                Parent & child both contains the same function with differnt implementation
                                The parent class function is said to be overriden.

    3. virtual functions: A virtual function that you expect to be redefined in derived classes.
            Just thinks that this function will be reimplemented in child class.
            Dynamic in nature
            defined by keyword vitual in baseclass and are always decleared in base class and overriden in
            child class.

            VIRTUAL FUNCTION CALLS AT RUNTIME..!!
    
    

# ABSTRACTION :

    two ways to atcive abstraction:
    1. hiding all the unecessary details and showing only the important parts.
    access modifiers are used to atcive abstraction.

    2. abstract class:
        
        Abstract class are used to provide the base class form which other class can be derived.
        They cannot be instansiated and are meant to be inherited.
        
        Typically used to define an interface for derived classes.


        virtual R fun() = 0; // pure virtual function.
        (Class whichever have PVF, it is said to be abstract class. )

# STATIC:



# HIDING vs OVER-RIDE:

## Hiding:
    Name lookup happens before overload resolution.
    So:
    1. Compiler finds f in Derived.
    2. Stops looking in Base.
    3. Overload resolution happens only on Derived's overload set.

## Override:

    1. best practise is to add override for all override methods in derived class.
    2. this prevents un-necessary method hiding issues.

## final:

    1. derived class cannot inherited.
    2. derived class 