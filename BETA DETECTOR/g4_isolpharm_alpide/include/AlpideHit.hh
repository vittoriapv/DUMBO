
#ifndef AlpideHit_h
#define AlpideHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4TouchableHandle.hh"
#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"

#include "DetectorConstruction.hh"

class AlpideHit : public G4VHit
{
  public:
    AlpideHit();
    AlpideHit(const AlpideHit&);
    virtual ~AlpideHit();

    // Operators
    const AlpideHit& operator=(const AlpideHit&);
    G4int operator==(const AlpideHit&) const;

    inline void* operator new(size_t);
    inline void  operator delete(void*);

    void SetTrackEnergy    (G4double en)      { fEnergy = en; }

    // This is used to get the correct pixel position
    void SetPosition(G4Step *aStep);

    // Get different physical quantities
    G4double GetTrackEnergy() const       { return fEnergy; }
    G4double GetDepositedEnergy() const       { return fDepositedEnergy; }
    G4double GetDepositedEnergyPixel0() const       { return fDepositedEnergyPixel0; }

    // For the hit pixel position.
    G4double GetHitPixelxPosition() const       { return fxPosition; }
    G4double GetHitPixelzPosition() const       { return fzPosition; }



  private:

      G4double fEnergy;
      G4double fDepositedEnergy;
      G4double fDepositedEnergyPixel0;
      G4double firstPixelCopyNumber = -1.;

      // Hit pixel position.
      G4double fxPosition;
      G4double fzPosition;

};

// Definition of a HitColletion
typedef G4THitsCollection<AlpideHit> AlpideHitsCollection;

// Definition of the Allocator
extern G4ThreadLocal G4Allocator<AlpideHit>* AlpideHitAllocator;


inline void* AlpideHit::operator new(size_t)
{
  if(!AlpideHitAllocator)
      AlpideHitAllocator = new G4Allocator<AlpideHit>;
  return (void *) AlpideHitAllocator->MallocSingle();
}

inline void AlpideHit::operator delete(void *hit)
{
  AlpideHitAllocator->FreeSingle((AlpideHit*) hit);
}

#endif //AlpideHit_h
