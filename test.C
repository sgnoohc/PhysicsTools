#include "TSystem.h"
#include "Particle.h"

void test()
{

  // Load the library for testing
  gSystem->Load("Particle.so");

  // Create an instance for testing
  Particle particle;

  // Create some variables for testing
  particle.createTLVVar("p4"      , "particle's 4-vector");
  particle.createIntVar("pdgId"   , "particle's pdgId");
  particle.createFltVar("relIso03", "relative isolation (sum Pt of junk around dR = 0.3 / lepton pt)");
  particle.createStrVar("label"   , "particle's label");

  // Set some values
  particle.setFltVar("relIso03" , 0.125);
  particle.setIntVar("pdgId"    , -13);
  particle.setStrVar("label"    , "my awesome muon");
  TLorentzVector p4;
  p4.SetPtEtaPhiM(32.5, 0.5, -0.2, 0.105);
  particle.setTLVVar("p4", p4);

  // Get the values
  std::cout << "I set them to   \"my awesome muon\"    and retrieved = \"" << particle.getStrVar("label")    << "\"" << std::endl;
  std::cout << "I set them to   0.125                and retrieved = "     << particle.getFltVar("relIso03") << std::endl;
  std::cout << "I set them to   -13                  and retrieved = "     << particle.getIntVar("pdgId")    << std::endl;
  std::cout << "I set them to   32.5                 and retrieved = "     << particle.getTLVVar("p4").Pt()  << std::endl;
  std::cout << "I set them to    0.5                 and retrieved = "     << particle.getTLVVar("p4").Eta() << std::endl;
  std::cout << "I set them to   -0.2                 and retrieved = "     << particle.getTLVVar("p4").Phi() << std::endl;
  std::cout << "I set them to    0.105               and retrieved = "     << particle.getTLVVar("p4").M()   << std::endl;

  // Print object
  std::cout << "Printing object" << std::endl;
  particle.print();

  // Error handling tests
  // Test out-of-range
//	  particle.getTLVVar("p4_that_doesn't_exist");

  // Test creatng a variable that already exists
//	  particle.createTLVVar("p4");
}
