//
// *** Class AliRsnTarget ***
//
// Base class used wherever it is needed to check the class type of 
// an object (daughter, mother, event) which could be used for 
// cut checking or value computing.
// Since most of these operation are implemented into classes that 
// operate on any of such objects, then this class helps in making sure
// that the object being processed corresponds to what is expected.
//

#ifndef ALIRSNTARGET_H
#define ALIRSNTARGET_H

#include "TNamed.h"

#include "AliRsnEvent.h"

class AliRsnTarget : public TNamed
{
  public:
  
    enum ETargetType
    {
      kDaughter,
      kMother,
      kEvent,
      kTargetTypes
    };

    AliRsnTarget() : fTargetType(kTargetTypes), fEvent(0x0) { /*nothing*/ }
    AliRsnTarget(const char *name, ETargetType type) : TNamed(name, ""), fTargetType(type), fEvent(0x0) { /*nothing*/ }
    AliRsnTarget(const AliRsnTarget& copy) : TNamed(copy), fTargetType(copy.fTargetType), fEvent(copy.fEvent) { /*nothing*/ }
    AliRsnTarget& operator=(const AliRsnTarget& copy) { TNamed::operator=(copy); fTargetType = copy.fTargetType; fEvent = copy.fEvent; return (*this); }
    virtual ~AliRsnTarget() { /*nothing*/ }
    
    Bool_t         IsTarget(ETargetType targetType)  {return (fTargetType == targetType);}
    ETargetType    GetTargetType() const             {return fTargetType;}
    Char_t         GetTargetTypeChar() const;
    const char*    GetTargetTypeName() const;
    void           SetTargetType(ETargetType type)   {fTargetType = type;}
    Bool_t         TargetOK(TObject *object);
    
    AliRsnEvent*   GetEvent() {return fEvent;}
    virtual void   SetEvent(AliRsnEvent *event);

  protected:
  
    ETargetType  fTargetType;  //  target type selected for this object
    AliRsnEvent *fEvent;       //! pointer to current event (useful in many cases)
    
    // ROOT dictionary
    ClassDef(AliRsnTarget, 1)
};

typedef AliRsnTarget::ETargetType RSNTARGET;

#endif
