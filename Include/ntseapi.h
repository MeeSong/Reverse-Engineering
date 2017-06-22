#pragma once
#include "ntbase.h"

//////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Universal well-known SIDs                                               //
//                                                                         //
//     Null SID                     S-1-0-0                                //
//     World                        S-1-1-0                                //
//     Local                        S-1-2-0                                //
//     Creator Owner ID             S-1-3-0                                //
//     Creator Group ID             S-1-3-1                                //
//     Creator Owner Server ID      S-1-3-2                                //
//     Creator Group Server ID      S-1-3-3                                //
//                                                                         //
//     (Non-unique IDs)             S-1-4                                  //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#define SECURITY_NULL_SID_AUTHORITY         {0,0,0,0,0,0}
#define SECURITY_WORLD_SID_AUTHORITY        {0,0,0,0,0,1}
#define SECURITY_LOCAL_SID_AUTHORITY        {0,0,0,0,0,2}
#define SECURITY_CREATOR_SID_AUTHORITY      {0,0,0,0,0,3}
#define SECURITY_NON_UNIQUE_AUTHORITY       {0,0,0,0,0,4}
#define SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

enum UNIVERSAL_SECURITY_RID : UINT32
{
    SECURITY_NULL_RID = 0x00000000L,
    SECURITY_WORLD_RID = 0x00000000L,
    SECURITY_LOCAL_RID = 0x00000000L,
    SECURITY_LOCAL_LOGON_RID = 0x00000001L,

    SECURITY_CREATOR_OWNER_RID = 0x00000000L,
    SECURITY_CREATOR_GROUP_RID = 0x00000001L,

    SECURITY_CREATOR_OWNER_SERVER_RID = 0x00000002L,
    SECURITY_CREATOR_GROUP_SERVER_RID = 0x00000003L,

    SECURITY_CREATOR_OWNER_RIGHTS_RID = 0x00000004L,
};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// NT well-known SIDs                                                        //
//                                                                           //
//     NT Authority            S-1-5                                         //
//     Dialup                  S-1-5-1                                       //
//                                                                           //
//     Network                 S-1-5-2                                       //
//     Batch                   S-1-5-3                                       //
//     Interactive             S-1-5-4                                       //
//     (Logon IDs)             S-1-5-5-X-Y                                   //
//     Service                 S-1-5-6                                       //
//     AnonymousLogon          S-1-5-7       (aka null logon session)        //
//     Proxy                   S-1-5-8                                       //
//     Enterprise DC (EDC)     S-1-5-9       (aka domain controller account) //
//     Self                    S-1-5-10      (self RID)                      //
//     Authenticated User      S-1-5-11      (Authenticated user somewhere)  //
//     Restricted Code         S-1-5-12      (Running restricted code)       //
//     Terminal Server         S-1-5-13      (Running on Terminal Server)    //
//     Remote Logon            S-1-5-14      (Remote Interactive Logon)      //
//     This Organization       S-1-5-15                                      //
//                                                                           //
//     IUser                   S-1-5-17
//     Local System            S-1-5-18                                      //
//     Local Service           S-1-5-19                                      //
//     Network Service         S-1-5-20                                      //
//                                                                           //
//     (NT non-unique IDs)     S-1-5-0x15-... (NT Domain Sids)               //
//                                                                           //
//     (Built-in domain)       S-1-5-0x20                                    //
//                                                                           //
//     (Security Package IDs)  S-1-5-0x40                                    //
//     NTLM Authentication     S-1-5-0x40-10                                 //
//     SChannel Authentication S-1-5-0x40-14                                 //
//     Digest Authentication   S-1-5-0x40-21                                 //
//                                                                           //
//     Other Organization      S-1-5-1000    (>=1000 can not be filtered)    //
//                                                                           //
//                                                                           //
// NOTE: the relative identifier values (RIDs) determine which security      //
//       boundaries the SID is allowed to cross.  Before adding new RIDs,    //
//       a determination needs to be made regarding which range they should  //
//       be added to in order to ensure proper "SID filtering"               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#define SECURITY_NT_AUTHORITY               {0,0,0,0,0,5}   // ntifs

enum NT_SECURITY_RID : UINT32
{
    SECURITY_DIALUP_RID = 0x00000001L,
    SECURITY_NETWORK_RID = 0x00000002L,
    SECURITY_BATCH_RID = 0x00000003L,
    SECURITY_INTERACTIVE_RID = 0x00000004L,
    SECURITY_LOGON_IDS_RID = 0x00000005L,
    SECURITY_LOGON_IDS_RID_COUNT = 3L,
    SECURITY_SERVICE_RID = 0x00000006L,
    SECURITY_ANONYMOUS_LOGON_RID = 0x00000007L,
    SECURITY_PROXY_RID = 0x00000008L,
    SECURITY_ENTERPRISE_CONTROLLERS_RID = 0x00000009L,
    SECURITY_SERVER_LOGON_RID = SECURITY_ENTERPRISE_CONTROLLERS_RID,
    SECURITY_PRINCIPAL_SELF_RID = 0x0000000AL,
    SECURITY_AUTHENTICATED_USER_RID = 0x0000000BL,
    SECURITY_RESTRICTED_CODE_RID = 0x0000000CL,
    SECURITY_TERMINAL_SERVER_RID = 0x0000000DL,
    SECURITY_REMOTE_LOGON_RID = 0x0000000EL,
    SECURITY_THIS_ORGANIZATION_RID = 0x0000000FL,
    SECURITY_IUSER_RID = 0x00000011L,
    SECURITY_LOCAL_SYSTEM_RID = 0x00000012L,
    SECURITY_LOCAL_SERVICE_RID = 0x00000013L,
    SECURITY_NETWORK_SERVICE_RID = 0x00000014L,

    SECURITY_NT_NON_UNIQUE = 0x00000015L,
    SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT = 3L,

    SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID = 0x00000016L,

    SECURITY_BUILTIN_DOMAIN_RID = 0x00000020L,
    SECURITY_WRITE_RESTRICTED_CODE_RID = 0x00000021L,


    SECURITY_PACKAGE_BASE_RID = 0x00000040L,
    SECURITY_PACKAGE_RID_COUNT = 2L,
    SECURITY_PACKAGE_NTLM_RID = 0x0000000AL,
    SECURITY_PACKAGE_SCHANNEL_RID = 0x0000000EL,
    SECURITY_PACKAGE_DIGEST_RID = 0x00000015L,

    SECURITY_CRED_TYPE_BASE_RID = 0x00000041L,
    SECURITY_CRED_TYPE_RID_COUNT = 2L,
    SECURITY_CRED_TYPE_THIS_ORG_CERT_RID = 0x00000001L,

    SECURITY_MIN_BASE_RID = 0x00000050L,

    SECURITY_SERVICE_ID_BASE_RID = 0x00000050L,
    SECURITY_SERVICE_ID_RID_COUNT = 6L,

    SECURITY_RESERVED_ID_BASE_RID = 0x00000051L,

    SECURITY_APPPOOL_ID_BASE_RID = 0x00000052L,
    SECURITY_APPPOOL_ID_RID_COUNT = 6L,

    SECURITY_VIRTUALSERVER_ID_BASE_RID = 0x00000053L,
    SECURITY_VIRTUALSERVER_ID_RID_COUNT = 6L,

    SECURITY_USERMODEDRIVERHOST_ID_BASE_RID = 0x00000054L,
    SECURITY_USERMODEDRIVERHOST_ID_RID_COUNT = 6L,

    SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_BASE_RID = 0x00000055L,
    SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_RID_COUNT = 6L,

    SECURITY_WMIHOST_ID_BASE_RID = 0x00000056L,
    SECURITY_WMIHOST_ID_RID_COUNT = 6L,

    SECURITY_TASK_ID_BASE_RID = 0x00000057L,

    SECURITY_NFS_ID_BASE_RID = 0x00000058L,

    SECURITY_COM_ID_BASE_RID = 0x00000059L,

    SECURITY_WINDOW_MANAGER_BASE_RID = 0x0000005AL,

    SECURITY_RDV_GFX_BASE_RID = 0x0000005BL,

    SECURITY_DASHOST_ID_BASE_RID = 0x0000005CL,
    SECURITY_DASHOST_ID_RID_COUNT = 6L,

    SECURITY_USERMANAGER_ID_BASE_RID = 0x0000005DL,
    SECURITY_USERMANAGER_ID_RID_COUNT = 6L,

    SECURITY_WINRM_ID_BASE_RID = 0x0000005EL,
    SECURITY_WINRM_ID_RID_COUNT = 6L,

    SECURITY_CCG_ID_BASE_RID = 0x0000005FL,

    SECURITY_VIRTUALACCOUNT_ID_RID_COUNT = 6L,

    SECURITY_MAX_BASE_RID = 0x0000006FL,
    SECURITY_MAX_ALWAYS_FILTERED = 0x000003E7L,
    SECURITY_MIN_NEVER_FILTERED = 0x000003E8L,

    SECURITY_OTHER_ORGANIZATION_RID = 0x000003E8L,

    //
    //Service SID type RIDs are in the range 0x50- 0x6F.  Therefore, we are giving  the next available RID to Windows Mobile team.
    //
    SECURITY_WINDOWSMOBILE_ID_BASE_RID = 0x00000070L,

    //
    // Installer Capability Group Sid related. Currently Base RID is same as LOCAL DOMAIN.
    //
    SECURITY_INSTALLER_GROUP_CAPABILITY_BASE = 0x20,
    SECURITY_INSTALLER_GROUP_CAPABILITY_RID_COUNT = 9,

    // Note: This is because the App Capability Rid is S-1-15-3-1024-...
    //       whereas the service group rid is          S-1-5-32-...
    //	The number of RIDs from hash (8) are the same for both
    SECURITY_INSTALLER_CAPABILITY_RID_COUNT = 10,

    //
    //Well-known group for local accounts
    //
    SECURITY_LOCAL_ACCOUNT_RID = 0x00000071L,
    SECURITY_LOCAL_ACCOUNT_AND_ADMIN_RID = 0x00000072L,

};

enum DOMAIN_USER_RID : UINT32
{
    DOMAIN_USER_RID_ADMIN = 0x000001F4L,
    DOMAIN_USER_RID_GUEST = 0x000001F5L,
    DOMAIN_USER_RID_KRBTGT = 0x000001F6L,
    DOMAIN_USER_RID_DEFAULT_ACCOUNT = 0x000001F7L,

    DOMAIN_USER_RID_MAX = 0x000003E7L,
};

enum DOMAIN_GROUP_RID : UINT32
{
    DOMAIN_GROUP_RID_AUTHORIZATION_DATA_IS_COMPOUNDED = 0x000001F0L,
    DOMAIN_GROUP_RID_AUTHORIZATION_DATA_CONTAINS_CLAIMS = 0x000001F1L,
    DOMAIN_GROUP_RID_ENTERPRISE_READONLY_DOMAIN_CONTROLLERS = 0x000001F2L,

    DOMAIN_GROUP_RID_ADMINS = 0x00000200L,
    DOMAIN_GROUP_RID_USERS = 0x00000201L,
    DOMAIN_GROUP_RID_GUESTS = 0x00000202L,
    DOMAIN_GROUP_RID_COMPUTERS = 0x00000203L,
    DOMAIN_GROUP_RID_CONTROLLERS = 0x00000204L,
    DOMAIN_GROUP_RID_CERT_ADMINS = 0x00000205L,
    DOMAIN_GROUP_RID_SCHEMA_ADMINS = 0x00000206L,
    DOMAIN_GROUP_RID_ENTERPRISE_ADMINS = 0x00000207L,
    DOMAIN_GROUP_RID_POLICY_ADMINS = 0x00000208L,
    DOMAIN_GROUP_RID_READONLY_CONTROLLERS = 0x00000209L,
    DOMAIN_GROUP_RID_CLONEABLE_CONTROLLERS = 0x0000020AL,
    DOMAIN_GROUP_RID_CDC_RESERVED = 0x0000020CL,
    DOMAIN_GROUP_RID_PROTECTED_USERS = 0x0000020DL,
    DOMAIN_GROUP_RID_KEY_ADMINS = 0x0000020EL,
    DOMAIN_GROUP_RID_ENTERPRISE_KEY_ADMINS = 0x0000020FL,
};

enum DOMAIN_ALIAS_RID : UINT32
{
    DOMAIN_ALIAS_RID_ADMINS = 0x00000220L,
    DOMAIN_ALIAS_RID_USERS = 0x00000221L,
    DOMAIN_ALIAS_RID_GUESTS = 0x00000222L,
    DOMAIN_ALIAS_RID_POWER_USERS = 0x00000223L,

    DOMAIN_ALIAS_RID_ACCOUNT_OPS = 0x00000224L,
    DOMAIN_ALIAS_RID_SYSTEM_OPS = 0x00000225L,
    DOMAIN_ALIAS_RID_PRINT_OPS = 0x00000226L,
    DOMAIN_ALIAS_RID_BACKUP_OPS = 0x00000227L,

    DOMAIN_ALIAS_RID_REPLICATOR = 0x00000228L,
    DOMAIN_ALIAS_RID_RAS_SERVERS = 0x00000229L,
    DOMAIN_ALIAS_RID_PREW2KCOMPACCESS = 0x0000022AL,
    DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS = 0x0000022BL,
    DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS = 0x0000022CL,
    DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS = 0x0000022DL,

    DOMAIN_ALIAS_RID_MONITORING_USERS = 0x0000022EL,
    DOMAIN_ALIAS_RID_LOGGING_USERS = 0x0000022FL,
    DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS = 0x00000230L,
    DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS = 0x00000231L,
    DOMAIN_ALIAS_RID_DCOM_USERS = 0x00000232L,
    DOMAIN_ALIAS_RID_IUSERS = 0x00000238L,
    DOMAIN_ALIAS_RID_CRYPTO_OPERATORS = 0x00000239L,
    DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP = 0x0000023BL,
    DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP = 0x0000023CL,
    DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP = 0x0000023DL,
    DOMAIN_ALIAS_RID_CERTSVC_DCOM_ACCESS_GROUP = 0x0000023EL,
    DOMAIN_ALIAS_RID_RDS_REMOTE_ACCESS_SERVERS = 0x0000023FL,
    DOMAIN_ALIAS_RID_RDS_ENDPOINT_SERVERS = 0x00000240L,
    DOMAIN_ALIAS_RID_RDS_MANAGEMENT_SERVERS = 0x00000241L,
    DOMAIN_ALIAS_RID_HYPER_V_ADMINS = 0x00000242L,
    DOMAIN_ALIAS_RID_ACCESS_CONTROL_ASSISTANCE_OPS = 0x00000243L,
    DOMAIN_ALIAS_RID_REMOTE_MANAGEMENT_USERS = 0x00000244L,
    DOMAIN_ALIAS_RID_DEFAULT_ACCOUNT = 0x00000245L,
    DOMAIN_ALIAS_RID_STORAGE_REPLICA_ADMINS = 0x00000246L,
};

//
// Application Package Authority.
// 

#define SECURITY_APP_PACKAGE_AUTHORITY      {0,0,0,0,0,15}

enum APP_PACKAGE_SECURITY_RID : UINT32
{
    SECURITY_APP_PACKAGE_BASE_RID = (0x00000002L),
    SECURITY_BUILTIN_APP_PACKAGE_RID_COUNT = (2L),
    SECURITY_APP_PACKAGE_RID_COUNT = (8L),
    SECURITY_CAPABILITY_BASE_RID = (0x00000003L),
    SECURITY_CAPABILITY_APP_RID = (0x000000400),
    SECURITY_BUILTIN_CAPABILITY_RID_COUNT = (2L),
    SECURITY_CAPABILITY_RID_COUNT = (5L),
    SECURITY_PARENT_PACKAGE_RID_COUNT = (SECURITY_APP_PACKAGE_RID_COUNT),
    SECURITY_CHILD_PACKAGE_RID_COUNT = (12L),

    //
    // Built-in Packages.
    //

    SECURITY_BUILTIN_PACKAGE_ANY_PACKAGE        = (0x00000001L),
    SECURITY_BUILTIN_PACKAGE_ANY_RESTRICTED_PACKAGE = (0x00000002L),

    //
    // Built-in Capabilities.
    //

    SECURITY_CAPABILITY_INTERNET_CLIENT = (0x00000001L),
    SECURITY_CAPABILITY_INTERNET_CLIENT_SERVER = (0x00000002L),
    SECURITY_CAPABILITY_PRIVATE_NETWORK_CLIENT_SERVER = (0x00000003L),
    SECURITY_CAPABILITY_PICTURES_LIBRARY = (0x00000004L),
    SECURITY_CAPABILITY_VIDEOS_LIBRARY = (0x00000005L),
    SECURITY_CAPABILITY_MUSIC_LIBRARY = (0x00000006L),
    SECURITY_CAPABILITY_DOCUMENTS_LIBRARY = (0x00000007L),
    SECURITY_CAPABILITY_ENTERPRISE_AUTHENTICATION = (0x00000008L),
    SECURITY_CAPABILITY_SHARED_USER_CERTIFICATES = (0x00000009L),
    SECURITY_CAPABILITY_REMOVABLE_STORAGE = (0x0000000AL),
    SECURITY_CAPABILITY_APPOINTMENTS = (0x0000000BL),
    SECURITY_CAPABILITY_CONTACTS = (0x0000000CL),

    SECURITY_CAPABILITY_INTERNET_EXPLORER = (0x00001000L),
};

//
// Mandatory Label Authority.
//

#define SECURITY_MANDATORY_LABEL_AUTHORITY  {0,0,0,0,0,16}

typedef enum _MANDATORY_LEVEL {
    MandatoryLevelUntrusted = 0,
    MandatoryLevelLow,
    MandatoryLevelMedium,
    MandatoryLevelHigh,
    MandatoryLevelSystem,
    MandatoryLevelSecureProcess,
    MandatoryLevelCount
} MANDATORY_LEVEL, *PMANDATORY_LEVEL;

enum MANDATORY_LEVEL_SECURITY_RID : UINT32
{
    SECURITY_MANDATORY_UNTRUSTED_RID = (0x00000000L),
    SECURITY_MANDATORY_LOW_RID = (0x00001000L),
    SECURITY_MANDATORY_MEDIUM_RID = (0x00002000L),
    SECURITY_MANDATORY_MEDIUM_PLUS_RID = (SECURITY_MANDATORY_MEDIUM_RID + 0x100),
    SECURITY_MANDATORY_HIGH_RID = (0x00003000L),
    SECURITY_MANDATORY_SYSTEM_RID = (0x00004000L),
    SECURITY_MANDATORY_PROTECTED_PROCESS_RID = (0x00005000L),

    //
    // SECURITY_MANDATORY_MAXIMUM_USER_RID is the highest RID that
    // can be set by a usermode caller.
    //

    SECURITY_MANDATORY_MAXIMUM_USER_RID = SECURITY_MANDATORY_SYSTEM_RID,

};

#define MANDATORY_LEVEL_TO_MANDATORY_RID(IL) (IL * 0x1000)

//
// 
//

#define SECURITY_SCOPED_POLICY_ID_AUTHORITY {0,0,0,0,0,17}

//
// Authentication Authority
//

#define SECURITY_AUTHENTICATION_AUTHORITY   {0,0,0,0,0,18}
#define SECURITY_AUTHENTICATION_AUTHORITY_RID_COUNT (1L)

enum AUTHENTICATION_SECURITY_RID : UINT32
{
    SECURITY_AUTHENTICATION_AUTHORITY_ASSERTED_RID = (0x00000001L),
    SECURITY_AUTHENTICATION_SERVICE_ASSERTED_RID = (0x00000002L),
    SECURITY_AUTHENTICATION_FRESH_KEY_AUTH_RID = (0x00000003L),
    SECURITY_AUTHENTICATION_KEY_TRUST_RID = (0x00000004L),
    SECURITY_AUTHENTICATION_KEY_PROPERTY_MFA_RID = (0x00000005L),
    SECURITY_AUTHENTICATION_KEY_PROPERTY_ATTESTATION_RID = (0x00000006L),
};

//
//Process Trust Authority
//

#define SECURITY_PROCESS_TRUST_AUTHORITY    {0,0,0,0,0,19}
#define SECURITY_PROCESS_TRUST_AUTHORITY_RID_COUNT (2L)

enum TRUST_SECURITY_RID : UINT32
{
    SECURITY_PROCESS_PROTECTION_TYPE_FULL_RID = (0x00000400L),
    SECURITY_PROCESS_PROTECTION_TYPE_LITE_RID = (0x00000200L),
    SECURITY_PROCESS_PROTECTION_TYPE_NONE_RID = (0x00000000L),

    SECURITY_PROCESS_PROTECTION_LEVEL_WINTCB_RID = (0x00002000L),
    SECURITY_PROCESS_PROTECTION_LEVEL_WINDOWS_RID = (0x00001000L),
    SECURITY_PROCESS_PROTECTION_LEVEL_NONE_RID = (0x00000000L),

    //
    // Trusted Installer RIDs
    //

    SECURITY_TRUSTED_INSTALLER_RID1 = 956008885,
    SECURITY_TRUSTED_INSTALLER_RID2 = 3418522649,
    SECURITY_TRUSTED_INSTALLER_RID3 = 1831038044,
    SECURITY_TRUSTED_INSTALLER_RID4 = 1853292631,
    SECURITY_TRUSTED_INSTALLER_RID5 = 2271478464,
};

//
// Allocate the System Luid.  The first 1000 LUIDs are reserved.
// Use #999 here (0x3e7 = 999)
//

#define SYSTEM_LUID                     { 0x3e7, 0x0 }
#define ANONYMOUS_LOGON_LUID            { 0x3e6, 0x0 }
#define LOCALSERVICE_LUID               { 0x3e5, 0x0 }
#define NETWORKSERVICE_LUID             { 0x3e4, 0x0 }
#define IUSER_LUID                      { 0x3e3, 0x0 }

//
// 
//


typedef struct _SID_IDENTIFIER_AUTHORITY
{
    BYTE  Value[6];
} SID_IDENTIFIER_AUTHORITY, *PSID_IDENTIFIER_AUTHORITY;

#define SID_IDENTIFIER_AUTHORITY_LENGTH  (sizeof(SID_IDENTIFIER_AUTHORITY))

typedef struct _LUID {
    UINT32 LowPart;
    INT32 HighPart;
} LUID, *PLUID;

typedef struct _LUID_AND_ATTRIBUTES {
    LUID Luid;
    UINT32 Attributes;
} LUID_AND_ATTRIBUTES, *PLUID_AND_ATTRIBUTES;

typedef struct _SID
{
    BYTE  Revision;
    BYTE  SubAuthorityCount;
    SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
    UINT32 SubAuthority[ANYSIZE_ARRAY];
} SID, *PSID, *PISID;

typedef struct _SID_AND_ATTRIBUTES {
    PISID Sid;
    UINT32 Attributes;
} SID_AND_ATTRIBUTES, *PSID_AND_ATTRIBUTES;

using SID_HASH_ENTRY = UINT_PTR;


#define SID_REVISION                     (1)    // Current revision level
#define SID_MAX_SUB_AUTHORITIES          (15)
#define SID_RECOMMENDED_SUB_AUTHORITIES  (1)    // Will change to around 6

#define SECURITY_MAX_SID_SIZE  \
      (sizeof(SID) - sizeof(UINT32) + (SID_MAX_SUB_AUTHORITIES * sizeof(UINT32)))

#define SECURITY_SID_SIZE(SubAuthorityCount_) (sizeof(SID) - sizeof(UINT32) + \
                                                (SubAuthorityCount_) * sizeof(UINT32))


typedef struct _SID_AND_ATTRIBUTES_HASH {
    enum : UINT32
    {
        SID_HASH_SIZE = 32,
    };

    UINT32 SidCount;
    PSID_AND_ATTRIBUTES SidAttr;
    SID_HASH_ENTRY Hash[SID_HASH_SIZE];
} SID_AND_ATTRIBUTES_HASH, *PSID_AND_ATTRIBUTES_HASH;

typedef struct _SECURITY_CAPABILITIES {
    PISID AppContainerSid;
    PSID_AND_ATTRIBUTES Capabilities;
    UINT32 CapabilityCount;
    UINT32 Reserved;
} SECURITY_CAPABILITIES, *PSECURITY_CAPABILITIES, *LPSECURITY_CAPABILITIES;

// This is the *current* ACL revision

enum ACL_REVISION_VALUE : BYTE
{
    ACL_REVISION1 = 1,
    ACL_REVISION = 2,
    MIN_ACL_REVISION = ACL_REVISION,
    ACL_REVISION3 = 3,
    ACL_REVISION_DS = 4,
    MAX_ACL_REVISION = ACL_REVISION_DS,
};

typedef struct _ACL {
    BYTE    AclRevision;
    BYTE    Sbz1;
    UINT16  AclSize;
    UINT16  AceCount;
    UINT16  Sbz2;
} ACL, *PACL;

//
// ACE
//


//
//  The structure of an ACE is a common ace header followed by ace type
//  specific data.  Pictorally the structure of the common ace header is
//  as follows:
//
//       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//      +---------------+-------+-------+---------------+---------------+
//      |            AceSize            |    AceFlags   |     AceType   |
//      +---------------+-------+-------+---------------+---------------+
//
//  AceType denotes the type of the ace, there are some predefined ace
//  types
//
//  AceSize is the size, in bytes, of ace.
//
//  AceFlags are the Ace flags for audit and inheritance, defined shortly.

typedef struct _ACE_HEADER {
    UINT8 AceType;
    UINT8 AceFlags;
    UINT16 AceSize;
} ACE_HEADER, *PACE_HEADER;

//
//  The following are the predefined ace types that go into the AceType
//  field of an Ace header.
//

enum ACE_TYPE : UINT8
{
    ACCESS_MIN_MS_ACE_TYPE = (0x0),
    ACCESS_ALLOWED_ACE_TYPE = (0x0),
    ACCESS_DENIED_ACE_TYPE = (0x1),
    SYSTEM_AUDIT_ACE_TYPE = (0x2),
    SYSTEM_ALARM_ACE_TYPE = (0x3),
    ACCESS_MAX_MS_V2_ACE_TYPE = (0x3),

    ACCESS_ALLOWED_COMPOUND_ACE_TYPE = (0x4),
    ACCESS_MAX_MS_V3_ACE_TYPE = (0x4),

    ACCESS_MIN_MS_OBJECT_ACE_TYPE = (0x5),
    ACCESS_ALLOWED_OBJECT_ACE_TYPE = (0x5),
    ACCESS_DENIED_OBJECT_ACE_TYPE = (0x6),
    SYSTEM_AUDIT_OBJECT_ACE_TYPE = (0x7),
    SYSTEM_ALARM_OBJECT_ACE_TYPE = (0x8),
    ACCESS_MAX_MS_OBJECT_ACE_TYPE = (0x8),

    ACCESS_MAX_MS_V4_ACE_TYPE = (0x8),
    ACCESS_MAX_MS_ACE_TYPE = (0x8),

    ACCESS_ALLOWED_CALLBACK_ACE_TYPE = (0x9),
    ACCESS_DENIED_CALLBACK_ACE_TYPE = (0xA),
    ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE = (0xB),
    ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE = (0xC),
    SYSTEM_AUDIT_CALLBACK_ACE_TYPE = (0xD),
    SYSTEM_ALARM_CALLBACK_ACE_TYPE = (0xE),
    SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE = (0xF),
    SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE = (0x10),

    SYSTEM_MANDATORY_LABEL_ACE_TYPE = (0x11),
    SYSTEM_RESOURCE_ATTRIBUTE_ACE_TYPE = (0x12),
    SYSTEM_SCOPED_POLICY_ID_ACE_TYPE = (0x13),
    SYSTEM_PROCESS_TRUST_LABEL_ACE_TYPE = (0x14),
    ACCESS_MAX_MS_V5_ACE_TYPE = (0x14),
};

//
//  The following are the inherit flags that go into the AceFlags field
//  of an Ace header.
//

enum ACE_FLAGS : UINT8
{
    OBJECT_INHERIT_ACE = (0x1),
    CONTAINER_INHERIT_ACE = (0x2),
    NO_PROPAGATE_INHERIT_ACE = (0x4),
    INHERIT_ONLY_ACE = (0x8),
    INHERITED_ACE = (0x10),
    VALID_INHERIT_FLAGS = (0x1F),
};

//  The following are the currently defined ACE flags that go into the
//  AceFlags field of an ACE header.  Each ACE type has its own set of
//  AceFlags.
//
//  SUCCESSFUL_ACCESS_ACE_FLAG - used only with system audit and alarm ACE
//  types to indicate that a message is generated for successful accesses.
//
//  FAILED_ACCESS_ACE_FLAG - used only with system audit and alarm ACE types
//  to indicate that a message is generated for failed accesses.
//

//
//  SYSTEM_AUDIT and SYSTEM_ALARM AceFlags
//
//  These control the signaling of audit and alarms for success or failure.
//

#define SUCCESSFUL_ACCESS_ACE_FLAG       (0x40)
#define FAILED_ACCESS_ACE_FLAG           (0x80)


//
//  We'll define the structure of the predefined ACE types.  Pictorally
//  the structure of the predefined ACE's is as follows:
//
//       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//      +---------------+-------+-------+---------------+---------------+
//      |    AceFlags   | Resd  |Inherit|    AceSize    |     AceType   |
//      +---------------+-------+-------+---------------+---------------+
//      |                              Mask                             |
//      +---------------------------------------------------------------+
//      |                                                               |
//      +                                                               +
//      |                                                               |
//      +                              Sid                              +
//      |                                                               |
//      +                                                               +
//      |                                                               |
//      +---------------------------------------------------------------+
//
//  Mask is the access mask associated with the ACE.  This is either the
//  access allowed, access denied, audit, or alarm mask.
//
//  Sid is the Sid associated with the ACE.
//

//  The following are the four predefined ACE types.

//  Examine the AceType field in the Header to determine
//  which structure is appropriate to use for casting.


typedef struct _ACCESS_ALLOWED_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    UINT32 SidStart;
} ACCESS_ALLOWED_ACE, *PACCESS_ALLOWED_ACE;

typedef struct _ACCESS_DENIED_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    UINT32 SidStart;
} ACCESS_DENIED_ACE, *PACCESS_DENIED_ACE;

typedef struct _SYSTEM_AUDIT_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    UINT32 SidStart;
} SYSTEM_AUDIT_ACE, *PSYSTEM_AUDIT_ACE;

typedef struct _SYSTEM_ALARM_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    UINT32 SidStart;
} SYSTEM_ALARM_ACE, *PSYSTEM_ALARM_ACE;

typedef struct _SYSTEM_RESOURCE_ATTRIBUTE_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    UINT32 SidStart;
    // Sid followed by CLAIM_SECURITY_ATTRIBUTE_RELATIVE_V1 structure
} SYSTEM_RESOURCE_ATTRIBUTE_ACE, *PSYSTEM_RESOURCE_ATTRIBUTE_ACE;

typedef struct _SYSTEM_SCOPED_POLICY_ID_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    UINT32 SidStart;
} SYSTEM_SCOPED_POLICY_ID_ACE, *PSYSTEM_SCOPED_POLICY_ID_ACE;

typedef struct _SYSTEM_MANDATORY_LABEL_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    UINT32 SidStart;
} SYSTEM_MANDATORY_LABEL_ACE, *PSYSTEM_MANDATORY_LABEL_ACE;

typedef struct _SYSTEM_PROCESS_TRUST_LABEL_ACE {
    ACE_HEADER Header;
    ACCESS_MASK Mask;
    UINT32 SidStart;
} SYSTEM_PROCESS_TRUST_LABEL_ACE, *PSYSTEM_PROCESS_TRUST_LABEL_ACE;

enum SYSTEM_MANDATORY_LABEL_POLICY : UINT32
{
    SYSTEM_MANDATORY_LABEL_NO_WRITE_UP  = 0x1,
    SYSTEM_MANDATORY_LABEL_NO_READ_UP   = 0x2,
    SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP = 0x4,

    SYSTEM_MANDATORY_LABEL_VALID_MASK   = 
    (SYSTEM_MANDATORY_LABEL_NO_WRITE_UP
        | SYSTEM_MANDATORY_LABEL_NO_READ_UP
        | SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP),
};

// Placeholder value that allows all ranges
#define SYSTEM_PROCESS_TRUST_LABEL_VALID_MASK      0x00ffffff
#define SYSTEM_PROCESS_TRUST_NOCONSTRAINT_MASK     0xffffffff

enum SECURITY_DESCRIPTOR_CONTROL : UINT16
{
    SE_OWNER_DEFAULTED = 0x0001,
    SE_GROUP_DEFAULTED = 0x0002,
    SE_DACL_PRESENT = 0x0004,
    SE_DACL_DEFAULTED = 0x0008,
    SE_SACL_PRESENT = 0x0010,
    SE_SACL_DEFAULTED = 0x0020,
    SE_DACL_UNTRUSTED = 0x0040,
    SE_SERVER_SECURITY = 0x0080,
    SE_DACL_AUTO_INHERIT_REQ = 0x0100,
    SE_SACL_AUTO_INHERIT_REQ = 0x0200,
    SE_DACL_AUTO_INHERITED = 0x0400,
    SE_SACL_AUTO_INHERITED = 0x0800,
    SE_DACL_PROTECTED = 0x1000,
    SE_SACL_PROTECTED = 0x2000,
    SE_RM_CONTROL_VALID = 0x4000,
    SE_SELF_RELATIVE = 0x8000,
};

enum SECURITY_DESCRIPTOR_REVISION_VALUE : UINT8
{
    SECURITY_DESCRIPTOR_REVISION1 = 1,
    SECURITY_DESCRIPTOR_REVISION = 1,
};

typedef struct _SECURITY_DESCRIPTOR_RELATIVE {
    BYTE  Revision;
    BYTE  Sbz1;
    SECURITY_DESCRIPTOR_CONTROL Control;
    UINT32 Owner;
    UINT32 Group;
    UINT32 Sacl;
    UINT32 Dacl;
} SECURITY_DESCRIPTOR_RELATIVE, *PSECURITY_DESCRIPTOR_RELATIVE, *PISECURITY_DESCRIPTOR_RELATIVE;

typedef struct _SECURITY_DESCRIPTOR {
    BYTE  Revision;
    BYTE  Sbz1;
    SECURITY_DESCRIPTOR_CONTROL Control;
    PSID Owner;
    PSID Group;
    PACL Sacl;
    PACL Dacl;
} SECURITY_DESCRIPTOR, *PSECURITY_DESCRIPTOR, *PISECURITY_DESCRIPTOR;

#define SECURITY_DESCRIPTOR_MIN_LENGTH   (sizeof(SECURITY_DESCRIPTOR))

enum ACCESS_MODE : UINT32
{
    NOT_USED_ACCESS = 0,
    GRANT_ACCESS,
    SET_ACCESS,
    DENY_ACCESS,
    REVOKE_ACCESS,
    SET_AUDIT_SUCCESS,
    SET_AUDIT_FAILURE
};

enum INHERITANCE_FLAGS : UINT32
{
    NO_INHERITANCE = 0x0,
    SUB_OBJECTS_ONLY_INHERIT = 0x1,
    SUB_CONTAINERS_ONLY_INHERIT = 0x2,
    SUB_CONTAINERS_AND_OBJECTS_INHERIT = 0x3,
    INHERIT_NO_PROPAGATE = 0x4,
    INHERIT_ONLY = 0x8,
};

enum MULTIPLE_TRUSTEE_OPERATION : UINT32
{
    NO_MULTIPLE_TRUSTEE,
    TRUSTEE_IS_IMPERSONATE,
};

enum TRUSTEE_FORM : UINT32
{
    TRUSTEE_IS_SID,
    TRUSTEE_IS_NAME,
    TRUSTEE_BAD_FORM,
    TRUSTEE_IS_OBJECTS_AND_SID,
    TRUSTEE_IS_OBJECTS_AND_NAME
};

enum TRUSTEE_TYPE : UINT32
{
    TRUSTEE_IS_UNKNOWN,
    TRUSTEE_IS_USER,
    TRUSTEE_IS_GROUP,
    TRUSTEE_IS_DOMAIN,
    TRUSTEE_IS_ALIAS,
    TRUSTEE_IS_WELL_KNOWN_GROUP,
    TRUSTEE_IS_DELETED,
    TRUSTEE_IS_INVALID,
    TRUSTEE_IS_COMPUTER
};

enum SE_OBJECT_TYPE : UINT32
{
    SE_UNKNOWN_OBJECT_TYPE = 0,
    SE_FILE_OBJECT,
    SE_SERVICE,
    SE_PRINTER,
    SE_REGISTRY_KEY,
    SE_LMSHARE,
    SE_KERNEL_OBJECT,
    SE_WINDOW_OBJECT,
    SE_DS_OBJECT,
    SE_DS_OBJECT_ALL,
    SE_PROVIDER_DEFINED_OBJECT,
    SE_WMIGUID_OBJECT,
    SE_REGISTRY_WOW64_32KEY,
    SE_REGISTRY_WOW64_64KEY,
};

typedef struct  _OBJECTS_AND_SID
{
    UINT32  ObjectsPresent;
    GUID    ObjectTypeGuid;
    GUID    InheritedObjectTypeGuid;
    SID     * pSid;
} OBJECTS_AND_SID, *POBJECTS_AND_SID;

typedef struct  _OBJECTS_AND_NAME_A
{
    UINT32         ObjectsPresent;
    SE_OBJECT_TYPE ObjectType;
    PSTR    ObjectTypeName;
    PSTR    InheritedObjectTypeName;
    PSTR    ptstrName;
} OBJECTS_AND_NAME_A, *POBJECTS_AND_NAME_A;

typedef struct  _OBJECTS_AND_NAME_W
{
    UINT32         ObjectsPresent;
    SE_OBJECT_TYPE ObjectType;
    PWSTR   ObjectTypeName;
    PWSTR   InheritedObjectTypeName;
    PWSTR   ptstrName;
} OBJECTS_AND_NAME_W, *POBJECTS_AND_NAME_W;

typedef struct _TRUSTEEA
{
    struct _TRUSTEEA           *pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION  MultipleTrusteeOperation;
    TRUSTEE_FORM                TrusteeForm;
    TRUSTEE_TYPE                TrusteeType;

    union
    {
        // [case(TRUSTEE_IS_NAME)]
        PSTR                  ptstrName;
        // [case(TRUSTEE_IS_SID)]
        SID                    *pSid;
        // [case(TRUSTEE_IS_OBJECTS_AND_SID)]
        OBJECTS_AND_SID        *pObjectsAndSid;
        // [case(TRUSTEE_IS_OBJECTS_AND_NAME)]
        OBJECTS_AND_NAME_A     *pObjectsAndName;
    } DUMMYUNIONNAME;
}TRUSTEEA, *PTRUSTEEA;

typedef struct _TRUSTEEW
{
    struct _TRUSTEEW           *pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION  MultipleTrusteeOperation;
    TRUSTEE_FORM                TrusteeForm;
    TRUSTEE_TYPE                TrusteeType;

    union
    {
        // [case(TRUSTEE_IS_NAME)]
        PWSTR                  ptstrName;
        // [case(TRUSTEE_IS_SID)]
        SID                    *pSid;
        // [case(TRUSTEE_IS_OBJECTS_AND_SID)]
        OBJECTS_AND_SID        *pObjectsAndSid;
        // [case(TRUSTEE_IS_OBJECTS_AND_NAME)]
        OBJECTS_AND_NAME_W     *pObjectsAndName;
    } DUMMYUNIONNAME;
}TRUSTEEW, *PTRUSTEEW;

typedef struct _EXPLICIT_ACCESSA
{
    UINT32        grfAccessPermissions;
    ACCESS_MODE   grfAccessMode;
    UINT32        grfInheritance;
    TRUSTEEA      Trustee;
}EXPLICIT_ACCESSA, *PEXPLICIT_ACCESSA;

typedef struct _EXPLICIT_ACCESSW
{
    UINT32        grfAccessPermissions;
    ACCESS_MODE   grfAccessMode;
    UINT32        grfInheritance;
    TRUSTEEW      Trustee;
}EXPLICIT_ACCESSW, *PEXPLICIT_ACCESSW;

typedef struct _GENERIC_MAPPING {
    ACCESS_MASK GenericRead;
    ACCESS_MASK GenericWrite;
    ACCESS_MASK GenericExecute;
    ACCESS_MASK GenericAll;
} GENERIC_MAPPING, *PGENERIC_MAPPING;

//
// Token Specific Access Rights.
//

enum TOKEN_ACCESS : UINT32
{
    TOKEN_ASSIGN_PRIMARY = (0x0001),
    TOKEN_DUPLICATE = (0x0002),
    TOKEN_IMPERSONATE = (0x0004),
    TOKEN_QUERY = (0x0008),
    TOKEN_QUERY_SOURCE = (0x0010),
    TOKEN_ADJUST_PRIVILEGES = (0x0020),
    TOKEN_ADJUST_GROUPS = (0x0040),
    TOKEN_ADJUST_DEFAULT = (0x0080),
    TOKEN_ADJUST_SESSIONID = (0x0100),

    TOKEN_ALL_ACCESS_P = 
        (STANDARD_RIGHTS_REQUIRED
            | TOKEN_ASSIGN_PRIMARY
            | TOKEN_DUPLICATE
            | TOKEN_IMPERSONATE
            | TOKEN_QUERY
            | TOKEN_QUERY_SOURCE
            | TOKEN_ADJUST_PRIVILEGES
            | TOKEN_ADJUST_GROUPS
            | TOKEN_ADJUST_DEFAULT),

    TOKEN_ALL_ACCESS = (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID),


    TOKEN_READ = (STANDARD_RIGHTS_READ | TOKEN_QUERY),

    TOKEN_WRITE = 
        (STANDARD_RIGHTS_WRITE
            | TOKEN_ADJUST_PRIVILEGES
            | TOKEN_ADJUST_GROUPS
            | TOKEN_ADJUST_DEFAULT),

    TOKEN_EXECUTE = (STANDARD_RIGHTS_EXECUTE),

    TOKEN_TRUST_CONSTRAINT_MASK = 
        (STANDARD_RIGHTS_READ
            | TOKEN_QUERY
            | TOKEN_QUERY_SOURCE),

    TOKEN_ACCESS_PSEUDO_HANDLE_WIN8 = (TOKEN_QUERY | TOKEN_QUERY_SOURCE),

    TOKEN_ACCESS_PSEUDO_HANDLE = TOKEN_ACCESS_PSEUDO_HANDLE_WIN8,
};

//////////////////////////////////////////////////////////////////////////

enum NT_SECURITY_PRIVILEGES : UINT32
{
    SE_MIN_WELL_KNOWN_PRIVILEGE = 2L,
    SE_CREATE_TOKEN_PRIVILEGE = 2L,
    SE_ASSIGNPRIMARYTOKEN_PRIVILEGE = 3L,
    SE_LOCK_MEMORY_PRIVILEGE = 4L,
    SE_INCREASE_QUOTA_PRIVILEGE = 5L,
    SE_MACHINE_ACCOUNT_PRIVILEGE = 6L,
    SE_TCB_PRIVILEGE = 7L,
    SE_SECURITY_PRIVILEGE = 8L,
    SE_TAKE_OWNERSHIP_PRIVILEGE = 9L,
    SE_LOAD_DRIVER_PRIVILEGE = 10L,
    SE_SYSTEM_PROFILE_PRIVILEGE = 11L,
    SE_SYSTEMTIME_PRIVILEGE = 12L,
    SE_PROF_SINGLE_PROCESS_PRIVILEGE = 13L,
    SE_INC_BASE_PRIORITY_PRIVILEGE = 14L,
    SE_CREATE_PAGEFILE_PRIVILEGE = 15L,
    SE_CREATE_PERMANENT_PRIVILEGE = 16L,
    SE_BACKUP_PRIVILEGE = 17L,
    SE_RESTORE_PRIVILEGE = 18L,
    SE_SHUTDOWN_PRIVILEGE = 19L,
    SE_DEBUG_PRIVILEGE = 20L,
    SE_AUDIT_PRIVILEGE = 21L,
    SE_SYSTEM_ENVIRONMENT_PRIVILEGE = 22L,
    SE_CHANGE_NOTIFY_PRIVILEGE = 23L,
    SE_REMOTE_SHUTDOWN_PRIVILEGE = 24L,
    SE_UNDOCK_PRIVILEGE = 25L,
    SE_SYNC_AGENT_PRIVILEGE = 26L,
    SE_ENABLE_DELEGATION_PRIVILEGE = 27L,
    SE_MANAGE_VOLUME_PRIVILEGE = 28L,
    SE_IMPERSONATE_PRIVILEGE = 29L,
    SE_CREATE_GLOBAL_PRIVILEGE = 30L,
    SE_TRUSTED_CREDMAN_ACCESS_PRIVILEGE = 31L,
    SE_RELABEL_PRIVILEGE = 32L,
    SE_INC_WORKING_SET_PRIVILEGE = 33L,
    SE_TIME_ZONE_PRIVILEGE = 34L,
    SE_CREATE_SYMBOLIC_LINK_PRIVILEGE = 35L,
    SE_DELEGATE_SESSION_USER_IMPERSONATE_PRIVILEGE = 36L,
    SE_MAX_WELL_KNOWN_PRIVILEGE = SE_DELEGATE_SESSION_USER_IMPERSONATE_PRIVILEGE,
};

//
// Token Types
//

enum TOKEN_TYPE : UINT32
{
    TokenPrimary = 1,
    TokenImpersonation
};

//
// Token elevation values describe the relative strength of a given token.
// A full token is a token with all groups and privileges to which the principal
// is authorized.  A limited token is one with some groups or privileges removed.
//

enum TOKEN_ELEVATION_TYPE : UINT32
{
    TokenElevationTypeDefault = 1,
    TokenElevationTypeFull,
    TokenElevationTypeLimited,
};

//////////////////////////////////////////////////////////////////////////

//
//  *** Claim Security attributes ***
//
//      These #defines and data structures (almost) exactly mirror
//      the Token_XXX definitions (except for PWSTR/PUNICODE changes)
//      in ntseapi.w as well as AUTHZ_XXX in authz.w. 
//      Keep them in sync. 
//
//
//  Security attribute data types ...
//

enum TOKEN_SECURITY_ATTRIBUTE_TYPE : UINT16
{
    TOKEN_SECURITY_ATTRIBUTE_TYPE_INVALID = 0x00,
    TOKEN_SECURITY_ATTRIBUTE_TYPE_INT64 = 0x01,
    TOKEN_SECURITY_ATTRIBUTE_TYPE_UINT64 = 0x02,

    //
    //  Case insensitive attribute value string by default.
    //  Unless the flag TOKEN_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE
    //  is set indicating otherwise.
    //

    TOKEN_SECURITY_ATTRIBUTE_TYPE_STRING = 0x03,
    TOKEN_SECURITY_ATTRIBUTE_TYPE_FQBN = 0x04,
    TOKEN_SECURITY_ATTRIBUTE_TYPE_SID = 0x05,
    TOKEN_SECURITY_ATTRIBUTE_TYPE_BOOLEAN = 0x06,
    TOKEN_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING = 0x10,
};

enum TOKEN_SECURITY_ATTRIBUTE_FLAGS : UINT32
{
    //
    //  Attribute must not be inherited across process spawns.
    //

    TOKEN_SECURITY_ATTRIBUTE_NON_INHERITABLE = 0x0001,

    //
    //  Attribute value is compared in a case sensitive way. It is valid with string value
    //  or composite type containing string value. For other types of value, this flag
    //  will be ignored. Currently, it is valid with the two types:
    //  TOKEN_SECURITY_ATTRIBUTE_TYPE_STRING and TOKEN_SECURITY_ATTRIBUTE_TYPE_FQBN.
    //
    TOKEN_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE = 0x0002,

    //
    // Attribute is considered only for Deny Aces.
    //

    TOKEN_SECURITY_ATTRIBUTE_USE_FOR_DENY_ONLY = 0x0004,

    //
    // Attribute is disabled by default.
    //

    TOKEN_SECURITY_ATTRIBUTE_DISABLED_BY_DEFAULT = 0x0008,

    // 
    // Attribute is disabled.
    //

    TOKEN_SECURITY_ATTRIBUTE_DISABLED = 0x0010,

    //
    // Attribute is mandatory.
    //

    TOKEN_SECURITY_ATTRIBUTE_MANDATORY = 0x0020,


    TOKEN_SECURITY_ATTRIBUTE_VALID_FLAGS = (
        TOKEN_SECURITY_ATTRIBUTE_NON_INHERITABLE
        | TOKEN_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE
        | TOKEN_SECURITY_ATTRIBUTE_USE_FOR_DENY_ONLY
        | TOKEN_SECURITY_ATTRIBUTE_DISABLED_BY_DEFAULT
        | TOKEN_SECURITY_ATTRIBUTE_DISABLED
        | TOKEN_SECURITY_ATTRIBUTE_MANDATORY),


    //
    // Reserve upper 16 bits for custom flags. These should be preserved but not
    // validated as they do not affect security in any way.
    //
    TOKEN_SECURITY_ATTRIBUTE_CUSTOM_FLAGS = 0xFFFF0000,
};

typedef struct _TOKEN_SECURITY_ATTRIBUTE_FQBN_VALUE
{
    UINT64 Version;
    UNICODE_STRING Name;
} TOKEN_SECURITY_ATTRIBUTE_FQBN_VALUE, *PTOKEN_SECURITY_ATTRIBUTE_FQBN_VALUE;

typedef struct _TOKEN_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE
{
    void* pValue;
    UINT32 ValueLength;
} TOKEN_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE, *PTOKEN_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE;

//
// TokenSecurityAttributes
// 

typedef struct _TOKEN_SECURITY_ATTRIBUTE_V1
{
    UNICODE_STRING Name;
    UINT16 ValueType;
    UINT16 Reserved;
    UINT32 Flags;
    UINT32 ValueCount;
    union
    {
        INT64* pInt64;
        UINT64* pUint64;

        // 不同于 CLAIM_SECURITY_ATTRIBUTE_V1.ppString
        PUNICODE_STRING pString;

        PTOKEN_SECURITY_ATTRIBUTE_FQBN_VALUE pFqbn;
        PTOKEN_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE pOctetString;
    } Values;
} TOKEN_SECURITY_ATTRIBUTE_V1, *PTOKEN_SECURITY_ATTRIBUTE_V1;

enum TOKEN_SECURITY_ATTRIBUTES_INFORMATION_VERSION_VALUE : UINT16
{
    TOKEN_SECURITY_ATTRIBUTES_INFORMATION_VERSION_V1 = 1,
    TOKEN_SECURITY_ATTRIBUTES_INFORMATION_VERSION = TOKEN_SECURITY_ATTRIBUTES_INFORMATION_VERSION_V1,
};

typedef struct _TOKEN_SECURITY_ATTRIBUTES_INFORMATION
{
    UINT16 Version;
    UINT16 Reserved;
    UINT32 AttributeCount;
    union
    {
        PTOKEN_SECURITY_ATTRIBUTE_V1 pAttributeV1;
    } Attribute;
} TOKEN_SECURITY_ATTRIBUTES_INFORMATION, *PTOKEN_SECURITY_ATTRIBUTES_INFORMATION;

enum TOKEN_INFORMATION_CLASS : UINT32
{
    TokenUser = 1,
    TokenGroups,
    TokenPrivileges,
    TokenOwner,
    TokenPrimaryGroup,
    TokenDefaultDacl,
    TokenSource,
    TokenType,
    TokenImpersonationLevel,
    TokenStatistics,
    TokenRestrictedSids,
    TokenSessionId,
    TokenGroupsAndPrivileges,
    TokenSessionReference,
    TokenSandBoxInert,
    TokenAuditPolicy,
    TokenOrigin,
    TokenElevationType,
    TokenLinkedToken,
    TokenElevation,
    TokenHasRestrictions,
    TokenAccessInformation,
    TokenVirtualizationAllowed,
    TokenVirtualizationEnabled,
    TokenIntegrityLevel,
    TokenUIAccess,
    TokenMandatoryPolicy,
    TokenLogonSid,
    TokenIsAppContainer,
    TokenCapabilities,
    TokenAppContainerSid,
    TokenAppContainerNumber,
    TokenUserClaimAttributes,
    TokenDeviceClaimAttributes,
    TokenRestrictedUserClaimAttributes,
    TokenRestrictedDeviceClaimAttributes,
    TokenDeviceGroups,
    TokenRestrictedDeviceGroups,
    TokenSecurityAttributes,
    TokenIsRestricted,
    TokenProcessTrustLevel,
    TokenPrivateNameSpace,
    TokenSingletonAttributes,
    MaxTokenInfoClass  // MaxTokenInfoClass should always be the last enum
};


//
// Token information class structures
//

typedef struct _TOKEN_USER {
    SID_AND_ATTRIBUTES User;
} TOKEN_USER, *PTOKEN_USER;

typedef struct _SE_TOKEN_USER {
    union {
        TOKEN_USER TokenUser;
        SID_AND_ATTRIBUTES User;
    } DUMMYUNIONNAME;

    union {
        SID Sid;
        BYTE  Buffer[SECURITY_MAX_SID_SIZE];
    } DUMMYUNIONNAME2;

} SE_TOKEN_USER, PSE_TOKEN_USER;

#define TOKEN_USER_MAX_SIZE (sizeof(TOKEN_USER) + SECURITY_MAX_SID_SIZE)

typedef struct _TOKEN_GROUPS {
    UINT32 GroupCount;
    SID_AND_ATTRIBUTES Groups[ANYSIZE_ARRAY];
} TOKEN_GROUPS, *PTOKEN_GROUPS;

typedef struct _TOKEN_PRIVILEGES {
    UINT32 PrivilegeCount;
    LUID_AND_ATTRIBUTES Privileges[ANYSIZE_ARRAY];
} TOKEN_PRIVILEGES, *PTOKEN_PRIVILEGES;


typedef struct _TOKEN_OWNER {
    PSID Owner;
} TOKEN_OWNER, *PTOKEN_OWNER;

#define TOKEN_OWNER_MAX_SIZE (sizeof(TOKEN_OWNER) + SECURITY_MAX_SID_SIZE)

typedef struct _TOKEN_PRIMARY_GROUP {
    PSID PrimaryGroup;
} TOKEN_PRIMARY_GROUP, *PTOKEN_PRIMARY_GROUP;

typedef struct _TOKEN_DEFAULT_DACL {
    PACL DefaultDacl;
} TOKEN_DEFAULT_DACL, *PTOKEN_DEFAULT_DACL;

typedef struct _TOKEN_USER_CLAIMS {
    void*   UserClaims;     // PCLAIMS_BLOB UserClaims;
} TOKEN_USER_CLAIMS, *PTOKEN_USER_CLAIMS;

typedef struct _TOKEN_DEVICE_CLAIMS {
    void*   DeviceClaims;   // PCLAIMS_BLOB DeviceClaims;
} TOKEN_DEVICE_CLAIMS, *PTOKEN_DEVICE_CLAIMS;

typedef struct _TOKEN_GROUPS_AND_PRIVILEGES {
    UINT32 SidCount;
    UINT32 SidLength;
    PSID_AND_ATTRIBUTES Sids;
    UINT32 RestrictedSidCount;
    UINT32 RestrictedSidLength;
    PSID_AND_ATTRIBUTES RestrictedSids;
    UINT32 PrivilegeCount;
    UINT32 PrivilegeLength;
    PLUID_AND_ATTRIBUTES Privileges;
    LUID AuthenticationId;
} TOKEN_GROUPS_AND_PRIVILEGES, *PTOKEN_GROUPS_AND_PRIVILEGES;

typedef struct _TOKEN_LINKED_TOKEN {
    HANDLE LinkedToken;
} TOKEN_LINKED_TOKEN, *PTOKEN_LINKED_TOKEN;

typedef struct _TOKEN_ELEVATION {
    UINT32 TokenIsElevated;
} TOKEN_ELEVATION, *PTOKEN_ELEVATION;

typedef struct _TOKEN_MANDATORY_LABEL {
    SID_AND_ATTRIBUTES Label;
} TOKEN_MANDATORY_LABEL, *PTOKEN_MANDATORY_LABEL;

enum TOKEN_MANDATORY_POLICY_FLAGS : UINT32
{
    TOKEN_MANDATORY_POLICY_OFF              = 0x00000000,
    TOKEN_MANDATORY_POLICY_NO_WRITE_UP      = 0x00000001,
    TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN  = 0x00000002,
    TOKEN_MANDATORY_POLICY_VALID_MASK = (TOKEN_MANDATORY_POLICY_NO_WRITE_UP 
                                         | TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN),

};

#define TOKEN_INTEGRITY_LEVEL_MAX_SIZE ((((UINT32)(sizeof(TOKEN_MANDATORY_LABEL)) + sizeof(void*) - 1) & ~(sizeof(void*)-1)) + SECURITY_MAX_SID_SIZE)

typedef struct _TOKEN_MANDATORY_POLICY {
    UINT32 Policy;
} TOKEN_MANDATORY_POLICY, *PTOKEN_MANDATORY_POLICY;

using PSECURITY_ATTRIBUTES_OPAQUE = void*;

typedef enum _SECURITY_IMPERSONATION_LEVEL {
    SecurityAnonymous,
    SecurityIdentification,
    SecurityImpersonation,
    SecurityDelegation
} SECURITY_IMPERSONATION_LEVEL, *PSECURITY_IMPERSONATION_LEVEL;

typedef struct _TOKEN_ACCESS_INFORMATION {
    PSID_AND_ATTRIBUTES_HASH SidHash;
    PSID_AND_ATTRIBUTES_HASH RestrictedSidHash;
    PTOKEN_PRIVILEGES Privileges;
    LUID AuthenticationId;
    TOKEN_TYPE TokenType;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    TOKEN_MANDATORY_POLICY MandatoryPolicy;
    UINT32 Flags;
    UINT32 AppContainerNumber;
    PSID PackageSid;
    PSID_AND_ATTRIBUTES_HASH CapabilitiesHash;
    PSID TrustLevelSid;
    PSECURITY_ATTRIBUTES_OPAQUE SecurityAttributes;
} TOKEN_ACCESS_INFORMATION, *PTOKEN_ACCESS_INFORMATION;

//
// Valid bits for each TOKEN_AUDIT_POLICY policy mask field.
//

typedef struct _TOKEN_AUDIT_POLICY {
    enum : UINT32
    {
        POLICY_AUDIT_SUBCATEGORY_COUNT = 59,
    };

    BYTE  PerUserPolicy[((POLICY_AUDIT_SUBCATEGORY_COUNT) >> 1) + 1];
} TOKEN_AUDIT_POLICY, *PTOKEN_AUDIT_POLICY;

typedef struct _TOKEN_SOURCE {
    enum : UINT32
    {
        TOKEN_SOURCE_LENGTH = 8,
    };

    UINT8 SourceName[TOKEN_SOURCE_LENGTH];
    LUID SourceIdentifier;
} TOKEN_SOURCE, *PTOKEN_SOURCE;


typedef struct _TOKEN_STATISTICS {
    LUID TokenId;
    LUID AuthenticationId;
    LARGE_INTEGER ExpirationTime;
    TOKEN_TYPE TokenType;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    UINT32 DynamicCharged;
    UINT32 DynamicAvailable;
    UINT32 GroupCount;
    UINT32 PrivilegeCount;
    LUID ModifiedId;
} TOKEN_STATISTICS, *PTOKEN_STATISTICS;

typedef struct _TOKEN_CONTROL {
    LUID TokenId;
    LUID AuthenticationId;
    LUID ModifiedId;
    TOKEN_SOURCE TokenSource;
} TOKEN_CONTROL, *PTOKEN_CONTROL;

typedef struct _TOKEN_ORIGIN {
    LUID OriginatingLogonSession;
} TOKEN_ORIGIN, *PTOKEN_ORIGIN;

typedef struct _TOKEN_APPCONTAINER_INFORMATION {
    PSID TokenAppContainer;
} TOKEN_APPCONTAINER_INFORMATION, *PTOKEN_APPCONTAINER_INFORMATION;

#define TOKEN_APPCONTAINER_SID_MAX_SIZE (sizeof(TOKEN_APPCONTAINER_INFORMATION) + SECURITY_MAX_SID_SIZE)

typedef struct _TOKEN_SID_INFORMATION {
    PSID Sid;
} TOKEN_SID_INFORMATION, *PTOKEN_SID_INFORMATION;


//
// Object Type list for AccessCheckByType
//

typedef struct _OBJECT_TYPE_LIST {
    UINT16   Level;
    UINT16   Sbz;
    GUID *ObjectType;
} OBJECT_TYPE_LIST, *POBJECT_TYPE_LIST;

//
// DS values for Level
//

#define ACCESS_OBJECT_GUID       0
#define ACCESS_PROPERTY_SET_GUID 1
#define ACCESS_PROPERTY_GUID     2

#define ACCESS_MAX_LEVEL         4

//
// Parameters to NtAccessCheckByTypeAndAditAlarm
//

typedef enum _AUDIT_EVENT_TYPE {
    AuditEventObjectAccess,
    AuditEventDirectoryServiceAccess
} AUDIT_EVENT_TYPE, *PAUDIT_EVENT_TYPE;

#define AUDIT_ALLOW_NO_PRIVILEGE 0x1

//
// DS values for Source and ObjectTypeName
//

#define ACCESS_DS_SOURCE_A "DS"
#define ACCESS_DS_SOURCE_W L"DS"
#define ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#define ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

//
// Privilege Set Control flags
//

enum PRIVILEGE_SET_CONTROL_FLAGS : UINT32 
{
    PRIVILEGE_SET_ALL_NECESSARY = 1,
};

//
//  Privilege Set - This is defined for a privilege set of one.
//                  If more than one privilege is needed, then this structure
//                  will need to be allocated with more space.
//
//  Note: don't change this structure without fixing the INITIAL_PRIVILEGE_SET
//  structure (defined in se.h)
//

typedef struct _PRIVILEGE_SET {
    UINT32 PrivilegeCount;
    UINT32 Control;
    LUID_AND_ATTRIBUTES Privilege[ANYSIZE_ARRAY];
} PRIVILEGE_SET, *PPRIVILEGE_SET;

enum SE_SIGNING_LEVEL : UINT8 
{
    SE_SIGNING_LEVEL_UNCHECKED = 0x00000000,
    SE_SIGNING_LEVEL_UNSIGNED = 0x00000001,
    SE_SIGNING_LEVEL_ENTERPRISE = 0x00000002,
    SE_SIGNING_LEVEL_CUSTOM_1 = 0x00000003,
    SE_SIGNING_LEVEL_AUTHENTICODE = 0x00000004,
    SE_SIGNING_LEVEL_CUSTOM_2 = 0x00000005,
    SE_SIGNING_LEVEL_STORE = 0x00000006,
    SE_SIGNING_LEVEL_CUSTOM_3 = 0x00000007,
    SE_SIGNING_LEVEL_ANTIMALWARE = SE_SIGNING_LEVEL_CUSTOM_3,
    SE_SIGNING_LEVEL_MICROSOFT = 0x00000008,
    SE_SIGNING_LEVEL_CUSTOM_4 = 0x00000009,
    SE_SIGNING_LEVEL_CUSTOM_5 = 0x0000000A,
    SE_SIGNING_LEVEL_DYNAMIC_CODEGEN = 0x0000000B,
    SE_SIGNING_LEVEL_WINDOWS = 0x0000000C,
    SE_SIGNING_LEVEL_CUSTOM_7 = 0x0000000D,
    SE_SIGNING_LEVEL_WINDOWS_TCB = 0x0000000E,
    SE_SIGNING_LEVEL_CUSTOM_6 = 0x0000000F,
};

typedef struct _LOWBOX_DATA
{
    HANDLE RootDirectory;       // AppContainers 主目录对象句柄
    HANDLE RpcControlDirectory; // AppContainers RPC目录对象句柄
    HANDLE LocalSymbolicLink;   // AppContainers Local对象句柄
    HANDLE GlobalSymbolicLink;  // Global对象句柄
    HANDLE SessionSymbolicLink; // AppContainers Session对象句柄
    HANDLE NamedPipe;           // AppContainers 命名管道句柄

} LOWBOX_DATA, *PLOWBOX_DATA;

//////////////////////////////////////////////////////////////////////////

//
// NtXXXToken
//

extern"C"
{
    NTSTATUS NtQueryInformationToken(
        HANDLE TokenHandle,
        TOKEN_INFORMATION_CLASS TokenInformationClass,
        void* TokenInformation,
        UINT32 TokenInformationLength,
        UINT32* ReturnLength
    );

    NTSTATUS NtCreateToken(
        HANDLE* TokenHandle,
        ACCESS_MASK DesiredAccess,
        OBJECT_ATTRIBUTES* ObjectAttributes,
        TOKEN_TYPE TokenType,
        PLUID AuthenticationId,
        PLARGE_INTEGER ExpirationTime,
        PTOKEN_USER User,
        PTOKEN_GROUPS Groups,
        PTOKEN_PRIVILEGES Privileges,
        PTOKEN_OWNER Owner,
        PTOKEN_PRIMARY_GROUP PrimaryGroup,
        PTOKEN_DEFAULT_DACL DefaultDacl,
        PTOKEN_SOURCE TokenSource
    );

    NTSTATUS NtCreateLowBoxToken(
        HANDLE* LowBoxToken,
        HANDLE ExistingTokenHandle,
        ACCESS_MASK DesiredAccess,
        OBJECT_ATTRIBUTES* ObjectAttributes,
        PSID AppContainerSid,
        UINT32 CapabilityCount,
        PSID_AND_ATTRIBUTES Capabilities,
        UINT32 LowBoxDataHandleCount,
        LOWBOX_DATA *LowBoxData
    );

    NTSTATUS NtCreateTokenEx(
        HANDLE* TokenHandle,
        ACCESS_MASK DesiredAccess,
        OBJECT_ATTRIBUTES* ObjectAttributes,
        TOKEN_TYPE TokenType,
        PLUID AuthenticationId,
        PLARGE_INTEGER ExpirationTime,
        PTOKEN_USER User,
        PTOKEN_GROUPS Groups,
        PTOKEN_PRIVILEGES Privileges,
        PTOKEN_SECURITY_ATTRIBUTES_INFORMATION UserAttributes,
        PTOKEN_SECURITY_ATTRIBUTES_INFORMATION DeviceAttributes,
        PTOKEN_GROUPS DeviceGroups,
        PTOKEN_MANDATORY_POLICY TokenMandatoryPolicy,
        PTOKEN_OWNER Owner,
        PTOKEN_PRIMARY_GROUP PrimaryGroup,
        PTOKEN_DEFAULT_DACL DefaultDacl,
        PTOKEN_SOURCE TokenSource
    );

    NTSTATUS NtOpenProcessToken(
        HANDLE ProcessHandle,
        ACCESS_MASK DesiredAccess,
        HANDLE* TokenHandle
    );

    NTSTATUS NtOpenProcessTokenEx(
        HANDLE ProcessHandle,
        ACCESS_MASK DesiredAccess,
        UINT32 HandleAttributes,
        HANDLE* TokenHandle
    );

    NTSTATUS NtOpenThreadToken(
        HANDLE ThreadHandle,
        ACCESS_MASK DesiredAccess,
        BOOLEAN OpenAsSelf,
        HANDLE* TokenHandle
    );

    NTSTATUS NtOpenThreadTokenEx(
        HANDLE ThreadHandle,
        ACCESS_MASK DesiredAccess,
        BOOLEAN OpenAsSelf,
        UINT32 HandleAttributes,
        HANDLE* TokenHandle
    );

    NTSTATUS NtDuplicateToken(
        HANDLE ExistingTokenHandle,
        ACCESS_MASK DesiredAccess,
        OBJECT_ATTRIBUTES* ObjectAttributes,
        BOOLEAN EffectiveOnly,
        TOKEN_TYPE TokenType,
        HANDLE* NewTokenHandle
    );

    NTSTATUS NtQueryInformationToken(
        HANDLE TokenHandle,
        TOKEN_INFORMATION_CLASS TokenInformationClass,
        void* TokenInformation,
        UINT32 TokenInformationLength,
        UINT32* ReturnLength
    );

    NTSTATUS NtSetInformationToken(
        HANDLE TokenHandle,
        TOKEN_INFORMATION_CLASS TokenInformationClass,
        void* TokenInformation,
        UINT32 TokenInformationLength
    );

    NTSTATUS NtAdjustPrivilegesToken(
        HANDLE TokenHandle,
        BOOLEAN DisableAllPrivileges,
        PTOKEN_PRIVILEGES NewState,
        UINT32 BufferLength,
        PTOKEN_PRIVILEGES PreviousState,
        UINT32* ReturnLength
    );

    NTSTATUS NtAdjustGroupsToken(
        HANDLE TokenHandle,
        BOOLEAN ResetToDefault,
        PTOKEN_GROUPS NewState,
        UINT32 BufferLength,
        PTOKEN_GROUPS PreviousState,
        UINT32* ReturnLength
    );

    NTSTATUS NtAdjustTokenClaimsAndDeviceGroups(
        HANDLE TokenHandle,
        BOOLEAN UserResetToDefault,
        BOOLEAN DeviceResetToDefault,
        BOOLEAN DeviceGroupsResetToDefault,
        PTOKEN_SECURITY_ATTRIBUTES_INFORMATION NewUserState,
        PTOKEN_SECURITY_ATTRIBUTES_INFORMATION NewDeviceState,
        PTOKEN_GROUPS NewDeviceGroupsState,
        UINT32 UserBufferLength,
        PTOKEN_SECURITY_ATTRIBUTES_INFORMATION PreviousUserState,
        UINT32 DeviceBufferLength,
        PTOKEN_SECURITY_ATTRIBUTES_INFORMATION PreviousDeviceState,
        UINT32 DeviceGroupsBufferLength,
        PTOKEN_GROUPS PreviousDeviceGroups,
        UINT32* UserReturnLength,
        UINT32* DeviceReturnLength,
        UINT32* DeviceGroupsReturnBufferLength
    );

    NTSTATUS NtFilterToken(
        HANDLE ExistingTokenHandle,
        UINT32 Flags,
        PTOKEN_GROUPS SidsToDisable,
        PTOKEN_PRIVILEGES PrivilegesToDelete,
        PTOKEN_GROUPS RestrictedSids,
        HANDLE* NewTokenHandle
    );

    NTSTATUS NtFilterTokenEx(
        HANDLE ExistingTokenHandle,
        UINT32 Flags,
        PTOKEN_GROUPS SidsToDisable,
        PTOKEN_PRIVILEGES PrivilegesToDelete,
        PTOKEN_GROUPS RestrictedSids,
        UINT32 DisableUserClaimsCount,
        PUNICODE_STRING UserClaimsToDisable,
        UINT32 DisableDeviceClaimsCount,
        PUNICODE_STRING DeviceClaimsToDisable,
        PTOKEN_GROUPS DeviceGroupsToDisable,
        PTOKEN_SECURITY_ATTRIBUTES_INFORMATION RestrictedUserAttributes,
        PTOKEN_SECURITY_ATTRIBUTES_INFORMATION RestrictedDeviceAttributes,
        PTOKEN_GROUPS RestrictedDeviceGroups,
        HANDLE* NewTokenHandle
    );

    NTSTATUS NtCompareTokens(
        HANDLE FirstTokenHandle,
        HANDLE SecondTokenHandle,
        BOOLEAN* Equal
    );

    NTSTATUS NtPrivilegeCheck(
        HANDLE ClientToken,
        PPRIVILEGE_SET RequiredPrivileges,
        BOOLEAN* Result
    );

    NTSTATUS NtImpersonateAnonymousToken(
        HANDLE ThreadHandle
    );


    NTSTATUS NtQuerySecurityAttributesToken(
        HANDLE TokenHandle,
        PUNICODE_STRING Attributes,
        UINT32 NumberOfAttributes,
        void* Buffer, // PTOKEN_SECURITY_ATTRIBUTES_INFORMATION
        UINT32 Length,
        UINT32* ReturnLength
    );

    // Access checking

    NTSTATUS NtAccessCheck(
        PSECURITY_DESCRIPTOR SecurityDescriptor,
        HANDLE ClientToken,
        ACCESS_MASK DesiredAccess,
        PGENERIC_MAPPING GenericMapping,
        PPRIVILEGE_SET PrivilegeSet,
        UINT32* PrivilegeSetLength,
        ACCESS_MASK* GrantedAccess,
        NTSTATUS* AccessStatus
    );

    NTSTATUS NtAccessCheckByType(
        PSECURITY_DESCRIPTOR SecurityDescriptor,
        PSID PrincipalSelfSid,
        HANDLE ClientToken,
        ACCESS_MASK DesiredAccess,
        POBJECT_TYPE_LIST ObjectTypeList,
        UINT32 ObjectTypeListLength,
        PGENERIC_MAPPING GenericMapping,
        PPRIVILEGE_SET PrivilegeSet,
        UINT32* PrivilegeSetLength,
        ACCESS_MASK* GrantedAccess,
        NTSTATUS* AccessStatus
    );

    NTSTATUS NtAccessCheckByTypeResultList(
        PSECURITY_DESCRIPTOR SecurityDescriptor,
        PSID PrincipalSelfSid,
        HANDLE ClientToken,
        ACCESS_MASK DesiredAccess,
        POBJECT_TYPE_LIST ObjectTypeList,
        UINT32 ObjectTypeListLength,
        PGENERIC_MAPPING GenericMapping,
        PPRIVILEGE_SET PrivilegeSet,
        UINT32* PrivilegeSetLength,
        ACCESS_MASK* GrantedAccess,
        NTSTATUS* AccessStatus
    );

    // Signing

    NTSTATUS NtSetCachedSigningLevel(
        UINT32 Flags,
        SE_SIGNING_LEVEL InputSigningLevel,
        HANDLE* SourceFiles,
        UINT32 SourceFileCount,
        HANDLE TargetFile
    );

    NTSTATUS NtGetCachedSigningLevel(
        HANDLE File,
        UINT32* Flags,
        SE_SIGNING_LEVEL* SigningLevel,
        UINT8* Thumbprint,
        UINT32* ThumbprintSize,
        UINT32* ThumbprintAlgorithm
    );

    // Audit alarm

    NTSTATUS NtAccessCheckAndAuditAlarm(
        PUNICODE_STRING SubsystemName,
        void* HandleId,
        PUNICODE_STRING ObjectTypeName,
        PUNICODE_STRING ObjectName,
        PSECURITY_DESCRIPTOR SecurityDescriptor,
        ACCESS_MASK DesiredAccess,
        PGENERIC_MAPPING GenericMapping,
        BOOLEAN ObjectCreation,
        ACCESS_MASK* GrantedAccess,
        NTSTATUS* AccessStatus,
        BOOLEAN* GenerateOnClose
    );

    NTSTATUS NtAccessCheckByTypeAndAuditAlarm(
        PUNICODE_STRING SubsystemName,
        void* HandleId,
        PUNICODE_STRING ObjectTypeName,
        PUNICODE_STRING ObjectName,
        PSECURITY_DESCRIPTOR SecurityDescriptor,
        PSID PrincipalSelfSid,
        ACCESS_MASK DesiredAccess,
        AUDIT_EVENT_TYPE AuditType,
        UINT32 Flags,
        POBJECT_TYPE_LIST ObjectTypeList,
        UINT32 ObjectTypeListLength,
        PGENERIC_MAPPING GenericMapping,
        BOOLEAN ObjectCreation,
        ACCESS_MASK* GrantedAccess,
        NTSTATUS* AccessStatus,
        BOOLEAN* GenerateOnClose
    );

    NTSTATUS NtAccessCheckByTypeResultListAndAuditAlarm(
        PUNICODE_STRING SubsystemName,
        void* HandleId,
        PUNICODE_STRING ObjectTypeName,
        PUNICODE_STRING ObjectName,
        PSECURITY_DESCRIPTOR SecurityDescriptor,
        PSID PrincipalSelfSid,
        ACCESS_MASK DesiredAccess,
        AUDIT_EVENT_TYPE AuditType,
        UINT32 Flags,
        POBJECT_TYPE_LIST ObjectTypeList,
        UINT32 ObjectTypeListLength,
        PGENERIC_MAPPING GenericMapping,
        BOOLEAN ObjectCreation,
        ACCESS_MASK* GrantedAccess,
        NTSTATUS* AccessStatus,
        BOOLEAN* GenerateOnClose
    );

    NTSTATUS NtAccessCheckByTypeResultListAndAuditAlarmByHandle(
        PUNICODE_STRING SubsystemName,
        void* HandleId,
        HANDLE ClientToken,
        PUNICODE_STRING ObjectTypeName,
        PUNICODE_STRING ObjectName,
        PSECURITY_DESCRIPTOR SecurityDescriptor,
        PSID PrincipalSelfSid,
        ACCESS_MASK DesiredAccess,
        AUDIT_EVENT_TYPE AuditType,
        UINT32 Flags,
        POBJECT_TYPE_LIST ObjectTypeList,
        UINT32 ObjectTypeListLength,
        PGENERIC_MAPPING GenericMapping,
        BOOLEAN ObjectCreation,
        ACCESS_MASK* GrantedAccess,
        NTSTATUS* AccessStatus,
        BOOLEAN* GenerateOnClose
    );

    NTSTATUS NtOpenObjectAuditAlarm(
        PUNICODE_STRING SubsystemName,
        void* HandleId,
        PUNICODE_STRING ObjectTypeName,
        PUNICODE_STRING ObjectName,
        PSECURITY_DESCRIPTOR SecurityDescriptor,
        HANDLE ClientToken,
        ACCESS_MASK DesiredAccess,
        ACCESS_MASK GrantedAccess,
        PPRIVILEGE_SET Privileges,
        BOOLEAN ObjectCreation,
        BOOLEAN AccessGranted,
        BOOLEAN* GenerateOnClose
    );

    NTSTATUS NtPrivilegeObjectAuditAlarm(
        PUNICODE_STRING SubsystemName,
        void* HandleId,
        HANDLE ClientToken,
        ACCESS_MASK DesiredAccess,
        PPRIVILEGE_SET Privileges,
        BOOLEAN AccessGranted
    );

    NTSTATUS NtCloseObjectAuditAlarm(
        PUNICODE_STRING SubsystemName,
        void* HandleId,
        BOOLEAN GenerateOnClose
    );


    NTSTATUS NtDeleteObjectAuditAlarm(
        PUNICODE_STRING SubsystemName,
        void* HandleId,
        BOOLEAN GenerateOnClose
    );

    NTSTATUS NtPrivilegedServiceAuditAlarm(
        PUNICODE_STRING SubsystemName,
        PUNICODE_STRING ServiceName,
        HANDLE ClientToken,
        PPRIVILEGE_SET Privileges,
        BOOLEAN AccessGranted
    );

    // Misc.

    typedef enum _FILTER_BOOT_OPTION_OPERATION
    {
        FilterBootOptionOperationOpenSystemStore,
        FilterBootOptionOperationSetElement,
        FilterBootOptionOperationDeleteElement,
        FilterBootOptionOperationMax
    } FILTER_BOOT_OPTION_OPERATION;

    NTSTATUS NtFilterBootOption(
        FILTER_BOOT_OPTION_OPERATION FilterOperation,
        UINT32 ObjectType,
        UINT32 ElementType,
        void* Data,
        UINT32 DataSize
    );

    //
    // Security Object
    //

    NTSTATUS NtSetSecurityObject(
        HANDLE Handle, 
        SECURITY_INFORMATION SecurityInformation, 
        PSECURITY_DESCRIPTOR SecurityDescriptor);
}