// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "Particle.h"

//__________________________________________________________________________________________________
Particle::Particle()
{
}

//__________________________________________________________________________________________________
Particle::~Particle()
{
}

//__________________________________________________________________________________________________
bool Particle::varExists(TString name)
{
  if (std::find(var_Nam.begin(), var_Nam.end(), name) != var_Nam.end())
    return true;
  return false;
}

//__________________________________________________________________________________________________
void Particle::createFltVar(TString name, TString title)
{
  if (varExists(name)) printAlreadyExistsError(name, __FUNCTION__, kFLT);
  var_Nam.push_back(name);
  var_Ttl[name] = title;
  var_Typ[name] = kFLT;
  var_Flt[name] = -999;
}

//__________________________________________________________________________________________________
void Particle::createIntVar(TString name, TString title)
{
  if (varExists(name)) printAlreadyExistsError(name, __FUNCTION__, kINT);
  var_Nam.push_back(name);
  var_Ttl[name] = title;
  var_Typ[name] = kINT;
  var_Int[name] = -999;
}

//__________________________________________________________________________________________________
void Particle::createTLVVar(TString name, TString title)
{
  if (varExists(name)) printAlreadyExistsError(name, __FUNCTION__, kTLV);
  var_Nam.push_back(name);
  var_Ttl[name] = title;
  var_Typ[name] = kTLV;
  var_TLV[name].SetXYZT(0, 0, 0, 0);
}

//__________________________________________________________________________________________________
void Particle::createStrVar(TString name, TString title)
{
  if (varExists(name)) printAlreadyExistsError(name, __FUNCTION__, kSTR);
  var_Nam.push_back(name);
  var_Ttl[name] = title;
  var_Typ[name] = kSTR;
  var_Str[name] = "";
}

//__________________________________________________________________________________________________
void Particle::printError(TString name, TString msg, TString action, VarType type)
{
  std::cerr << "ERROR - " << msg.Data() << ", ";
  std::cerr << "name = " << name.Data() << ", ";
  std::cerr << "what was tried = " << action.Data() << ", ";
  switch (type)
  {
    case kINT: std::cerr << "type = int"            << " "; break;
    case kFLT: std::cerr << "type = float"          << " "; break;
    case kTLV: std::cerr << "type = TLorentzVector" << " "; break;
    case kSTR: std::cerr << "type = TString"        << " "; break;
    default: break;
  }
  std::cerr << std::endl;
}

//__________________________________________________________________________________________________
void Particle::printAlreadyExistsError(TString name, TString action, VarType type)
{
  printError(name, "already exists!", action, type);
}

//__________________________________________________________________________________________________
void Particle::printOutOfRangeError(TString name, TString action, VarType type)
{
  printError(name, "out-of-range error", action, type);
}

//__________________________________________________________________________________________________
void Particle::setFltVar(TString name, float var)
{
  try { var_Flt.at(name) = var; }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kFLT); exit(1); }
}

//__________________________________________________________________________________________________
void Particle::setIntVar(TString name, int var)
{
  try { var_Int.at(name) = var; }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kINT); exit(1); }
}

//__________________________________________________________________________________________________
void Particle::setStrVar(TString name, TString var)
{
  try { var_Str.at(name) = var; }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kSTR); exit(1); }
}

//__________________________________________________________________________________________________
void Particle::setTLVVar(TString name, TLorentzVector var)
{
  try { var_TLV.at(name) = var; }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kTLV); exit(1); }
}

//__________________________________________________________________________________________________
const float& Particle::getFltVar(TString name) const
{
  try { return var_Flt.at(name); }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kFLT); exit(2); }
}

//__________________________________________________________________________________________________
const int& Particle::getIntVar(TString name) const
{
  try { return var_Int.at(name); }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kINT); exit(2); }
}

//__________________________________________________________________________________________________
const TLorentzVector& Particle::getTLVVar(TString name) const
{
  try { return var_TLV.at(name); }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kTLV); exit(2); }
}

//__________________________________________________________________________________________________
const TString& Particle::getStrVar(TString name) const
{
  try { return var_Str.at(name); }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kSTR); exit(2); }
}

//__________________________________________________________________________________________________
Particle::VarType Particle::getType(TString name)
{
  try { return var_Typ.at(name); }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__); exit(4); }
}

//__________________________________________________________________________________________________
void Particle::print()
{
  for (auto& name : var_Nam)
  {
    switch (getType(name))
    {
      case kFLT: printFltVar(name); break;
      case kINT: printIntVar(name); break;
      case kTLV: printTLVVar(name); break;
      case kSTR: printStrVar(name); break;
      case kNON: printOutOfRangeError(name, __FUNCTION__); exit(5); break;
    }
  }
}

//__________________________________________________________________________________________________
void Particle::printFltVar(TString name)
{
  try { std::cout << name.Data() << " kFLT " << " " << var_Flt.at(name) << std::endl; }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kFLT); exit(3); }
}

//__________________________________________________________________________________________________
void Particle::printIntVar(TString name)
{
  try { std::cout << name.Data() << " kINT " << " " << var_Int.at(name) << std::endl; }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kINT); exit(3); }
}

//__________________________________________________________________________________________________
void Particle::printTLVVar(TString name)
{
  try {
    std::cout << name.Data() << " kTLV ";
    std::cout << var_TLV.at(name).Pt () << " ";
    std::cout << var_TLV.at(name).Eta() << " ";
    std::cout << var_TLV.at(name).Phi() << " ";
    std::cout << var_TLV.at(name).M  () << " ";
    std::cout << std::endl;
  }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kTLV); exit(3); }
}

//__________________________________________________________________________________________________
void Particle::printStrVar(TString name)
{
  try { std::cout << name.Data() << " kSTR " << " " << var_Str.at(name) << std::endl; }
  catch (const std::out_of_range& oor) { printOutOfRangeError(name, __FUNCTION__, kSTR); exit(3); }
}

//eof
