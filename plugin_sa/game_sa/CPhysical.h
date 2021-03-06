#pragma once
#include "plbase/PluginBase.h"
#include "CEntity.h"
#include "CColPoint.h"
#include "CVector.h"
#include "CQuaternion.h"
#include "CRealTimeShadow.h"
#include "CRepeatSector.h"
#include "eWeaponType.h"

#pragma pack(push, 4)
class PLUGIN_API CPhysical : public CEntity {
public:
    __int32 field_38;
    unsigned __int32 m_dwLastCollisionTime;
    unsigned __int32 b0x01 : 1;
    unsigned __int32 m_bApplyGravity : 1;
    unsigned __int32 m_bDisableCollisionForce : 1;
    unsigned __int32 m_bCollidable : 1; 
    unsigned __int32 m_bDisableTurnForce : 1;
    unsigned __int32 m_bDisableMoveForce : 1;
    unsigned __int32 m_bInfiniteMass : 1;
    unsigned __int32 m_bDisableZ : 1;
    unsigned __int32 m_bSubmergedInWater : 1;
    unsigned __int32 m_bOnSolidSurface : 1;
    unsigned __int32 m_bBroken : 1;
    unsigned __int32 b0x800 : 1; // ref @ 0x6F5CF0
    unsigned __int32 b0x1000 : 1;
    unsigned __int32 m_bDontApplySpeed : 1;
    unsigned __int32 b0x4000 : 1;
    unsigned __int32 b0x8000 : 1;
    unsigned __int32 b0x10000 : 1;
    unsigned __int32 b0x20000 : 1; // ref @ CPhysical::ProcessCollision
    unsigned __int32 m_bBulletProof : 1;
    unsigned __int32 m_bFireProof : 1;
    unsigned __int32 m_bCollisionProof : 1;
    unsigned __int32 m_bMeeleProof : 1;
    unsigned __int32 m_bInvulnerable : 1;
    unsigned __int32 m_bExplosionProof : 1;
    unsigned __int32 b0x1000000 : 1;
    unsigned __int32 m_bAttachedToEntity : 1;
    unsigned __int32 b0x4000000 : 1;
    unsigned __int32 m_bTouchingWater : 1;
    unsigned __int32 m_bCanBeCollidedWith : 1;
    unsigned __int32 m_bDestroyed : 1;
    unsigned __int32 b0x40000000 : 1;
    unsigned __int32 b0x80000000 : 1;
    CVector          m_vLinearVelocity;
    CVector          m_vAngularVelocity;
    CVector          m_vLinearAcceleration;
    CVector          m_vAngularAcceleration;
    CVector          m_vForce;
    CVector          m_vTorque;
    float            m_fMass;
    float            m_fTurnMass;
    float            m_fVelocityFrequency;
    float            m_fAirResistance;
    float            m_fElasticity;
    float            m_fBuoyancyConstant;
    CVector          m_vCentreOfMass;
    void            *m_pCollisionList;
    void            *m_pMovingList;
    __int8 field_B8;
    unsigned __int8  m_nNumEntitiesCollided;
    unsigned __int8  m_nContactSurface;
    __int8 field_BB;
    CEntity         *m_apCollidedEntities[6];
    __int32 field_D4;
    float            m_fDamageIntensity;
    CEntity         *m_pDamageEntity;
    CVector          m_vLastCollisionImpactVelocity;
    CVector          m_vLastCollisionPosn;
    unsigned __int16 m_wPieceType;
    __int16 field_FA;
    class CPhysical *m_pAttachedTo;
    CVector          m_vAttachOffset;
    CVector          m_vAttachedEntityPosn;
    CQuaternion      m_qAttachedEntityRotation;
    CEntity         *m_pEntityIgnoredCollision;
    float            m_fContactSurfaceBrightness;
    __int32 field_130;
    CRealTimeShadow *m_pShadowData;
    
    // originally virtual functions
    void ProcessEntityCollision(CEntity *entity, CColPoint *point);
    
    // functions
    void RemoveAndAdd();
    void AddToMovingList();
    void RemoveFromMovingList();
    void SetDamagedPieceRecord(float damageIntensity, CEntity* damagingEntity, CColPoint& colPoint, float distanceMult);
    void ApplyMoveForce(CVector force);
    void ApplyTurnForce(CVector dir, CVector velocity);
    void ApplyForce(CVector dir, CVector velocity, bool flag);
    CVector GetSpeed(CVector direction);
    void ApplyMoveSpeed();
    void ApplyTurnSpeed();
    void ApplyGravity();
    void ApplyFrictionMoveForce(CVector moveForce);
    void ApplyFrictionTurnForce(CVector posn, CVector velocity);
    void ApplyFrictionForce(CVector posn, CVector velocity);
    void SkipPhysics();
    void AddCollisionRecord(CEntity* collidedEntity);
    bool GetHasCollidedWith(CEntity* entity);
    bool GetHasCollidedWithAnyObject();
    bool ApplyCollision(CEntity* entity, CColPoint& colPoint, float& arg2);
    bool ApplySoftCollision(CEntity* entity, CColPoint& colPoint, float& arg2);
    bool ApplySpringCollision(float arg0, CVector& arg1, CVector& arg2, float arg3, float arg4, float& arg5);
    bool ApplySpringCollisionAlt(float arg0, CVector& arg1, CVector& arg2, float arg3, float arg4, CVector& arg5, float& arg6);
    bool ApplySpringDampening(float arg0, float arg1, CVector& arg2, CVector& arg3, CVector& arg4);
    bool ApplySpringDampeningOld(float arg0, float arg1, CVector& arg2, CVector& arg3, CVector& arg4);
    void RemoveRefsToEntity(CEntity* entity);
    void DettachEntityFromEntity(float x, float y, float z, bool useCollision);
    void DettachAutoAttachedEntity();
    float GetLightingFromCol(bool flag);
    float GetLightingTotal();
    bool CanPhysicalBeDamaged(eWeaponType weapon, unsigned char* arg1);
    void ApplyAirResistance();
    bool ApplyCollisionAlt(CEntity* entity, CColPoint& colPoint, float& arg2, CVector& arg3, CVector& arg4);
    bool ApplyFriction(float arg0, CColPoint& colPoint);
    bool ApplyFriction(CPhysical* physical, float arg1, CColPoint& colPoint);
    bool ProcessShiftSectorList(int sectorX, int sectorY);
    static void PlacePhysicalRelativeToOtherPhysical(CPhysical* physical1, CPhysical* physical2, CVector offset);
    float ApplyScriptCollision(CVector arg0, float arg1, float arg2, CVector* arg3);
    void PositionAttachedEntity();
    void ApplySpeed();
    void UnsetIsInSafePosition();
    void ApplyFriction();
    bool ApplyCollision(CPhysical* physical, CColPoint& colPoint, float& arg2, float& arg3);
    bool ApplySoftCollision(CPhysical* physical, CColPoint& colPoint, float& arg2, float& arg3);
    bool ProcessCollisionSectorList(int sectorX, int sectorY);
    bool ProcessCollisionSectorList_SimpleCar(CRepeatSector* sector);
    void AttachEntityToEntity(CEntity* entity, CVector offset, CVector rotation);
    void AttachEntityToEntity(CEntity* entity, CVector* , RtQuat* rotation);
    bool CheckCollision();
    bool CheckCollision_SimpleCar();
};
#pragma pack(pop)

VALIDATE_SIZE(CPhysical, 0x138);