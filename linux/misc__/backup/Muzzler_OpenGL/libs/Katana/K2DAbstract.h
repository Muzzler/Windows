////////////////////////////////////////////////////////////////////////////////
// GUARDS
////////////////////////////////////////////////////////////////////////////////

#ifndef __K2DABSTRACT_H__
#define __K2DABSTRACT_H__

//+-----------------------------------------------------------------------------
//
//  Abstract Class:
//      K2DABSTRACT
//
//  Synopsis:
//      Differentiates which of the two possible arcs could match the given arc
//      parameters.
//
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// INCLUDE
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS
////////////////////////////////////////////////////////////////////////////////

class   K2D;
class   K2DAbstract;
class   K2DRenderable;
class   K2DAbstractComponent;
class   K2DCamera;
struct  K2DCameraProperties;
struct  K2DRenderData;
class   K2DMatrixFactory;
class   K2DBackBuffer;
class   K2DMatrixFactory;
class   K2DModelFactory;
class   K2DRootPane;
struct  K2DWindowProperties;
class   K2DWindow;
class   K2DImagePanel;


////////////////////////////////////////////////////////////////////////////////
// DEFINE
////////////////////////////////////////////////////////////////////////////////

#define K2DABSTRACT_LL(str1, str2)                            str1 str2

////////////////////////////////////////////////////////////////////////////////
// DECLARATION
////////////////////////////////////////////////////////////////////////////////

class K2DAbstract
{
public:
    
    // Constructor
    K2DAbstract();
    
    // Deconstructor
    ~K2DAbstract();

    // Variables
    // { NONE }

    // Accessors
    // { NONE }

    // Mutators
    // { NONE }

    // Builders
    // { NONE }

    // Factory
    // { NONE }

    // Additional
    // { NONE }

protected:

    // Pure Virtual
    virtual bool                    Initialize() = 0;                           // Initialize  
    virtual void                    Deinitialize() = 0;                         // Shutdown   

    // Virtual    
    virtual string                  GetClass();                                 // Class type    
    virtual bool                    operator==(K2DAbstract * xAbstract);        // Class type       
    virtual string                  ToString();                                 // Class type 

public:
    virtual bool                    isClass(string xClass) final; // To prevent it from being overridden, I put a final here.

    // Implementations
    // { NONE}
};

#endif
