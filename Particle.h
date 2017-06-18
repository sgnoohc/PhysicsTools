// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#ifndef Particle_h
#define Particle_h

// C++
#include <algorithm>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <vector>

// ROOT
#include "TLorentzVector.h"
#include "TString.h"

#include "Math/LorentzVector.h"

class Particle
{

  enum VarType
  {
    kINT = 0,
    kFLT = 1,
    kTLV = 2,
    kSTR = 3,
    kNON = -1
  };

  typedef std::vector<TString> vecStr;
  typedef std::map<TString, VarType> mapTyp;
  typedef std::map<TString, float> mapFlt;
  typedef std::map<TString, int> mapInt;
  typedef std::map<TString, TLorentzVector> mapTLV;
  typedef std::map<TString, TString> mapStr;

  private:

    //================================================================================================
    // Members
    //================================================================================================

    // Vector to hold the types
    vecStr var_Nam;
    mapStr var_Ttl;
    mapTyp var_Typ;
    mapFlt var_Flt;
    mapInt var_Int;
    mapTLV var_TLV;
    mapStr var_Str;

  public:

    //================================================================================================
    // Functions
    //================================================================================================

    Particle();
    ~Particle();

    bool varExists(TString name);
    void createFltVar(TString name, TString title="");
    void createIntVar(TString name, TString title="");
    void createTLVVar(TString name, TString title="");
    void createStrVar(TString name, TString title="");

    static void printError             (TString name, TString msg, TString action, VarType type=kNON);
    static void printAlreadyExistsError(TString name, TString action, VarType type=kNON);
    static void printOutOfRangeError   (TString name, TString action, VarType type=kNON);

    void setFltVar(TString name, float          var);
    void setIntVar(TString name, int            var);
    void setStrVar(TString name, TString        var);
    void setTLVVar(TString name, TLorentzVector var);

    const float&          getFltVar(TString name) const;
    const int&            getIntVar(TString name) const;
    const TLorentzVector& getTLVVar(TString name) const;
    const TString&        getStrVar(TString name) const;

    VarType getType(TString name);

    void print();
    void printFltVar(TString name);
    void printIntVar(TString name);
    void printTLVVar(TString name);
    void printStrVar(TString name);

};

#endif
//eof
