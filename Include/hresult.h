#pragma once
#include "doserror.h"

//////////////////////////////////////////////////////////////////////////

enum HRESULT : unsigned long
{
    S_OK = 0x00000000L,
    S_FALSE = 0x00000001L,

    //
    // Codes 0x4000-0x40ff are reserved for OLE
    //
    //
    // Error codes
    //
    //
    // MessageId: E_UNEXPECTED
    //
    // MessageText:
    //
    // Catastrophic failure
    //
    E_UNEXPECTED = 0x8000FFFFL,

    //
    // MessageId: E_NOTIMPL
    //
    // MessageText:
    //
    // Not implemented
    //
    E_NOTIMPL = 0x80004001L,

    //
    // MessageId: E_OUTOFMEMORY
    //
    // MessageText:
    //
    // Ran out of memory
    //
    E_OUTOFMEMORY = 0x8007000EL,

    //
    // MessageId: E_INVALIDARG
    //
    // MessageText:
    //
    // One or more arguments are invalid
    //
    E_INVALIDARG = 0x80070057L,

    //
    // MessageId: E_NOINTERFACE
    //
    // MessageText:
    //
    // No such interface supported
    //
    E_NOINTERFACE = 0x80004002L,

    //
    // MessageId: E_POINTER
    //
    // MessageText:
    //
    // Invalid pointer
    //
    E_POINTER = 0x80004003L,

    //
    // MessageId: E_HANDLE
    //
    // MessageText:
    //
    // Invalid handle
    //
    E_HANDLE = 0x80070006L,

    //
    // MessageId: E_ABORT
    //
    // MessageText:
    //
    // Operation aborted
    //
    E_ABORT = 0x80004004L,

    //
    // MessageId: E_FAIL
    //
    // MessageText:
    //
    // Unspecified error
    //
    E_FAIL = 0x80004005L,

    //
    // MessageId: E_ACCESSDENIED
    //
    // MessageText:
    //
    // General access denied error
    //
    E_ACCESSDENIED = 0x80070005L,

    //
    // MessageId: E_PENDING
    //
    // MessageText:
    //
    // The data necessary to complete this operation is not yet available.
    //
    E_PENDING = 0x8000000AL,

    //
    // MessageId: E_BOUNDS
    //
    // MessageText:
    //
    // The operation attempted to access data outside the valid range
    //
    E_BOUNDS = 0x8000000BL,

    //
    // MessageId: E_CHANGED_STATE
    //
    // MessageText:
    //
    // A concurrent or interleaved operation changed the state of the object, invalidating this operation.
    //
    E_CHANGED_STATE = 0x8000000CL,

    //
    // MessageId: E_ILLEGAL_STATE_CHANGE
    //
    // MessageText:
    //
    // An illegal state change was requested.
    //
    E_ILLEGAL_STATE_CHANGE = 0x8000000DL,

    //
    // MessageId: E_ILLEGAL_METHOD_CALL
    //
    // MessageText:
    //
    // A method was called at an unexpected time.
    //
    E_ILLEGAL_METHOD_CALL = 0x8000000EL,

    //
    // MessageId: RO_E_METADATA_NAME_NOT_FOUND
    //
    // MessageText:
    //
    // Typename or Namespace was not found in metadata file.
    //
    RO_E_METADATA_NAME_NOT_FOUND = 0x8000000FL,

    //
    // MessageId: RO_E_METADATA_NAME_IS_NAMESPACE
    //
    // MessageText:
    //
    // Name is an existing namespace rather than a typename.
    //
    RO_E_METADATA_NAME_IS_NAMESPACE = 0x80000010L,

    //
    // MessageId: RO_E_METADATA_INVALID_TYPE_FORMAT
    //
    // MessageText:
    //
    // Typename has an invalid format.
    //
    RO_E_METADATA_INVALID_TYPE_FORMAT = 0x80000011L,

    //
    // MessageId: RO_E_INVALID_METADATA_FILE
    //
    // MessageText:
    //
    // Metadata file is invalid or corrupted.
    //
    RO_E_INVALID_METADATA_FILE = 0x80000012L,

    //
    // MessageId: RO_E_CLOSED
    //
    // MessageText:
    //
    // The object has been closed.
    //
    RO_E_CLOSED = 0x80000013L,

    //
    // MessageId: RO_E_EXCLUSIVE_WRITE
    //
    // MessageText:
    //
    // Only one thread may access the object during a write operation.
    //
    RO_E_EXCLUSIVE_WRITE = 0x80000014L,

    //
    // MessageId: RO_E_CHANGE_NOTIFICATION_IN_PROGRESS
    //
    // MessageText:
    //
    // Operation is prohibited during change notification.
    //
    RO_E_CHANGE_NOTIFICATION_IN_PROGRESS = 0x80000015L,

    //
    // MessageId: RO_E_ERROR_STRING_NOT_FOUND
    //
    // MessageText:
    //
    // The text associated with this error code could not be found.
    //
    RO_E_ERROR_STRING_NOT_FOUND = 0x80000016L,

    //
    // MessageId: E_STRING_NOT_NULL_TERMINATED
    //
    // MessageText:
    //
    // String not null terminated.
    //
    E_STRING_NOT_NULL_TERMINATED = 0x80000017L,

    //
    // MessageId: E_ILLEGAL_DELEGATE_ASSIGNMENT
    //
    // MessageText:
    //
    // A delegate was assigned when not allowed.
    //
    E_ILLEGAL_DELEGATE_ASSIGNMENT = 0x80000018L,

    //
    // MessageId: E_ASYNC_OPERATION_NOT_STARTED
    //
    // MessageText:
    //
    // An async operation was not properly started.
    //
    E_ASYNC_OPERATION_NOT_STARTED = 0x80000019L,

    //
    // MessageId: E_APPLICATION_EXITING
    //
    // MessageText:
    //
    // The application is exiting and cannot service this request
    //
    E_APPLICATION_EXITING = 0x8000001AL,

    //
    // MessageId: E_APPLICATION_VIEW_EXITING
    //
    // MessageText:
    //
    // The application view is exiting and cannot service this request
    //
    E_APPLICATION_VIEW_EXITING = 0x8000001BL,

    //
    // MessageId: RO_E_MUST_BE_AGILE
    //
    // MessageText:
    //
    // The object must support the IAgileObject interface
    //
    RO_E_MUST_BE_AGILE = 0x8000001CL,

    //
    // MessageId: RO_E_UNSUPPORTED_FROM_MTA
    //
    // MessageText:
    //
    // Activating a single-threaded class from MTA is not supported
    //
    RO_E_UNSUPPORTED_FROM_MTA = 0x8000001DL,

    //
    // MessageId: RO_E_COMMITTED
    //
    // MessageText:
    //
    // The object has been committed.
    //
    RO_E_COMMITTED = 0x8000001EL,

    //
    // MessageId: RO_E_BLOCKED_CROSS_ASTA_CALL
    //
    // MessageText:
    //
    // A COM call to an ASTA was blocked because the call chain originated in or passed through another ASTA. This call pattern is deadlock-prone and disallowed by apartment call control.
    //
    RO_E_BLOCKED_CROSS_ASTA_CALL = 0x8000001FL,

    //
    // MessageId: CO_E_INIT_TLS
    //
    // MessageText:
    //
    // Thread local storage failure
    //
    CO_E_INIT_TLS = 0x80004006L,

    //
    // MessageId: CO_E_INIT_SHARED_ALLOCATOR
    //
    // MessageText:
    //
    // Get shared memory allocator failure
    //
    CO_E_INIT_SHARED_ALLOCATOR = 0x80004007L,

    //
    // MessageId: CO_E_INIT_MEMORY_ALLOCATOR
    //
    // MessageText:
    //
    // Get memory allocator failure
    //
    CO_E_INIT_MEMORY_ALLOCATOR = 0x80004008L,

    //
    // MessageId: CO_E_INIT_CLASS_CACHE
    //
    // MessageText:
    //
    // Unable to initialize class cache
    //
    CO_E_INIT_CLASS_CACHE = 0x80004009L,

    //
    // MessageId: CO_E_INIT_RPC_CHANNEL
    //
    // MessageText:
    //
    // Unable to initialize RPC services
    //
    CO_E_INIT_RPC_CHANNEL = 0x8000400AL,

    //
    // MessageId: CO_E_INIT_TLS_SET_CHANNEL_CONTROL
    //
    // MessageText:
    //
    // Cannot set thread local storage channel control
    //
    CO_E_INIT_TLS_SET_CHANNEL_CONTROL = 0x8000400BL,

    //
    // MessageId: CO_E_INIT_TLS_CHANNEL_CONTROL
    //
    // MessageText:
    //
    // Could not allocate thread local storage channel control
    //
    CO_E_INIT_TLS_CHANNEL_CONTROL = 0x8000400CL,

    //
    // MessageId: CO_E_INIT_UNACCEPTED_USER_ALLOCATOR
    //
    // MessageText:
    //
    // The user supplied memory allocator is unacceptable
    //
    CO_E_INIT_UNACCEPTED_USER_ALLOCATOR = 0x8000400DL,

    //
    // MessageId: CO_E_INIT_SCM_MUTEX_EXISTS
    //
    // MessageText:
    //
    // The OLE service mutex already exists
    //
    CO_E_INIT_SCM_MUTEX_EXISTS = 0x8000400EL,

    //
    // MessageId: CO_E_INIT_SCM_FILE_MAPPING_EXISTS
    //
    // MessageText:
    //
    // The OLE service file mapping already exists
    //
    CO_E_INIT_SCM_FILE_MAPPING_EXISTS = 0x8000400FL,

    //
    // MessageId: CO_E_INIT_SCM_MAP_VIEW_OF_FILE
    //
    // MessageText:
    //
    // Unable to map view of file for OLE service
    //
    CO_E_INIT_SCM_MAP_VIEW_OF_FILE = 0x80004010L,

    //
    // MessageId: CO_E_INIT_SCM_EXEC_FAILURE
    //
    // MessageText:
    //
    // Failure attempting to launch OLE service
    //
    CO_E_INIT_SCM_EXEC_FAILURE = 0x80004011L,

    //
    // MessageId: CO_E_INIT_ONLY_SINGLE_THREADED
    //
    // MessageText:
    //
    // There was an attempt to call CoInitialize a second time while single threaded
    //
    CO_E_INIT_ONLY_SINGLE_THREADED = 0x80004012L,

    //
    // MessageId: CO_E_CANT_REMOTE
    //
    // MessageText:
    //
    // A Remote activation was necessary but was not allowed
    //
    CO_E_CANT_REMOTE = 0x80004013L,

    //
    // MessageId: CO_E_BAD_SERVER_NAME
    //
    // MessageText:
    //
    // A Remote activation was necessary but the server name provided was invalid
    //
    CO_E_BAD_SERVER_NAME = 0x80004014L,

    //
    // MessageId: CO_E_WRONG_SERVER_IDENTITY
    //
    // MessageText:
    //
    // The class is configured to run as a security id different from the caller
    //
    CO_E_WRONG_SERVER_IDENTITY = 0x80004015L,

    //
    // MessageId: CO_E_OLE1DDE_DISABLED
    //
    // MessageText:
    //
    // Use of Ole1 services requiring DDE windows is disabled
    //
    CO_E_OLE1DDE_DISABLED = 0x80004016L,

    //
    // MessageId: CO_E_RUNAS_SYNTAX
    //
    // MessageText:
    //
    // A RunAs specification must be <domain name>\<user name> or simply <user name>
    //
    CO_E_RUNAS_SYNTAX = 0x80004017L,

    //
    // MessageId: CO_E_CREATEPROCESS_FAILURE
    //
    // MessageText:
    //
    // The server process could not be started. The pathname may be incorrect.
    //
    CO_E_CREATEPROCESS_FAILURE = 0x80004018L,

    //
    // MessageId: CO_E_RUNAS_CREATEPROCESS_FAILURE
    //
    // MessageText:
    //
    // The server process could not be started as the configured identity. The pathname may be incorrect or unavailable.
    //
    CO_E_RUNAS_CREATEPROCESS_FAILURE = 0x80004019L,

    //
    // MessageId: CO_E_RUNAS_LOGON_FAILURE
    //
    // MessageText:
    //
    // The server process could not be started because the configured identity is incorrect. Check the username and password.
    //
    CO_E_RUNAS_LOGON_FAILURE = 0x8000401AL,

    //
    // MessageId: CO_E_LAUNCH_PERMSSION_DENIED
    //
    // MessageText:
    //
    // The client is not allowed to launch this server.
    //
    CO_E_LAUNCH_PERMSSION_DENIED = 0x8000401BL,

    //
    // MessageId: CO_E_START_SERVICE_FAILURE
    //
    // MessageText:
    //
    // The service providing this server could not be started.
    //
    CO_E_START_SERVICE_FAILURE = 0x8000401CL,

    //
    // MessageId: CO_E_REMOTE_COMMUNICATION_FAILURE
    //
    // MessageText:
    //
    // This computer was unable to communicate with the computer providing the server.
    //
    CO_E_REMOTE_COMMUNICATION_FAILURE = 0x8000401DL,

    //
    // MessageId: CO_E_SERVER_START_TIMEOUT
    //
    // MessageText:
    //
    // The server did not respond after being launched.
    //
    CO_E_SERVER_START_TIMEOUT = 0x8000401EL,

    //
    // MessageId: CO_E_CLSREG_INCONSISTENT
    //
    // MessageText:
    //
    // The registration information for this server is inconsistent or incomplete.
    //
    CO_E_CLSREG_INCONSISTENT = 0x8000401FL,

    //
    // MessageId: CO_E_IIDREG_INCONSISTENT
    //
    // MessageText:
    //
    // The registration information for this interface is inconsistent or incomplete.
    //
    CO_E_IIDREG_INCONSISTENT = 0x80004020L,

    //
    // MessageId: CO_E_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The operation attempted is not supported.
    //
    CO_E_NOT_SUPPORTED = 0x80004021L,

    //
    // MessageId: CO_E_RELOAD_DLL
    //
    // MessageText:
    //
    // A dll must be loaded.
    //
    CO_E_RELOAD_DLL = 0x80004022L,

    //
    // MessageId: CO_E_MSI_ERROR
    //
    // MessageText:
    //
    // A Microsoft Software Installer error was encountered.
    //
    CO_E_MSI_ERROR = 0x80004023L,

    //
    // MessageId: CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT
    //
    // MessageText:
    //
    // The specified activation could not occur in the client context as specified.
    //
    CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT = 0x80004024L,

    //
    // MessageId: CO_E_SERVER_PAUSED
    //
    // MessageText:
    //
    // Activations on the server are paused.
    //
    CO_E_SERVER_PAUSED = 0x80004025L,

    //
    // MessageId: CO_E_SERVER_NOT_PAUSED
    //
    // MessageText:
    //
    // Activations on the server are not paused.
    //
    CO_E_SERVER_NOT_PAUSED = 0x80004026L,

    //
    // MessageId: CO_E_CLASS_DISABLED
    //
    // MessageText:
    //
    // The component or application containing the component has been disabled.
    //
    CO_E_CLASS_DISABLED = 0x80004027L,

    //
    // MessageId: CO_E_CLRNOTAVAILABLE
    //
    // MessageText:
    //
    // The common language runtime is not available
    //
    CO_E_CLRNOTAVAILABLE = 0x80004028L,

    //
    // MessageId: CO_E_ASYNC_WORK_REJECTED
    //
    // MessageText:
    //
    // The thread-pool rejected the submitted asynchronous work.
    //
    CO_E_ASYNC_WORK_REJECTED = 0x80004029L,

    //
    // MessageId: CO_E_SERVER_INIT_TIMEOUT
    //
    // MessageText:
    //
    // The server started, but did not finish initializing in a timely fashion.
    //
    CO_E_SERVER_INIT_TIMEOUT = 0x8000402AL,

    //
    // MessageId: CO_E_NO_SECCTX_IN_ACTIVATE
    //
    // MessageText:
    //
    // Unable to complete the call since there is no COM+ security context inside IObjectControl.Activate.
    //
    CO_E_NO_SECCTX_IN_ACTIVATE = 0x8000402BL,

    //
    // MessageId: CO_E_TRACKER_CONFIG
    //
    // MessageText:
    //
    // The provided tracker configuration is invalid
    //
    CO_E_TRACKER_CONFIG = 0x80004030L,

    //
    // MessageId: CO_E_THREADPOOL_CONFIG
    //
    // MessageText:
    //
    // The provided thread pool configuration is invalid
    //
    CO_E_THREADPOOL_CONFIG = 0x80004031L,

    //
    // MessageId: CO_E_SXS_CONFIG
    //
    // MessageText:
    //
    // The provided side-by-side configuration is invalid
    //
    CO_E_SXS_CONFIG = 0x80004032L,

    //
    // MessageId: CO_E_MALFORMED_SPN
    //
    // MessageText:
    //
    // The server principal name (SPN) obtained during security negotiation is malformed.
    //
    CO_E_MALFORMED_SPN = 0x80004033L,

    //
    // MessageId: CO_E_UNREVOKED_REGISTRATION_ON_APARTMENT_SHUTDOWN
    //
    // MessageText:
    //
    // The caller failed to revoke a per-apartment registration before apartment shutdown.
    //
    CO_E_UNREVOKED_REGISTRATION_ON_APARTMENT_SHUTDOWN = 0x80004034L,

    //
    // MessageId: CO_E_PREMATURE_STUB_RUNDOWN
    //
    // MessageText:
    //
    // The object has been rundown by the stub manager while there are external clients.
    //
    CO_E_PREMATURE_STUB_RUNDOWN = 0x80004035L,

    //
    // Generic OLE errors that may be returned by many inerfaces
    //
    OLE_E_FIRST = 0x80040000L,
    OLE_E_LAST = 0x800400FFL,
    OLE_S_FIRST = 0x00040000L,
    OLE_S_LAST = 0x000400FFL,

    //
    // Old OLE errors
    //
    //
    // MessageId: OLE_E_OLEVERB
    //
    // MessageText:
    //
    // Invalid OLEVERB structure
    //
    OLE_E_OLEVERB = 0x80040000L,

    //
    // MessageId: OLE_E_ADVF
    //
    // MessageText:
    //
    // Invalid advise flags
    //
    OLE_E_ADVF = 0x80040001L,

    //
    // MessageId: OLE_E_ENUM_NOMORE
    //
    // MessageText:
    //
    // Can't enumerate any more, because the associated data is missing
    //
    OLE_E_ENUM_NOMORE = 0x80040002L,

    //
    // MessageId: OLE_E_ADVISENOTSUPPORTED
    //
    // MessageText:
    //
    // This implementation doesn't take advises
    //
    OLE_E_ADVISENOTSUPPORTED = 0x80040003L,

    //
    // MessageId: OLE_E_NOCONNECTION
    //
    // MessageText:
    //
    // There is no connection for this connection ID
    //
    OLE_E_NOCONNECTION = 0x80040004L,

    //
    // MessageId: OLE_E_NOTRUNNING
    //
    // MessageText:
    //
    // Need to run the object to perform this operation
    //
    OLE_E_NOTRUNNING = 0x80040005L,

    //
    // MessageId: OLE_E_NOCACHE
    //
    // MessageText:
    //
    // There is no cache to operate on
    //
    OLE_E_NOCACHE = 0x80040006L,

    //
    // MessageId: OLE_E_BLANK
    //
    // MessageText:
    //
    // Uninitialized object
    //
    OLE_E_BLANK = 0x80040007L,

    //
    // MessageId: OLE_E_CLASSDIFF
    //
    // MessageText:
    //
    // Linked object's source class has changed
    //
    OLE_E_CLASSDIFF = 0x80040008L,

    //
    // MessageId: OLE_E_CANT_GETMONIKER
    //
    // MessageText:
    //
    // Not able to get the moniker of the object
    //
    OLE_E_CANT_GETMONIKER = 0x80040009L,

    //
    // MessageId: OLE_E_CANT_BINDTOSOURCE
    //
    // MessageText:
    //
    // Not able to bind to the source
    //
    OLE_E_CANT_BINDTOSOURCE = 0x8004000AL,

    //
    // MessageId: OLE_E_STATIC
    //
    // MessageText:
    //
    // Object is static; operation not allowed
    //
    OLE_E_STATIC = 0x8004000BL,

    //
    // MessageId: OLE_E_PROMPTSAVECANCELLED
    //
    // MessageText:
    //
    // User canceled out of save dialog
    //
    OLE_E_PROMPTSAVECANCELLED = 0x8004000CL,

    //
    // MessageId: OLE_E_INVALIDRECT
    //
    // MessageText:
    //
    // Invalid rectangle
    //
    OLE_E_INVALIDRECT = 0x8004000DL,

    //
    // MessageId: OLE_E_WRONGCOMPOBJ
    //
    // MessageText:
    //
    // compobj.dll is too old for the ole2.dll initialized
    //
    OLE_E_WRONGCOMPOBJ = 0x8004000EL,

    //
    // MessageId: OLE_E_INVALIDHWND
    //
    // MessageText:
    //
    // Invalid window handle
    //
    OLE_E_INVALIDHWND = 0x8004000FL,

    //
    // MessageId: OLE_E_NOT_INPLACEACTIVE
    //
    // MessageText:
    //
    // Object is not in any of the inplace active states
    //
    OLE_E_NOT_INPLACEACTIVE = 0x80040010L,

    //
    // MessageId: OLE_E_CANTCONVERT
    //
    // MessageText:
    //
    // Not able to convert object
    //
    OLE_E_CANTCONVERT = 0x80040011L,

    //
    // MessageId: OLE_E_NOSTORAGE
    //
    // MessageText:
    //
    // Not able to perform the operation because object is not given storage yet
    //
    OLE_E_NOSTORAGE = 0x80040012L,

    //
    // MessageId: DV_E_FORMATETC
    //
    // MessageText:
    //
    // Invalid FORMATETC structure
    //
    DV_E_FORMATETC = 0x80040064L,

    //
    // MessageId: DV_E_DVTARGETDEVICE
    //
    // MessageText:
    //
    // Invalid DVTARGETDEVICE structure
    //
    DV_E_DVTARGETDEVICE = 0x80040065L,

    //
    // MessageId: DV_E_STGMEDIUM
    //
    // MessageText:
    //
    // Invalid STDGMEDIUM structure
    //
    DV_E_STGMEDIUM = 0x80040066L,

    //
    // MessageId: DV_E_STATDATA
    //
    // MessageText:
    //
    // Invalid STATDATA structure
    //
    DV_E_STATDATA = 0x80040067L,

    //
    // MessageId: DV_E_LINDEX
    //
    // MessageText:
    //
    // Invalid lindex
    //
    DV_E_LINDEX = 0x80040068L,

    //
    // MessageId: DV_E_TYMED
    //
    // MessageText:
    //
    // Invalid tymed
    //
    DV_E_TYMED = 0x80040069L,

    //
    // MessageId: DV_E_CLIPFORMAT
    //
    // MessageText:
    //
    // Invalid clipboard format
    //
    DV_E_CLIPFORMAT = 0x8004006AL,

    //
    // MessageId: DV_E_DVASPECT
    //
    // MessageText:
    //
    // Invalid aspect(s)
    //
    DV_E_DVASPECT = 0x8004006BL,

    //
    // MessageId: DV_E_DVTARGETDEVICE_SIZE
    //
    // MessageText:
    //
    // tdSize parameter of the DVTARGETDEVICE structure is invalid
    //
    DV_E_DVTARGETDEVICE_SIZE = 0x8004006CL,

    //
    // MessageId: DV_E_NOIVIEWOBJECT
    //
    // MessageText:
    //
    // Object doesn't support IViewObject interface
    //
    DV_E_NOIVIEWOBJECT = 0x8004006DL,

    DRAGDROP_E_FIRST = 0x80040100L,
    DRAGDROP_E_LAST = 0x8004010FL,
    DRAGDROP_S_FIRST = 0x00040100L,
    DRAGDROP_S_LAST = 0x0004010FL,

    //
    // MessageId: DRAGDROP_E_NOTREGISTERED
    //
    // MessageText:
    //
    // Trying to revoke a drop target that has not been registered
    //
    DRAGDROP_E_NOTREGISTERED = 0x80040100L,

    //
    // MessageId: DRAGDROP_E_ALREADYREGISTERED
    //
    // MessageText:
    //
    // This window has already been registered as a drop target
    //
    DRAGDROP_E_ALREADYREGISTERED = 0x80040101L,

    //
    // MessageId: DRAGDROP_E_INVALIDHWND
    //
    // MessageText:
    //
    // Invalid window handle
    //
    DRAGDROP_E_INVALIDHWND = 0x80040102L,

    //
    // MessageId: DRAGDROP_E_CONCURRENT_DRAG_ATTEMPTED
    //
    // MessageText:
    //
    // A drag operation is already in progress
    //
    DRAGDROP_E_CONCURRENT_DRAG_ATTEMPTED = 0x80040103L,

    CLASSFACTORY_E_FIRST = 0x80040110L,
    CLASSFACTORY_E_LAST = 0x8004011FL,
    CLASSFACTORY_S_FIRST = 0x00040110L,
    CLASSFACTORY_S_LAST = 0x0004011FL,

    //
    // MessageId: CLASS_E_NOAGGREGATION
    //
    // MessageText:
    //
    // Class does not support aggregation (or class object is remote)
    //
    CLASS_E_NOAGGREGATION = 0x80040110L,

    //
    // MessageId: CLASS_E_CLASSNOTAVAILABLE
    //
    // MessageText:
    //
    // ClassFactory cannot supply requested class
    //
    CLASS_E_CLASSNOTAVAILABLE = 0x80040111L,

    //
    // MessageId: CLASS_E_NOTLICENSED
    //
    // MessageText:
    //
    // Class is not licensed for use
    //
    CLASS_E_NOTLICENSED = 0x80040112L,

    MARSHAL_E_FIRST = 0x80040120L,
    MARSHAL_E_LAST = 0x8004012FL,
    MARSHAL_S_FIRST = 0x00040120L,
    MARSHAL_S_LAST = 0x0004012FL,
    DATA_E_FIRST = 0x80040130L,
    DATA_E_LAST = 0x8004013FL,
    DATA_S_FIRST = 0x00040130L,
    DATA_S_LAST = 0x0004013FL,
    VIEW_E_FIRST = 0x80040140L,
    VIEW_E_LAST = 0x8004014FL,
    VIEW_S_FIRST = 0x00040140L,
    VIEW_S_LAST = 0x0004014FL,

    //
    // MessageId: VIEW_E_DRAW
    //
    // MessageText:
    //
    // Error drawing view
    //
    VIEW_E_DRAW = 0x80040140L,

    REGDB_E_FIRST = 0x80040150L,
    REGDB_E_LAST = 0x8004015FL,
    REGDB_S_FIRST = 0x00040150L,
    REGDB_S_LAST = 0x0004015FL,

    //
    // MessageId: REGDB_E_READREGDB
    //
    // MessageText:
    //
    // Could not read key from registry
    //
    REGDB_E_READREGDB = 0x80040150L,

    //
    // MessageId: REGDB_E_WRITEREGDB
    //
    // MessageText:
    //
    // Could not write key to registry
    //
    REGDB_E_WRITEREGDB = 0x80040151L,

    //
    // MessageId: REGDB_E_KEYMISSING
    //
    // MessageText:
    //
    // Could not find the key in the registry
    //
    REGDB_E_KEYMISSING = 0x80040152L,

    //
    // MessageId: REGDB_E_INVALIDVALUE
    //
    // MessageText:
    //
    // Invalid value for registry
    //
    REGDB_E_INVALIDVALUE = 0x80040153L,

    //
    // MessageId: REGDB_E_CLASSNOTREG
    //
    // MessageText:
    //
    // Class not registered
    //
    REGDB_E_CLASSNOTREG = 0x80040154L,

    //
    // MessageId: REGDB_E_IIDNOTREG
    //
    // MessageText:
    //
    // Interface not registered
    //
    REGDB_E_IIDNOTREG = 0x80040155L,

    //
    // MessageId: REGDB_E_BADTHREADINGMODEL
    //
    // MessageText:
    //
    // Threading model entry is not valid
    //
    REGDB_E_BADTHREADINGMODEL = 0x80040156L,

    CAT_E_FIRST = 0x80040160L,
    CAT_E_LAST = 0x80040161L,

    //
    // MessageId: CAT_E_CATIDNOEXIST
    //
    // MessageText:
    //
    // CATID does not exist
    //
    CAT_E_CATIDNOEXIST = 0x80040160L,

    //
    // MessageId: CAT_E_NODESCRIPTION
    //
    // MessageText:
    //
    // Description not found
    //
    CAT_E_NODESCRIPTION = 0x80040161L,

    ////////////////////////////////////
    //                                //
    //     Class Store Error Codes    //
    //                                //
    ////////////////////////////////////
    CS_E_FIRST = 0x80040164L,
    CS_E_LAST = 0x8004016FL,

    //
    // MessageId: CS_E_PACKAGE_NOTFOUND
    //
    // MessageText:
    //
    // No package in the software installation data in the Active Directory meets this criteria.
    //
    CS_E_PACKAGE_NOTFOUND = 0x80040164L,

    //
    // MessageId: CS_E_NOT_DELETABLE
    //
    // MessageText:
    //
    // Deleting this will break the referential integrity of the software installation data in the Active Directory.
    //
    CS_E_NOT_DELETABLE = 0x80040165L,

    //
    // MessageId: CS_E_CLASS_NOTFOUND
    //
    // MessageText:
    //
    // The CLSID was not found in the software installation data in the Active Directory.
    //
    CS_E_CLASS_NOTFOUND = 0x80040166L,

    //
    // MessageId: CS_E_INVALID_VERSION
    //
    // MessageText:
    //
    // The software installation data in the Active Directory is corrupt.
    //
    CS_E_INVALID_VERSION = 0x80040167L,

    //
    // MessageId: CS_E_NO_CLASSSTORE
    //
    // MessageText:
    //
    // There is no software installation data in the Active Directory.
    //
    CS_E_NO_CLASSSTORE = 0x80040168L,

    //
    // MessageId: CS_E_OBJECT_NOTFOUND
    //
    // MessageText:
    //
    // There is no software installation data object in the Active Directory.
    //
    CS_E_OBJECT_NOTFOUND = 0x80040169L,

    //
    // MessageId: CS_E_OBJECT_ALREADY_EXISTS
    //
    // MessageText:
    //
    // The software installation data object in the Active Directory already exists.
    //
    CS_E_OBJECT_ALREADY_EXISTS = 0x8004016AL,

    //
    // MessageId: CS_E_INVALID_PATH
    //
    // MessageText:
    //
    // The path to the software installation data in the Active Directory is not correct.
    //
    CS_E_INVALID_PATH = 0x8004016BL,

    //
    // MessageId: CS_E_NETWORK_ERROR
    //
    // MessageText:
    //
    // A network error interrupted the operation.
    //
    CS_E_NETWORK_ERROR = 0x8004016CL,

    //
    // MessageId: CS_E_ADMIN_LIMIT_EXCEEDED
    //
    // MessageText:
    //
    // The size of this object exceeds the maximum size set by the Administrator.
    //
    CS_E_ADMIN_LIMIT_EXCEEDED = 0x8004016DL,

    //
    // MessageId: CS_E_SCHEMA_MISMATCH
    //
    // MessageText:
    //
    // The schema for the software installation data in the Active Directory does not match the required schema.
    //
    CS_E_SCHEMA_MISMATCH = 0x8004016EL,

    //
    // MessageId: CS_E_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An error occurred in the software installation data in the Active Directory.
    //
    CS_E_INTERNAL_ERROR = 0x8004016FL,

    CACHE_E_FIRST = 0x80040170L,
    CACHE_E_LAST = 0x8004017FL,
    CACHE_S_FIRST = 0x00040170L,
    CACHE_S_LAST = 0x0004017FL,

    //
    // MessageId: CACHE_E_NOCACHE_UPDATED
    //
    // MessageText:
    //
    // Cache not updated
    //
    CACHE_E_NOCACHE_UPDATED = 0x80040170L,

    OLEOBJ_E_FIRST = 0x80040180L,
    OLEOBJ_E_LAST = 0x8004018FL,
    OLEOBJ_S_FIRST = 0x00040180L,
    OLEOBJ_S_LAST = 0x0004018FL,
    //
    // MessageId: OLEOBJ_E_NOVERBS
    //
    // MessageText:
    //
    // No verbs for OLE object
    //
    OLEOBJ_E_NOVERBS = 0x80040180L,

    //
    // MessageId: OLEOBJ_E_INVALIDVERB
    //
    // MessageText:
    //
    // Invalid verb for OLE object
    //
    OLEOBJ_E_INVALIDVERB = 0x80040181L,

    CLIENTSITE_E_FIRST = 0x80040190L,
    CLIENTSITE_E_LAST = 0x8004019FL,
    CLIENTSITE_S_FIRST = 0x00040190L,
    CLIENTSITE_S_LAST = 0x0004019FL,
    //
    // MessageId: INPLACE_E_NOTUNDOABLE
    //
    // MessageText:
    //
    // Undo is not available
    //
    INPLACE_E_NOTUNDOABLE = 0x800401A0L,

    //
    // MessageId: INPLACE_E_NOTOOLSPACE
    //
    // MessageText:
    //
    // Space for tools is not available
    //
    INPLACE_E_NOTOOLSPACE = 0x800401A1L,

    INPLACE_E_FIRST = 0x800401A0L,
    INPLACE_E_LAST = 0x800401AFL,
    INPLACE_S_FIRST = 0x000401A0L,
    INPLACE_S_LAST = 0x000401AFL,
    ENUM_E_FIRST = 0x800401B0L,
    ENUM_E_LAST = 0x800401BFL,
    ENUM_S_FIRST = 0x000401B0L,
    ENUM_S_LAST = 0x000401BFL,
    CONVERT10_E_FIRST = 0x800401C0L,
    CONVERT10_E_LAST = 0x800401CFL,
    CONVERT10_S_FIRST = 0x000401C0L,
    CONVERT10_S_LAST = 0x000401CFL,

    //
    // MessageId: CONVERT10_E_OLESTREAM_GET
    //
    // MessageText:
    //
    // OLESTREAM Get method failed
    //
    CONVERT10_E_OLESTREAM_GET = 0x800401C0L,

    //
    // MessageId: CONVERT10_E_OLESTREAM_PUT
    //
    // MessageText:
    //
    // OLESTREAM Put method failed
    //
    CONVERT10_E_OLESTREAM_PUT = 0x800401C1L,

    //
    // MessageId: CONVERT10_E_OLESTREAM_FMT
    //
    // MessageText:
    //
    // Contents of the OLESTREAM not in correct format
    //
    CONVERT10_E_OLESTREAM_FMT = 0x800401C2L,

    //
    // MessageId: CONVERT10_E_OLESTREAM_BITMAP_TO_DIB
    //
    // MessageText:
    //
    // There was an error in a Windows GDI call while converting the bitmap to a DIB
    //
    CONVERT10_E_OLESTREAM_BITMAP_TO_DIB = 0x800401C3L,

    //
    // MessageId: CONVERT10_E_STG_FMT
    //
    // MessageText:
    //
    // Contents of the IStorage not in correct format
    //
    CONVERT10_E_STG_FMT = 0x800401C4L,

    //
    // MessageId: CONVERT10_E_STG_NO_STD_STREAM
    //
    // MessageText:
    //
    // Contents of IStorage is missing one of the standard streams
    //
    CONVERT10_E_STG_NO_STD_STREAM = 0x800401C5L,

    //
    // MessageId: CONVERT10_E_STG_DIB_TO_BITMAP
    //
    // MessageText:
    //
    // There was an error in a Windows GDI call while converting the DIB to a bitmap.
    //
    CONVERT10_E_STG_DIB_TO_BITMAP = 0x800401C6L,

    CLIPBRD_E_FIRST = 0x800401D0L,
    CLIPBRD_E_LAST = 0x800401DFL,
    CLIPBRD_S_FIRST = 0x000401D0L,
    CLIPBRD_S_LAST = 0x000401DFL,
    //
    // MessageId: CLIPBRD_E_CANT_OPEN
    //
    // MessageText:
    //
    // OpenClipboard Failed
    //
    CLIPBRD_E_CANT_OPEN = 0x800401D0L,

    //
    // MessageId: CLIPBRD_E_CANT_EMPTY
    //
    // MessageText:
    //
    // EmptyClipboard Failed
    //
    CLIPBRD_E_CANT_EMPTY = 0x800401D1L,

    //
    // MessageId: CLIPBRD_E_CANT_SET
    //
    // MessageText:
    //
    // SetClipboard Failed
    //
    CLIPBRD_E_CANT_SET = 0x800401D2L,

    //
    // MessageId: CLIPBRD_E_BAD_DATA
    //
    // MessageText:
    //
    // Data on clipboard is invalid
    //
    CLIPBRD_E_BAD_DATA = 0x800401D3L,

    //
    // MessageId: CLIPBRD_E_CANT_CLOSE
    //
    // MessageText:
    //
    // CloseClipboard Failed
    //
    CLIPBRD_E_CANT_CLOSE = 0x800401D4L,

    MK_E_FIRST = 0x800401E0L,
    MK_E_LAST = 0x800401EFL,
    MK_S_FIRST = 0x000401E0L,
    MK_S_LAST = 0x000401EFL,
    //
    // MessageId: MK_E_CONNECTMANUALLY
    //
    // MessageText:
    //
    // Moniker needs to be connected manually
    //
    MK_E_CONNECTMANUALLY = 0x800401E0L,

    //
    // MessageId: MK_E_EXCEEDEDDEADLINE
    //
    // MessageText:
    //
    // Operation exceeded deadline
    //
    MK_E_EXCEEDEDDEADLINE = 0x800401E1L,

    //
    // MessageId: MK_E_NEEDGENERIC
    //
    // MessageText:
    //
    // Moniker needs to be generic
    //
    MK_E_NEEDGENERIC = 0x800401E2L,

    //
    // MessageId: MK_E_UNAVAILABLE
    //
    // MessageText:
    //
    // Operation unavailable
    //
    MK_E_UNAVAILABLE = 0x800401E3L,

    //
    // MessageId: MK_E_SYNTAX
    //
    // MessageText:
    //
    // Invalid syntax
    //
    MK_E_SYNTAX = 0x800401E4L,

    //
    // MessageId: MK_E_NOOBJECT
    //
    // MessageText:
    //
    // No object for moniker
    //
    MK_E_NOOBJECT = 0x800401E5L,

    //
    // MessageId: MK_E_INVALIDEXTENSION
    //
    // MessageText:
    //
    // Bad extension for file
    //
    MK_E_INVALIDEXTENSION = 0x800401E6L,

    //
    // MessageId: MK_E_INTERMEDIATEINTERFACENOTSUPPORTED
    //
    // MessageText:
    //
    // Intermediate operation failed
    //
    MK_E_INTERMEDIATEINTERFACENOTSUPPORTED = 0x800401E7L,

    //
    // MessageId: MK_E_NOTBINDABLE
    //
    // MessageText:
    //
    // Moniker is not bindable
    //
    MK_E_NOTBINDABLE = 0x800401E8L,

    //
    // MessageId: MK_E_NOTBOUND
    //
    // MessageText:
    //
    // Moniker is not bound
    //
    MK_E_NOTBOUND = 0x800401E9L,

    //
    // MessageId: MK_E_CANTOPENFILE
    //
    // MessageText:
    //
    // Moniker cannot open file
    //
    MK_E_CANTOPENFILE = 0x800401EAL,

    //
    // MessageId: MK_E_MUSTBOTHERUSER
    //
    // MessageText:
    //
    // User input required for operation to succeed
    //
    MK_E_MUSTBOTHERUSER = 0x800401EBL,

    //
    // MessageId: MK_E_NOINVERSE
    //
    // MessageText:
    //
    // Moniker class has no inverse
    //
    MK_E_NOINVERSE = 0x800401ECL,

    //
    // MessageId: MK_E_NOSTORAGE
    //
    // MessageText:
    //
    // Moniker does not refer to storage
    //
    MK_E_NOSTORAGE = 0x800401EDL,

    //
    // MessageId: MK_E_NOPREFIX
    //
    // MessageText:
    //
    // No common prefix
    //
    MK_E_NOPREFIX = 0x800401EEL,

    //
    // MessageId: MK_E_ENUMERATION_FAILED
    //
    // MessageText:
    //
    // Moniker could not be enumerated
    //
    MK_E_ENUMERATION_FAILED = 0x800401EFL,

    CO_E_FIRST = 0x800401F0L,
    CO_E_LAST = 0x800401FFL,
    CO_S_FIRST = 0x000401F0L,
    CO_S_LAST = 0x000401FFL,
    //
    // MessageId: CO_E_NOTINITIALIZED
    //
    // MessageText:
    //
    // CoInitialize has not been called.
    //
    CO_E_NOTINITIALIZED = 0x800401F0L,

    //
    // MessageId: CO_E_ALREADYINITIALIZED
    //
    // MessageText:
    //
    // CoInitialize has already been called.
    //
    CO_E_ALREADYINITIALIZED = 0x800401F1L,

    //
    // MessageId: CO_E_CANTDETERMINECLASS
    //
    // MessageText:
    //
    // Class of object cannot be determined
    //
    CO_E_CANTDETERMINECLASS = 0x800401F2L,

    //
    // MessageId: CO_E_CLASSSTRING
    //
    // MessageText:
    //
    // Invalid class string
    //
    CO_E_CLASSSTRING = 0x800401F3L,

    //
    // MessageId: CO_E_IIDSTRING
    //
    // MessageText:
    //
    // Invalid interface string
    //
    CO_E_IIDSTRING = 0x800401F4L,

    //
    // MessageId: CO_E_APPNOTFOUND
    //
    // MessageText:
    //
    // Application not found
    //
    CO_E_APPNOTFOUND = 0x800401F5L,

    //
    // MessageId: CO_E_APPSINGLEUSE
    //
    // MessageText:
    //
    // Application cannot be run more than once
    //
    CO_E_APPSINGLEUSE = 0x800401F6L,

    //
    // MessageId: CO_E_ERRORINAPP
    //
    // MessageText:
    //
    // Some error in application program
    //
    CO_E_ERRORINAPP = 0x800401F7L,

    //
    // MessageId: CO_E_DLLNOTFOUND
    //
    // MessageText:
    //
    // DLL for class not found
    //
    CO_E_DLLNOTFOUND = 0x800401F8L,

    //
    // MessageId: CO_E_ERRORINDLL
    //
    // MessageText:
    //
    // Error in the DLL
    //
    CO_E_ERRORINDLL = 0x800401F9L,

    //
    // MessageId: CO_E_WRONGOSFORAPP
    //
    // MessageText:
    //
    // Wrong OS or OS version for application
    //
    CO_E_WRONGOSFORAPP = 0x800401FAL,

    //
    // MessageId: CO_E_OBJNOTREG
    //
    // MessageText:
    //
    // Object is not registered
    //
    CO_E_OBJNOTREG = 0x800401FBL,

    //
    // MessageId: CO_E_OBJISREG
    //
    // MessageText:
    //
    // Object is already registered
    //
    CO_E_OBJISREG = 0x800401FCL,

    //
    // MessageId: CO_E_OBJNOTCONNECTED
    //
    // MessageText:
    //
    // Object is not connected to server
    //
    CO_E_OBJNOTCONNECTED = 0x800401FDL,

    //
    // MessageId: CO_E_APPDIDNTREG
    //
    // MessageText:
    //
    // Application was launched but it didn't register a class factory
    //
    CO_E_APPDIDNTREG = 0x800401FEL,

    //
    // MessageId: CO_E_RELEASED
    //
    // MessageText:
    //
    // Object has been released
    //
    CO_E_RELEASED = 0x800401FFL,

    EVENT_E_FIRST = 0x80040200L,
    EVENT_E_LAST = 0x8004021FL,
    EVENT_S_FIRST = 0x00040200L,
    EVENT_S_LAST = 0x0004021FL,
    //
    // MessageId: EVENT_S_SOME_SUBSCRIBERS_FAILED
    //
    // MessageText:
    //
    // An event was able to invoke some but not all of the subscribers
    //
    EVENT_S_SOME_SUBSCRIBERS_FAILED = 0x00040200L,

    //
    // MessageId: EVENT_E_ALL_SUBSCRIBERS_FAILED
    //
    // MessageText:
    //
    // An event was unable to invoke any of the subscribers
    //
    EVENT_E_ALL_SUBSCRIBERS_FAILED = 0x80040201L,

    //
    // MessageId: EVENT_S_NOSUBSCRIBERS
    //
    // MessageText:
    //
    // An event was delivered but there were no subscribers
    //
    EVENT_S_NOSUBSCRIBERS = 0x00040202L,

    //
    // MessageId: EVENT_E_QUERYSYNTAX
    //
    // MessageText:
    //
    // A syntax error occurred trying to evaluate a query string
    //
    EVENT_E_QUERYSYNTAX = 0x80040203L,

    //
    // MessageId: EVENT_E_QUERYFIELD
    //
    // MessageText:
    //
    // An invalid field name was used in a query string
    //
    EVENT_E_QUERYFIELD = 0x80040204L,

    //
    // MessageId: EVENT_E_INTERNALEXCEPTION
    //
    // MessageText:
    //
    // An unexpected exception was raised
    //
    EVENT_E_INTERNALEXCEPTION = 0x80040205L,

    //
    // MessageId: EVENT_E_INTERNALERROR
    //
    // MessageText:
    //
    // An unexpected internal error was detected
    //
    EVENT_E_INTERNALERROR = 0x80040206L,

    //
    // MessageId: EVENT_E_INVALID_PER_USER_SID
    //
    // MessageText:
    //
    // The owner SID on a per-user subscription doesn't exist
    //
    EVENT_E_INVALID_PER_USER_SID = 0x80040207L,

    //
    // MessageId: EVENT_E_USER_EXCEPTION
    //
    // MessageText:
    //
    // A user-supplied component or subscriber raised an exception
    //
    EVENT_E_USER_EXCEPTION = 0x80040208L,

    //
    // MessageId: EVENT_E_TOO_MANY_METHODS
    //
    // MessageText:
    //
    // An interface has too many methods to fire events from
    //
    EVENT_E_TOO_MANY_METHODS = 0x80040209L,

    //
    // MessageId: EVENT_E_MISSING_EVENTCLASS
    //
    // MessageText:
    //
    // A subscription cannot be stored unless its event class already exists
    //
    EVENT_E_MISSING_EVENTCLASS = 0x8004020AL,

    //
    // MessageId: EVENT_E_NOT_ALL_REMOVED
    //
    // MessageText:
    //
    // Not all the objects requested could be removed
    //
    EVENT_E_NOT_ALL_REMOVED = 0x8004020BL,

    //
    // MessageId: EVENT_E_COMPLUS_NOT_INSTALLED
    //
    // MessageText:
    //
    // COM+ is required for this operation, but is not installed
    //
    EVENT_E_COMPLUS_NOT_INSTALLED = 0x8004020CL,

    //
    // MessageId: EVENT_E_CANT_MODIFY_OR_DELETE_UNCONFIGURED_OBJECT
    //
    // MessageText:
    //
    // Cannot modify or delete an object that was not added using the COM+ Admin SDK
    //
    EVENT_E_CANT_MODIFY_OR_DELETE_UNCONFIGURED_OBJECT = 0x8004020DL,

    //
    // MessageId: EVENT_E_CANT_MODIFY_OR_DELETE_CONFIGURED_OBJECT
    //
    // MessageText:
    //
    // Cannot modify or delete an object that was added using the COM+ Admin SDK
    //
    EVENT_E_CANT_MODIFY_OR_DELETE_CONFIGURED_OBJECT = 0x8004020EL,

    //
    // MessageId: EVENT_E_INVALID_EVENT_CLASS_PARTITION
    //
    // MessageText:
    //
    // The event class for this subscription is in an invalid partition
    //
    EVENT_E_INVALID_EVENT_CLASS_PARTITION = 0x8004020FL,

    //
    // MessageId: EVENT_E_PER_USER_SID_NOT_LOGGED_ON
    //
    // MessageText:
    //
    // The owner of the PerUser subscription is not logged on to the system specified
    //
    EVENT_E_PER_USER_SID_NOT_LOGGED_ON = 0x80040210L,

    //
    // MessageId: TPC_E_INVALID_PROPERTY
    //
    // MessageText:
    //
    // TabletPC inking error code. The property was not found, or supported by the recognizer
    //
    TPC_E_INVALID_PROPERTY = 0x80040241L,

    //
    // MessageId: TPC_E_NO_DEFAULT_TABLET
    //
    // MessageText:
    //
    // TabletPC inking error code. No default tablet
    //
    TPC_E_NO_DEFAULT_TABLET = 0x80040212L,

    //
    // MessageId: TPC_E_UNKNOWN_PROPERTY
    //
    // MessageText:
    //
    // TabletPC inking error code. Unknown property specified
    //
    TPC_E_UNKNOWN_PROPERTY = 0x8004021BL,

    //
    // MessageId: TPC_E_INVALID_INPUT_RECT
    //
    // MessageText:
    //
    // TabletPC inking error code. An invalid input rectangle was specified
    //
    TPC_E_INVALID_INPUT_RECT = 0x80040219L,

    //
    // MessageId: TPC_E_INVALID_STROKE
    //
    // MessageText:
    //
    // TabletPC inking error code. The stroke object was deleted
    //
    TPC_E_INVALID_STROKE = 0x80040222L,

    //
    // MessageId: TPC_E_INITIALIZE_FAIL
    //
    // MessageText:
    //
    // TabletPC inking error code. Initialization failure
    //
    TPC_E_INITIALIZE_FAIL = 0x80040223L,

    //
    // MessageId: TPC_E_NOT_RELEVANT
    //
    // MessageText:
    //
    // TabletPC inking error code. The data required for the operation was not supplied
    //
    TPC_E_NOT_RELEVANT = 0x80040232L,

    //
    // MessageId: TPC_E_INVALID_PACKET_DESCRIPTION
    //
    // MessageText:
    //
    // TabletPC inking error code. Invalid packet description
    //
    TPC_E_INVALID_PACKET_DESCRIPTION = 0x80040233L,

    //
    // MessageId: TPC_E_RECOGNIZER_NOT_REGISTERED
    //
    // MessageText:
    //
    // TabletPC inking error code. There are no handwriting recognizers registered
    //
    TPC_E_RECOGNIZER_NOT_REGISTERED = 0x80040235L,

    //
    // MessageId: TPC_E_INVALID_RIGHTS
    //
    // MessageText:
    //
    // TabletPC inking error code. User does not have the necessary rights to read recognizer information
    //
    TPC_E_INVALID_RIGHTS = 0x80040236L,

    //
    // MessageId: TPC_E_OUT_OF_ORDER_CALL
    //
    // MessageText:
    //
    // TabletPC inking error code. API calls were made in an incorrect order
    //
    TPC_E_OUT_OF_ORDER_CALL = 0x80040237L,

    //
    // MessageId: TPC_E_QUEUE_FULL
    //
    // MessageText:
    //
    // TabletPC inking error code. Queue is full
    //
    TPC_E_QUEUE_FULL = 0x80040238L,

    //
    // MessageId: TPC_E_INVALID_CONFIGURATION
    //
    // MessageText:
    //
    // TabletPC inking error code. RtpEnabled called multiple times
    //
    TPC_E_INVALID_CONFIGURATION = 0x80040239L,

    //
    // MessageId: TPC_E_INVALID_DATA_FROM_RECOGNIZER
    //
    // MessageText:
    //
    // TabletPC inking error code. A recognizer returned invalid data
    //
    TPC_E_INVALID_DATA_FROM_RECOGNIZER = 0x8004023AL,

    //
    // MessageId: TPC_S_TRUNCATED
    //
    // MessageText:
    //
    // TabletPC inking error code. String was truncated
    //
    TPC_S_TRUNCATED = 0x00040252L,

    //
    // MessageId: TPC_S_INTERRUPTED
    //
    // MessageText:
    //
    // TabletPC inking error code. Recognition or training was interrupted
    //
    TPC_S_INTERRUPTED = 0x00040253L,

    //
    // MessageId: TPC_S_NO_DATA_TO_PROCESS
    //
    // MessageText:
    //
    // TabletPC inking error code. No personalization update to the recognizer because no training data found
    //
    TPC_S_NO_DATA_TO_PROCESS = 0x00040254L,

    XACT_E_FIRST = 0x8004D000L,
    XACT_E_LAST = 0x8004D02BL,
    XACT_S_FIRST = 0x0004D000L,
    XACT_S_LAST = 0x0004D010L,

    //
    // MessageId: XACT_E_ALREADYOTHERSINGLEPHASE
    //
    // MessageText:
    //
    // Another single phase resource manager has already been enlisted in this transaction.
    //
    XACT_E_ALREADYOTHERSINGLEPHASE = 0x8004D000L,

    //
    // MessageId: XACT_E_CANTRETAIN
    //
    // MessageText:
    //
    // A retaining commit or abort is not supported
    //
    XACT_E_CANTRETAIN = 0x8004D001L,

    //
    // MessageId: XACT_E_COMMITFAILED
    //
    // MessageText:
    //
    // The transaction failed to commit for an unknown reason. The transaction was aborted.
    //
    XACT_E_COMMITFAILED = 0x8004D002L,

    //
    // MessageId: XACT_E_COMMITPREVENTED
    //
    // MessageText:
    //
    // Cannot call commit on this transaction object because the calling application did not initiate the transaction.
    //
    XACT_E_COMMITPREVENTED = 0x8004D003L,

    //
    // MessageId: XACT_E_HEURISTICABORT
    //
    // MessageText:
    //
    // Instead of committing, the resource heuristically aborted.
    //
    XACT_E_HEURISTICABORT = 0x8004D004L,

    //
    // MessageId: XACT_E_HEURISTICCOMMIT
    //
    // MessageText:
    //
    // Instead of aborting, the resource heuristically committed.
    //
    XACT_E_HEURISTICCOMMIT = 0x8004D005L,

    //
    // MessageId: XACT_E_HEURISTICDAMAGE
    //
    // MessageText:
    //
    // Some of the states of the resource were committed while others were aborted, likely because of heuristic decisions.
    //
    XACT_E_HEURISTICDAMAGE = 0x8004D006L,

    //
    // MessageId: XACT_E_HEURISTICDANGER
    //
    // MessageText:
    //
    // Some of the states of the resource may have been committed while others may have been aborted, likely because of heuristic decisions.
    //
    XACT_E_HEURISTICDANGER = 0x8004D007L,

    //
    // MessageId: XACT_E_ISOLATIONLEVEL
    //
    // MessageText:
    //
    // The requested isolation level is not valid or supported.
    //
    XACT_E_ISOLATIONLEVEL = 0x8004D008L,

    //
    // MessageId: XACT_E_NOASYNC
    //
    // MessageText:
    //
    // The transaction manager doesn't support an asynchronous operation for this method.
    //
    XACT_E_NOASYNC = 0x8004D009L,

    //
    // MessageId: XACT_E_NOENLIST
    //
    // MessageText:
    //
    // Unable to enlist in the transaction.
    //
    XACT_E_NOENLIST = 0x8004D00AL,

    //
    // MessageId: XACT_E_NOISORETAIN
    //
    // MessageText:
    //
    // The requested semantics of retention of isolation across retaining commit and abort boundaries cannot be supported by this transaction implementation, or isoFlags was not equal to zero.
    //
    XACT_E_NOISORETAIN = 0x8004D00BL,

    //
    // MessageId: XACT_E_NORESOURCE
    //
    // MessageText:
    //
    // There is no resource presently associated with this enlistment
    //
    XACT_E_NORESOURCE = 0x8004D00CL,

    //
    // MessageId: XACT_E_NOTCURRENT
    //
    // MessageText:
    //
    // The transaction failed to commit due to the failure of optimistic concurrency control in at least one of the resource managers.
    //
    XACT_E_NOTCURRENT = 0x8004D00DL,

    //
    // MessageId: XACT_E_NOTRANSACTION
    //
    // MessageText:
    //
    // The transaction has already been implicitly or explicitly committed or aborted
    //
    XACT_E_NOTRANSACTION = 0x8004D00EL,

    //
    // MessageId: XACT_E_NOTSUPPORTED
    //
    // MessageText:
    //
    // An invalid combination of flags was specified
    //
    XACT_E_NOTSUPPORTED = 0x8004D00FL,

    //
    // MessageId: XACT_E_UNKNOWNRMGRID
    //
    // MessageText:
    //
    // The resource manager id is not associated with this transaction or the transaction manager.
    //
    XACT_E_UNKNOWNRMGRID = 0x8004D010L,

    //
    // MessageId: XACT_E_WRONGSTATE
    //
    // MessageText:
    //
    // This method was called in the wrong state
    //
    XACT_E_WRONGSTATE = 0x8004D011L,

    //
    // MessageId: XACT_E_WRONGUOW
    //
    // MessageText:
    //
    // The indicated unit of work does not match the unit of work expected by the resource manager.
    //
    XACT_E_WRONGUOW = 0x8004D012L,

    //
    // MessageId: XACT_E_XTIONEXISTS
    //
    // MessageText:
    //
    // An enlistment in a transaction already exists.
    //
    XACT_E_XTIONEXISTS = 0x8004D013L,

    //
    // MessageId: XACT_E_NOIMPORTOBJECT
    //
    // MessageText:
    //
    // An import object for the transaction could not be found.
    //
    XACT_E_NOIMPORTOBJECT = 0x8004D014L,

    //
    // MessageId: XACT_E_INVALIDCOOKIE
    //
    // MessageText:
    //
    // The transaction cookie is invalid.
    //
    XACT_E_INVALIDCOOKIE = 0x8004D015L,

    //
    // MessageId: XACT_E_INDOUBT
    //
    // MessageText:
    //
    // The transaction status is in doubt. A communication failure occurred, or a transaction manager or resource manager has failed
    //
    XACT_E_INDOUBT = 0x8004D016L,

    //
    // MessageId: XACT_E_NOTIMEOUT
    //
    // MessageText:
    //
    // A time-out was specified, but time-outs are not supported.
    //
    XACT_E_NOTIMEOUT = 0x8004D017L,

    //
    // MessageId: XACT_E_ALREADYINPROGRESS
    //
    // MessageText:
    //
    // The requested operation is already in progress for the transaction.
    //
    XACT_E_ALREADYINPROGRESS = 0x8004D018L,

    //
    // MessageId: XACT_E_ABORTED
    //
    // MessageText:
    //
    // The transaction has already been aborted.
    //
    XACT_E_ABORTED = 0x8004D019L,

    //
    // MessageId: XACT_E_LOGFULL
    //
    // MessageText:
    //
    // The Transaction Manager returned a log full error.
    //
    XACT_E_LOGFULL = 0x8004D01AL,

    //
    // MessageId: XACT_E_TMNOTAVAILABLE
    //
    // MessageText:
    //
    // The Transaction Manager is not available.
    //
    XACT_E_TMNOTAVAILABLE = 0x8004D01BL,

    //
    // MessageId: XACT_E_CONNECTION_DOWN
    //
    // MessageText:
    //
    // A connection with the transaction manager was lost.
    //
    XACT_E_CONNECTION_DOWN = 0x8004D01CL,

    //
    // MessageId: XACT_E_CONNECTION_DENIED
    //
    // MessageText:
    //
    // A request to establish a connection with the transaction manager was denied.
    //
    XACT_E_CONNECTION_DENIED = 0x8004D01DL,

    //
    // MessageId: XACT_E_REENLISTTIMEOUT
    //
    // MessageText:
    //
    // Resource manager reenlistment to determine transaction status timed out.
    //
    XACT_E_REENLISTTIMEOUT = 0x8004D01EL,

    //
    // MessageId: XACT_E_TIP_CONNECT_FAILED
    //
    // MessageText:
    //
    // This transaction manager failed to establish a connection with another TIP transaction manager.
    //
    XACT_E_TIP_CONNECT_FAILED = 0x8004D01FL,

    //
    // MessageId: XACT_E_TIP_PROTOCOL_ERROR
    //
    // MessageText:
    //
    // This transaction manager encountered a protocol error with another TIP transaction manager.
    //
    XACT_E_TIP_PROTOCOL_ERROR = 0x8004D020L,

    //
    // MessageId: XACT_E_TIP_PULL_FAILED
    //
    // MessageText:
    //
    // This transaction manager could not propagate a transaction from another TIP transaction manager.
    //
    XACT_E_TIP_PULL_FAILED = 0x8004D021L,

    //
    // MessageId: XACT_E_DEST_TMNOTAVAILABLE
    //
    // MessageText:
    //
    // The Transaction Manager on the destination machine is not available.
    //
    XACT_E_DEST_TMNOTAVAILABLE = 0x8004D022L,

    //
    // MessageId: XACT_E_TIP_DISABLED
    //
    // MessageText:
    //
    // The Transaction Manager has disabled its support for TIP.
    //
    XACT_E_TIP_DISABLED = 0x8004D023L,

    //
    // MessageId: XACT_E_NETWORK_TX_DISABLED
    //
    // MessageText:
    //
    // The transaction manager has disabled its support for remote/network transactions.
    //
    XACT_E_NETWORK_TX_DISABLED = 0x8004D024L,

    //
    // MessageId: XACT_E_PARTNER_NETWORK_TX_DISABLED
    //
    // MessageText:
    //
    // The partner transaction manager has disabled its support for remote/network transactions.
    //
    XACT_E_PARTNER_NETWORK_TX_DISABLED = 0x8004D025L,

    //
    // MessageId: XACT_E_XA_TX_DISABLED
    //
    // MessageText:
    //
    // The transaction manager has disabled its support for XA transactions.
    //
    XACT_E_XA_TX_DISABLED = 0x8004D026L,

    //
    // MessageId: XACT_E_UNABLE_TO_READ_DTC_CONFIG
    //
    // MessageText:
    //
    // MSDTC was unable to read its configuration information.
    //
    XACT_E_UNABLE_TO_READ_DTC_CONFIG = 0x8004D027L,

    //
    // MessageId: XACT_E_UNABLE_TO_LOAD_DTC_PROXY
    //
    // MessageText:
    //
    // MSDTC was unable to load the dtc proxy dll.
    //
    XACT_E_UNABLE_TO_LOAD_DTC_PROXY = 0x8004D028L,

    //
    // MessageId: XACT_E_ABORTING
    //
    // MessageText:
    //
    // The local transaction has aborted.
    //
    XACT_E_ABORTING = 0x8004D029L,

    //
    // MessageId: XACT_E_PUSH_COMM_FAILURE
    //
    // MessageText:
    //
    // The MSDTC transaction manager was unable to push the transaction to the destination transaction manager due to communication problems. Possible causes are: a firewall is present and it doesn't have an exception for the MSDTC process, the two machines cannot find each other by their NetBIOS names, or the support for network transactions is not enabled for one of the two transaction managers.
    //
    XACT_E_PUSH_COMM_FAILURE = 0x8004D02AL,

    //
    // MessageId: XACT_E_PULL_COMM_FAILURE
    //
    // MessageText:
    //
    // The MSDTC transaction manager was unable to pull the transaction from the source transaction manager due to communication problems. Possible causes are: a firewall is present and it doesn't have an exception for the MSDTC process, the two machines cannot find each other by their NetBIOS names, or the support for network transactions is not enabled for one of the two transaction managers.
    //
    XACT_E_PULL_COMM_FAILURE = 0x8004D02BL,

    //
    // MessageId: XACT_E_LU_TX_DISABLED
    //
    // MessageText:
    //
    // The MSDTC transaction manager has disabled its support for SNA LU 6.2 transactions.
    //
    XACT_E_LU_TX_DISABLED = 0x8004D02CL,

    //
    // TXF & CRM errors start 4d080.
    //
    // MessageId: XACT_E_CLERKNOTFOUND
    //
    // MessageText:
    //
    //  XACT_E_CLERKNOTFOUND
    //
    XACT_E_CLERKNOTFOUND = 0x8004D080L,

    //
    // MessageId: XACT_E_CLERKEXISTS
    //
    // MessageText:
    //
    //  XACT_E_CLERKEXISTS
    //
    XACT_E_CLERKEXISTS = 0x8004D081L,

    //
    // MessageId: XACT_E_RECOVERYINPROGRESS
    //
    // MessageText:
    //
    //  XACT_E_RECOVERYINPROGRESS
    //
    XACT_E_RECOVERYINPROGRESS = 0x8004D082L,

    //
    // MessageId: XACT_E_TRANSACTIONCLOSED
    //
    // MessageText:
    //
    //  XACT_E_TRANSACTIONCLOSED
    //
    XACT_E_TRANSACTIONCLOSED = 0x8004D083L,

    //
    // MessageId: XACT_E_INVALIDLSN
    //
    // MessageText:
    //
    //  XACT_E_INVALIDLSN
    //
    XACT_E_INVALIDLSN = 0x8004D084L,

    //
    // MessageId: XACT_E_REPLAYREQUEST
    //
    // MessageText:
    //
    //  XACT_E_REPLAYREQUEST
    //
    XACT_E_REPLAYREQUEST = 0x8004D085L,

    // Begin XACT_DTC_CONSTANTS enumerated values defined in txdtc.h

    // SymbolicName=XACT_E_CONNECTION_REQUEST_DENIED
    //
    // MessageId: 0x8004D100L (No symbolic name defined)
    //
    // MessageText:
    //
    // The request to connect to the specified transaction coordinator was denied.
    //

    // SymbolicName=XACT_E_TOOMANY_ENLISTMENTS
    //
    // MessageId: 0x8004D101L (No symbolic name defined)
    //
    // MessageText:
    //
    // The maximum number of enlistments for the specified transaction has been reached.
    //

    // SymbolicName=XACT_E_DUPLICATE_GUID
    //
    // MessageId: 0x8004D102L (No symbolic name defined)
    //
    // MessageText:
    //
    // A resource manager with the same identifier is already registered with the specified transaction coordinator.
    //

    // SymbolicName=XACT_E_NOTSINGLEPHASE
    //
    // MessageId: 0x8004D103L (No symbolic name defined)
    //
    // MessageText:
    //
    // The prepare request given was not eligible for single phase optimizations.
    //

    // SymbolicName=XACT_E_RECOVERYALREADYDONE
    //
    // MessageId: 0x8004D104L (No symbolic name defined)
    //
    // MessageText:
    //
    // RecoveryComplete has already been called for the given resource manager.
    //

    // SymbolicName=XACT_E_PROTOCOL
    //
    // MessageId: 0x8004D105L (No symbolic name defined)
    //
    // MessageText:
    //
    // The interface call made was incorrect for the current state of the protocol.
    //

    // SymbolicName=XACT_E_RM_FAILURE
    //
    // MessageId: 0x8004D106L (No symbolic name defined)
    //
    // MessageText:
    //
    // xa_open call failed for the XA resource.
    //

    // SymbolicName=XACT_E_RECOVERY_FAILED
    //
    // MessageId: 0x8004D107L (No symbolic name defined)
    //
    // MessageText:
    //
    // xa_recover call failed for the XA resource.
    //

    // SymbolicName=XACT_E_LU_NOT_FOUND
    //
    // MessageId: 0x8004D108L (No symbolic name defined)
    //
    // MessageText:
    //
    // The Logical Unit of Work specified cannot be found.
    //

    // SymbolicName=XACT_E_DUPLICATE_LU
    //
    // MessageId: 0x8004D109L (No symbolic name defined)
    //
    // MessageText:
    //
    // The specified Logical Unit of Work already exists.
    //

    // SymbolicName=XACT_E_LU_NOT_CONNECTED
    //
    // MessageId: 0x8004D10AL (No symbolic name defined)
    //
    // MessageText:
    //
    // Subordinate creation failed. The specified Logical Unit of Work was not connected.
    //

    // SymbolicName=XACT_E_DUPLICATE_TRANSID
    //
    // MessageId: 0x8004D10BL (No symbolic name defined)
    //
    // MessageText:
    //
    // A transaction with the given identifier already exists.
    //

    // SymbolicName=XACT_E_LU_BUSY
    //
    // MessageId: 0x8004D10CL (No symbolic name defined)
    //
    // MessageText:
    //
    // The resource is in use.
    //

    // SymbolicName=XACT_E_LU_NO_RECOVERY_PROCESS
    //
    // MessageId: 0x8004D10DL (No symbolic name defined)
    //
    // MessageText:
    //
    // The LU Recovery process is down.
    //

    // SymbolicName=XACT_E_LU_DOWN
    //
    // MessageId: 0x8004D10EL (No symbolic name defined)
    //
    // MessageText:
    //
    // The remote session was lost.
    //

    // SymbolicName=XACT_E_LU_RECOVERING
    //
    // MessageId: 0x8004D10FL (No symbolic name defined)
    //
    // MessageText:
    //
    // The resource is currently recovering.
    //

    // SymbolicName=XACT_E_LU_RECOVERY_MISMATCH
    //
    // MessageId: 0x8004D110L (No symbolic name defined)
    //
    // MessageText:
    //
    // There was a mismatch in driving recovery.
    //

    // SymbolicName=XACT_E_RM_UNAVAILABLE
    //
    // MessageId: 0x8004D111L (No symbolic name defined)
    //
    // MessageText:
    //
    // An error occurred with the XA resource.
    //

    // End XACT_DTC_CONSTANTS enumerated values defined in txdtc.h

    //
    // OleTx Success codes.
    //
    //
    // MessageId: XACT_S_ASYNC
    //
    // MessageText:
    //
    // An asynchronous operation was specified. The operation has begun, but its outcome is not known yet.
    //
    XACT_S_ASYNC = 0x0004D000L,

    //
    // MessageId: XACT_S_DEFECT
    //
    // MessageText:
    //
    //  XACT_S_DEFECT
    //
    XACT_S_DEFECT = 0x0004D001L,

    //
    // MessageId: XACT_S_READONLY
    //
    // MessageText:
    //
    // The method call succeeded because the transaction was read-only.
    //
    XACT_S_READONLY = 0x0004D002L,

    //
    // MessageId: XACT_S_SOMENORETAIN
    //
    // MessageText:
    //
    // The transaction was successfully aborted. However, this is a coordinated transaction, and some number of enlisted resources were aborted outright because they could not support abort-retaining semantics
    //
    XACT_S_SOMENORETAIN = 0x0004D003L,

    //
    // MessageId: XACT_S_OKINFORM
    //
    // MessageText:
    //
    // No changes were made during this call, but the sink wants another chance to look if any other sinks make further changes.
    //
    XACT_S_OKINFORM = 0x0004D004L,

    //
    // MessageId: XACT_S_MADECHANGESCONTENT
    //
    // MessageText:
    //
    // The sink is content and wishes the transaction to proceed. Changes were made to one or more resources during this call.
    //
    XACT_S_MADECHANGESCONTENT = 0x0004D005L,

    //
    // MessageId: XACT_S_MADECHANGESINFORM
    //
    // MessageText:
    //
    // The sink is for the moment and wishes the transaction to proceed, but if other changes are made following this return by other event sinks then this sink wants another chance to look
    //
    XACT_S_MADECHANGESINFORM = 0x0004D006L,

    //
    // MessageId: XACT_S_ALLNORETAIN
    //
    // MessageText:
    //
    // The transaction was successfully aborted. However, the abort was non-retaining.
    //
    XACT_S_ALLNORETAIN = 0x0004D007L,

    //
    // MessageId: XACT_S_ABORTING
    //
    // MessageText:
    //
    // An abort operation was already in progress.
    //
    XACT_S_ABORTING = 0x0004D008L,

    //
    // MessageId: XACT_S_SINGLEPHASE
    //
    // MessageText:
    //
    // The resource manager has performed a single-phase commit of the transaction.
    //
    XACT_S_SINGLEPHASE = 0x0004D009L,

    //
    // MessageId: XACT_S_LOCALLY_OK
    //
    // MessageText:
    //
    // The local transaction has not aborted.
    //
    XACT_S_LOCALLY_OK = 0x0004D00AL,

    //
    // MessageId: XACT_S_LASTRESOURCEMANAGER
    //
    // MessageText:
    //
    // The resource manager has requested to be the coordinator (last resource manager) for the transaction.
    //
    XACT_S_LASTRESOURCEMANAGER = 0x0004D010L,

    CONTEXT_E_FIRST = 0x8004E000L,
    CONTEXT_E_LAST = 0x8004E02FL,
    CONTEXT_S_FIRST = 0x0004E000L,
    CONTEXT_S_LAST = 0x0004E02FL,
    //
    // MessageId: CONTEXT_E_ABORTED
    //
    // MessageText:
    //
    // The root transaction wanted to commit, but transaction aborted
    //
    CONTEXT_E_ABORTED = 0x8004E002L,

    //
    // MessageId: CONTEXT_E_ABORTING
    //
    // MessageText:
    //
    // You made a method call on a COM+ component that has a transaction that has already aborted or in the process of aborting.
    //
    CONTEXT_E_ABORTING = 0x8004E003L,

    //
    // MessageId: CONTEXT_E_NOCONTEXT
    //
    // MessageText:
    //
    // There is no MTS object context
    //
    CONTEXT_E_NOCONTEXT = 0x8004E004L,

    //
    // MessageId: CONTEXT_E_WOULD_DEADLOCK
    //
    // MessageText:
    //
    // The component is configured to use synchronization and this method call would cause a deadlock to occur.
    //
    CONTEXT_E_WOULD_DEADLOCK = 0x8004E005L,

    //
    // MessageId: CONTEXT_E_SYNCH_TIMEOUT
    //
    // MessageText:
    //
    // The component is configured to use synchronization and a thread has timed out waiting to enter the context.
    //
    CONTEXT_E_SYNCH_TIMEOUT = 0x8004E006L,

    //
    // MessageId: CONTEXT_E_OLDREF
    //
    // MessageText:
    //
    // You made a method call on a COM+ component that has a transaction that has already committed or aborted.
    //
    CONTEXT_E_OLDREF = 0x8004E007L,

    //
    // MessageId: CONTEXT_E_ROLENOTFOUND
    //
    // MessageText:
    //
    // The specified role was not configured for the application
    //
    CONTEXT_E_ROLENOTFOUND = 0x8004E00CL,

    //
    // MessageId: CONTEXT_E_TMNOTAVAILABLE
    //
    // MessageText:
    //
    // COM+ was unable to talk to the Microsoft Distributed Transaction Coordinator
    //
    CONTEXT_E_TMNOTAVAILABLE = 0x8004E00FL,

    //
    // MessageId: CO_E_ACTIVATIONFAILED
    //
    // MessageText:
    //
    // An unexpected error occurred during COM+ Activation.
    //
    CO_E_ACTIVATIONFAILED = 0x8004E021L,

    //
    // MessageId: CO_E_ACTIVATIONFAILED_EVENTLOGGED
    //
    // MessageText:
    //
    // COM+ Activation failed. Check the event log for more information
    //
    CO_E_ACTIVATIONFAILED_EVENTLOGGED = 0x8004E022L,

    //
    // MessageId: CO_E_ACTIVATIONFAILED_CATALOGERROR
    //
    // MessageText:
    //
    // COM+ Activation failed due to a catalog or configuration error.
    //
    CO_E_ACTIVATIONFAILED_CATALOGERROR = 0x8004E023L,

    //
    // MessageId: CO_E_ACTIVATIONFAILED_TIMEOUT
    //
    // MessageText:
    //
    // COM+ activation failed because the activation could not be completed in the specified amount of time.
    //
    CO_E_ACTIVATIONFAILED_TIMEOUT = 0x8004E024L,

    //
    // MessageId: CO_E_INITIALIZATIONFAILED
    //
    // MessageText:
    //
    // COM+ Activation failed because an initialization function failed. Check the event log for more information.
    //
    CO_E_INITIALIZATIONFAILED = 0x8004E025L,

    //
    // MessageId: CONTEXT_E_NOJIT
    //
    // MessageText:
    //
    // The requested operation requires that JIT be in the current context and it is not
    //
    CONTEXT_E_NOJIT = 0x8004E026L,

    //
    // MessageId: CONTEXT_E_NOTRANSACTION
    //
    // MessageText:
    //
    // The requested operation requires that the current context have a Transaction, and it does not
    //
    CONTEXT_E_NOTRANSACTION = 0x8004E027L,

    //
    // MessageId: CO_E_THREADINGMODEL_CHANGED
    //
    // MessageText:
    //
    // The components threading model has changed after install into a COM+ Application. Please re-install component.
    //
    CO_E_THREADINGMODEL_CHANGED = 0x8004E028L,

    //
    // MessageId: CO_E_NOIISINTRINSICS
    //
    // MessageText:
    //
    // IIS intrinsics not available. Start your work with IIS.
    //
    CO_E_NOIISINTRINSICS = 0x8004E029L,

    //
    // MessageId: CO_E_NOCOOKIES
    //
    // MessageText:
    //
    // An attempt to write a cookie failed.
    //
    CO_E_NOCOOKIES = 0x8004E02AL,

    //
    // MessageId: CO_E_DBERROR
    //
    // MessageText:
    //
    // An attempt to use a database generated a database specific error.
    //
    CO_E_DBERROR = 0x8004E02BL,

    //
    // MessageId: CO_E_NOTPOOLED
    //
    // MessageText:
    //
    // The COM+ component you created must use object pooling to work.
    //
    CO_E_NOTPOOLED = 0x8004E02CL,

    //
    // MessageId: CO_E_NOTCONSTRUCTED
    //
    // MessageText:
    //
    // The COM+ component you created must use object construction to work correctly.
    //
    CO_E_NOTCONSTRUCTED = 0x8004E02DL,

    //
    // MessageId: CO_E_NOSYNCHRONIZATION
    //
    // MessageText:
    //
    // The COM+ component requires synchronization, and it is not configured for it.
    //
    CO_E_NOSYNCHRONIZATION = 0x8004E02EL,

    //
    // MessageId: CO_E_ISOLEVELMISMATCH
    //
    // MessageText:
    //
    // The TxIsolation Level property for the COM+ component being created is stronger than the TxIsolationLevel for the "root" component for the transaction. The creation failed.
    //
    CO_E_ISOLEVELMISMATCH = 0x8004E02FL,

    //
    // MessageId: CO_E_CALL_OUT_OF_TX_SCOPE_NOT_ALLOWED
    //
    // MessageText:
    //
    // The component attempted to make a cross-context call between invocations of EnterTransactionScopeand ExitTransactionScope. This is not allowed. Cross-context calls cannot be made while inside of a transaction scope.
    //
    CO_E_CALL_OUT_OF_TX_SCOPE_NOT_ALLOWED = 0x8004E030L,

    //
    // MessageId: CO_E_EXIT_TRANSACTION_SCOPE_NOT_CALLED
    //
    // MessageText:
    //
    // The component made a call to EnterTransactionScope, but did not make a corresponding call to ExitTransactionScope before returning.
    //
    CO_E_EXIT_TRANSACTION_SCOPE_NOT_CALLED = 0x8004E031L,

    //
    // Old OLE Success Codes
    //
    //
    // MessageId: OLE_S_USEREG
    //
    // MessageText:
    //
    // Use the registry database to provide the requested information
    //
    OLE_S_USEREG = 0x00040000L,

    //
    // MessageId: OLE_S_STATIC
    //
    // MessageText:
    //
    // Success, but static
    //
    OLE_S_STATIC = 0x00040001L,

    //
    // MessageId: OLE_S_MAC_CLIPFORMAT
    //
    // MessageText:
    //
    // Macintosh clipboard format
    //
    OLE_S_MAC_CLIPFORMAT = 0x00040002L,

    //
    // MessageId: DRAGDROP_S_DROP
    //
    // MessageText:
    //
    // Successful drop took place
    //
    DRAGDROP_S_DROP = 0x00040100L,

    //
    // MessageId: DRAGDROP_S_CANCEL
    //
    // MessageText:
    //
    // Drag-drop operation canceled
    //
    DRAGDROP_S_CANCEL = 0x00040101L,

    //
    // MessageId: DRAGDROP_S_USEDEFAULTCURSORS
    //
    // MessageText:
    //
    // Use the default cursor
    //
    DRAGDROP_S_USEDEFAULTCURSORS = 0x00040102L,

    //
    // MessageId: DATA_S_SAMEFORMATETC
    //
    // MessageText:
    //
    // Data has same FORMATETC
    //
    DATA_S_SAMEFORMATETC = 0x00040130L,

    //
    // MessageId: VIEW_S_ALREADY_FROZEN
    //
    // MessageText:
    //
    // View is already frozen
    //
    VIEW_S_ALREADY_FROZEN = 0x00040140L,

    //
    // MessageId: CACHE_S_FORMATETC_NOTSUPPORTED
    //
    // MessageText:
    //
    // FORMATETC not supported
    //
    CACHE_S_FORMATETC_NOTSUPPORTED = 0x00040170L,

    //
    // MessageId: CACHE_S_SAMECACHE
    //
    // MessageText:
    //
    // Same cache
    //
    CACHE_S_SAMECACHE = 0x00040171L,

    //
    // MessageId: CACHE_S_SOMECACHES_NOTUPDATED
    //
    // MessageText:
    //
    // Some cache(s) not updated
    //
    CACHE_S_SOMECACHES_NOTUPDATED = 0x00040172L,

    //
    // MessageId: OLEOBJ_S_INVALIDVERB
    //
    // MessageText:
    //
    // Invalid verb for OLE object
    //
    OLEOBJ_S_INVALIDVERB = 0x00040180L,

    //
    // MessageId: OLEOBJ_S_CANNOT_DOVERB_NOW
    //
    // MessageText:
    //
    // Verb number is valid but verb cannot be done now
    //
    OLEOBJ_S_CANNOT_DOVERB_NOW = 0x00040181L,

    //
    // MessageId: OLEOBJ_S_INVALIDHWND
    //
    // MessageText:
    //
    // Invalid window handle passed
    //
    OLEOBJ_S_INVALIDHWND = 0x00040182L,

    //
    // MessageId: INPLACE_S_TRUNCATED
    //
    // MessageText:
    //
    // Message is too long; some of it had to be truncated before displaying
    //
    INPLACE_S_TRUNCATED = 0x000401A0L,

    //
    // MessageId: CONVERT10_S_NO_PRESENTATION
    //
    // MessageText:
    //
    // Unable to convert OLESTREAM to IStorage
    //
    CONVERT10_S_NO_PRESENTATION = 0x000401C0L,

    //
    // MessageId: MK_S_REDUCED_TO_SELF
    //
    // MessageText:
    //
    // Moniker reduced to itself
    //
    MK_S_REDUCED_TO_SELF = 0x000401E2L,

    //
    // MessageId: MK_S_ME
    //
    // MessageText:
    //
    // Common prefix is this moniker
    //
    MK_S_ME = 0x000401E4L,

    //
    // MessageId: MK_S_HIM
    //
    // MessageText:
    //
    // Common prefix is input moniker
    //
    MK_S_HIM = 0x000401E5L,

    //
    // MessageId: MK_S_US
    //
    // MessageText:
    //
    // Common prefix is both monikers
    //
    MK_S_US = 0x000401E6L,

    //
    // MessageId: MK_S_MONIKERALREADYREGISTERED
    //
    // MessageText:
    //
    // Moniker is already registered in running object table
    //
    MK_S_MONIKERALREADYREGISTERED = 0x000401E7L,

    //
    // Task Scheduler errors
    //
    //
    // MessageId: SCHED_S_TASK_READY
    //
    // MessageText:
    //
    // The task is ready to run at its next scheduled time.
    //
    SCHED_S_TASK_READY = 0x00041300L,

    //
    // MessageId: SCHED_S_TASK_RUNNING
    //
    // MessageText:
    //
    // The task is currently running.
    //
    SCHED_S_TASK_RUNNING = 0x00041301L,

    //
    // MessageId: SCHED_S_TASK_DISABLED
    //
    // MessageText:
    //
    // The task will not run at the scheduled times because it has been disabled.
    //
    SCHED_S_TASK_DISABLED = 0x00041302L,

    //
    // MessageId: SCHED_S_TASK_HAS_NOT_RUN
    //
    // MessageText:
    //
    // The task has not yet run.
    //
    SCHED_S_TASK_HAS_NOT_RUN = 0x00041303L,

    //
    // MessageId: SCHED_S_TASK_NO_MORE_RUNS
    //
    // MessageText:
    //
    // There are no more runs scheduled for this task.
    //
    SCHED_S_TASK_NO_MORE_RUNS = 0x00041304L,

    //
    // MessageId: SCHED_S_TASK_NOT_SCHEDULED
    //
    // MessageText:
    //
    // One or more of the properties that are needed to run this task on a schedule have not been set.
    //
    SCHED_S_TASK_NOT_SCHEDULED = 0x00041305L,

    //
    // MessageId: SCHED_S_TASK_TERMINATED
    //
    // MessageText:
    //
    // The last run of the task was terminated by the user.
    //
    SCHED_S_TASK_TERMINATED = 0x00041306L,

    //
    // MessageId: SCHED_S_TASK_NO_VALID_TRIGGERS
    //
    // MessageText:
    //
    // Either the task has no triggers or the existing triggers are disabled or not set.
    //
    SCHED_S_TASK_NO_VALID_TRIGGERS = 0x00041307L,

    //
    // MessageId: SCHED_S_EVENT_TRIGGER
    //
    // MessageText:
    //
    // Event triggers don't have set run times.
    //
    SCHED_S_EVENT_TRIGGER = 0x00041308L,

    //
    // MessageId: SCHED_E_TRIGGER_NOT_FOUND
    //
    // MessageText:
    //
    // Trigger not found.
    //
    SCHED_E_TRIGGER_NOT_FOUND = 0x80041309L,

    //
    // MessageId: SCHED_E_TASK_NOT_READY
    //
    // MessageText:
    //
    // One or more of the properties that are needed to run this task have not been set.
    //
    SCHED_E_TASK_NOT_READY = 0x8004130AL,

    //
    // MessageId: SCHED_E_TASK_NOT_RUNNING
    //
    // MessageText:
    //
    // There is no running instance of the task.
    //
    SCHED_E_TASK_NOT_RUNNING = 0x8004130BL,

    //
    // MessageId: SCHED_E_SERVICE_NOT_INSTALLED
    //
    // MessageText:
    //
    // The Task Scheduler Service is not installed on this computer.
    //
    SCHED_E_SERVICE_NOT_INSTALLED = 0x8004130CL,

    //
    // MessageId: SCHED_E_CANNOT_OPEN_TASK
    //
    // MessageText:
    //
    // The task object could not be opened.
    //
    SCHED_E_CANNOT_OPEN_TASK = 0x8004130DL,

    //
    // MessageId: SCHED_E_INVALID_TASK
    //
    // MessageText:
    //
    // The object is either an invalid task object or is not a task object.
    //
    SCHED_E_INVALID_TASK = 0x8004130EL,

    //
    // MessageId: SCHED_E_ACCOUNT_INFORMATION_NOT_SET
    //
    // MessageText:
    //
    // No account information could be found in the Task Scheduler security database for the task indicated.
    //
    SCHED_E_ACCOUNT_INFORMATION_NOT_SET = 0x8004130FL,

    //
    // MessageId: SCHED_E_ACCOUNT_NAME_NOT_FOUND
    //
    // MessageText:
    //
    // Unable to establish existence of the account specified.
    //
    SCHED_E_ACCOUNT_NAME_NOT_FOUND = 0x80041310L,

    //
    // MessageId: SCHED_E_ACCOUNT_DBASE_CORRUPT
    //
    // MessageText:
    //
    // Corruption was detected in the Task Scheduler security database; the database has been reset.
    //
    SCHED_E_ACCOUNT_DBASE_CORRUPT = 0x80041311L,

    //
    // MessageId: SCHED_E_NO_SECURITY_SERVICES
    //
    // MessageText:
    //
    // Task Scheduler security services are available only on Windows NT.
    //
    SCHED_E_NO_SECURITY_SERVICES = 0x80041312L,

    //
    // MessageId: SCHED_E_UNKNOWN_OBJECT_VERSION
    //
    // MessageText:
    //
    // The task object version is either unsupported or invalid.
    //
    SCHED_E_UNKNOWN_OBJECT_VERSION = 0x80041313L,

    //
    // MessageId: SCHED_E_UNSUPPORTED_ACCOUNT_OPTION
    //
    // MessageText:
    //
    // The task has been configured with an unsupported combination of account settings and run time options.
    //
    SCHED_E_UNSUPPORTED_ACCOUNT_OPTION = 0x80041314L,

    //
    // MessageId: SCHED_E_SERVICE_NOT_RUNNING
    //
    // MessageText:
    //
    // The Task Scheduler Service is not running.
    //
    SCHED_E_SERVICE_NOT_RUNNING = 0x80041315L,

    //
    // MessageId: SCHED_E_UNEXPECTEDNODE
    //
    // MessageText:
    //
    // The task XML contains an unexpected node.
    //
    SCHED_E_UNEXPECTEDNODE = 0x80041316L,

    //
    // MessageId: SCHED_E_NAMESPACE
    //
    // MessageText:
    //
    // The task XML contains an element or attribute from an unexpected namespace.
    //
    SCHED_E_NAMESPACE = 0x80041317L,

    //
    // MessageId: SCHED_E_INVALIDVALUE
    //
    // MessageText:
    //
    // The task XML contains a value which is incorrectly formatted or out of range.
    //
    SCHED_E_INVALIDVALUE = 0x80041318L,

    //
    // MessageId: SCHED_E_MISSINGNODE
    //
    // MessageText:
    //
    // The task XML is missing a required element or attribute.
    //
    SCHED_E_MISSINGNODE = 0x80041319L,

    //
    // MessageId: SCHED_E_MALFORMEDXML
    //
    // MessageText:
    //
    // The task XML is malformed.
    //
    SCHED_E_MALFORMEDXML = 0x8004131AL,

    //
    // MessageId: SCHED_S_SOME_TRIGGERS_FAILED
    //
    // MessageText:
    //
    // The task is registered, but not all specified triggers will start the task, check task scheduler event log for detailed information.
    //
    SCHED_S_SOME_TRIGGERS_FAILED = 0x0004131BL,

    //
    // MessageId: SCHED_S_BATCH_LOGON_PROBLEM
    //
    // MessageText:
    //
    // The task is registered, but may fail to start. Batch logon privilege needs to be enabled for the task principal.
    //
    SCHED_S_BATCH_LOGON_PROBLEM = 0x0004131CL,

    //
    // MessageId: SCHED_E_TOO_MANY_NODES
    //
    // MessageText:
    //
    // The task XML contains too many nodes of the same type.
    //
    SCHED_E_TOO_MANY_NODES = 0x8004131DL,

    //
    // MessageId: SCHED_E_PAST_END_BOUNDARY
    //
    // MessageText:
    //
    // The task cannot be started after the trigger's end boundary.
    //
    SCHED_E_PAST_END_BOUNDARY = 0x8004131EL,

    //
    // MessageId: SCHED_E_ALREADY_RUNNING
    //
    // MessageText:
    //
    // An instance of this task is already running.
    //
    SCHED_E_ALREADY_RUNNING = 0x8004131FL,

    //
    // MessageId: SCHED_E_USER_NOT_LOGGED_ON
    //
    // MessageText:
    //
    // The task will not run because the user is not logged on.
    //
    SCHED_E_USER_NOT_LOGGED_ON = 0x80041320L,

    //
    // MessageId: SCHED_E_INVALID_TASK_HASH
    //
    // MessageText:
    //
    // The task image is corrupt or has been tampered with.
    //
    SCHED_E_INVALID_TASK_HASH = 0x80041321L,

    //
    // MessageId: SCHED_E_SERVICE_NOT_AVAILABLE
    //
    // MessageText:
    //
    // The Task Scheduler service is not available.
    //
    SCHED_E_SERVICE_NOT_AVAILABLE = 0x80041322L,

    //
    // MessageId: SCHED_E_SERVICE_TOO_BUSY
    //
    // MessageText:
    //
    // The Task Scheduler service is too busy to handle your request. Please try again later.
    //
    SCHED_E_SERVICE_TOO_BUSY = 0x80041323L,

    //
    // MessageId: SCHED_E_TASK_ATTEMPTED
    //
    // MessageText:
    //
    // The Task Scheduler service attempted to run the task, but the task did not run due to one of the constraints in the task definition.
    //
    SCHED_E_TASK_ATTEMPTED = 0x80041324L,

    //
    // MessageId: SCHED_S_TASK_QUEUED
    //
    // MessageText:
    //
    // The Task Scheduler service has asked the task to run.
    //
    SCHED_S_TASK_QUEUED = 0x00041325L,

    //
    // MessageId: SCHED_E_TASK_DISABLED
    //
    // MessageText:
    //
    // The task is disabled.
    //
    SCHED_E_TASK_DISABLED = 0x80041326L,

    //
    // MessageId: SCHED_E_TASK_NOT_V1_COMPAT
    //
    // MessageText:
    //
    // The task has properties that are not compatible with previous versions of Windows.
    //
    SCHED_E_TASK_NOT_V1_COMPAT = 0x80041327L,

    //
    // MessageId: SCHED_E_START_ON_DEMAND
    //
    // MessageText:
    //
    // The task settings do not allow the task to start on demand.
    //
    SCHED_E_START_ON_DEMAND = 0x80041328L,

    //
    // MessageId: SCHED_E_TASK_NOT_UBPM_COMPAT
    //
    // MessageText:
    //
    // The combination of properties that task is using is not compatible with the scheduling engine.
    //
    SCHED_E_TASK_NOT_UBPM_COMPAT = 0x80041329L,

    //
    // MessageId: SCHED_E_DEPRECATED_FEATURE_USED
    //
    // MessageText:
    //
    // The task definition uses a deprecated feature.
    //
    SCHED_E_DEPRECATED_FEATURE_USED = 0x80041330L,

    // ******************
    // FACILITY_WINDOWS
    // ******************
    //
    // Codes 0x0-0x01ff are reserved for the OLE group of
    // interfaces.
    //
    //
    // MessageId: CO_E_CLASS_CREATE_FAILED
    //
    // MessageText:
    //
    // Attempt to create a class object failed
    //
    CO_E_CLASS_CREATE_FAILED = 0x80080001L,

    //
    // MessageId: CO_E_SCM_ERROR
    //
    // MessageText:
    //
    // OLE service could not bind object
    //
    CO_E_SCM_ERROR = 0x80080002L,

    //
    // MessageId: CO_E_SCM_RPC_FAILURE
    //
    // MessageText:
    //
    // RPC communication failed with OLE service
    //
    CO_E_SCM_RPC_FAILURE = 0x80080003L,

    //
    // MessageId: CO_E_BAD_PATH
    //
    // MessageText:
    //
    // Bad path to object
    //
    CO_E_BAD_PATH = 0x80080004L,

    //
    // MessageId: CO_E_SERVER_EXEC_FAILURE
    //
    // MessageText:
    //
    // Server execution failed
    //
    CO_E_SERVER_EXEC_FAILURE = 0x80080005L,

    //
    // MessageId: CO_E_OBJSRV_RPC_FAILURE
    //
    // MessageText:
    //
    // OLE service could not communicate with the object server
    //
    CO_E_OBJSRV_RPC_FAILURE = 0x80080006L,

    //
    // MessageId: MK_E_NO_NORMALIZED
    //
    // MessageText:
    //
    // Moniker path could not be normalized
    //
    MK_E_NO_NORMALIZED = 0x80080007L,

    //
    // MessageId: CO_E_SERVER_STOPPING
    //
    // MessageText:
    //
    // Object server is stopping when OLE service contacts it
    //
    CO_E_SERVER_STOPPING = 0x80080008L,

    //
    // MessageId: MEM_E_INVALID_ROOT
    //
    // MessageText:
    //
    // An invalid root block pointer was specified
    //
    MEM_E_INVALID_ROOT = 0x80080009L,

    //
    // MessageId: MEM_E_INVALID_LINK
    //
    // MessageText:
    //
    // An allocation chain contained an invalid link pointer
    //
    MEM_E_INVALID_LINK = 0x80080010L,

    //
    // MessageId: MEM_E_INVALID_SIZE
    //
    // MessageText:
    //
    // The requested allocation size was too large
    //
    MEM_E_INVALID_SIZE = 0x80080011L,

    //
    // MessageId: CO_S_NOTALLINTERFACES
    //
    // MessageText:
    //
    // Not all the requested interfaces were available
    //
    CO_S_NOTALLINTERFACES = 0x00080012L,

    //
    // MessageId: CO_S_MACHINENAMENOTFOUND
    //
    // MessageText:
    //
    // The specified machine name was not found in the cache.
    //
    CO_S_MACHINENAMENOTFOUND = 0x00080013L,

    //
    // MessageId: CO_E_MISSING_DISPLAYNAME
    //
    // MessageText:
    //
    // The activation requires a display name to be present under the CLSID key.
    //
    CO_E_MISSING_DISPLAYNAME = 0x80080015L,

    //
    // MessageId: CO_E_RUNAS_VALUE_MUST_BE_AAA
    //
    // MessageText:
    //
    // The activation requires that the RunAs value for the application is Activate As Activator.
    //
    CO_E_RUNAS_VALUE_MUST_BE_AAA = 0x80080016L,

    //
    // MessageId: CO_E_ELEVATION_DISABLED
    //
    // MessageText:
    //
    // The class is not configured to support Elevated activation.
    //
    CO_E_ELEVATION_DISABLED = 0x80080017L,

    //
    // Codes 0x0200-0x02ff are reserved for the APPX errors
    //
    //
    // MessageId: APPX_E_PACKAGING_INTERNAL
    //
    // MessageText:
    //
    // Appx packaging API has encountered an internal error.
    //
    APPX_E_PACKAGING_INTERNAL = 0x80080200L,

    //
    // MessageId: APPX_E_INTERLEAVING_NOT_ALLOWED
    //
    // MessageText:
    //
    // The file is not a valid Appx package because its contents are interleaved.
    //
    APPX_E_INTERLEAVING_NOT_ALLOWED = 0x80080201L,

    //
    // MessageId: APPX_E_RELATIONSHIPS_NOT_ALLOWED
    //
    // MessageText:
    //
    // The file is not a valid Appx package because it contains OPC relationships.
    //
    APPX_E_RELATIONSHIPS_NOT_ALLOWED = 0x80080202L,

    //
    // MessageId: APPX_E_MISSING_REQUIRED_FILE
    //
    // MessageText:
    //
    // The file is not a valid Appx package because it is missing a manifest or block map, or missing a signature file when the code integrity file is present.
    //
    APPX_E_MISSING_REQUIRED_FILE = 0x80080203L,

    //
    // MessageId: APPX_E_INVALID_MANIFEST
    //
    // MessageText:
    //
    // The Appx package's manifest is invalid.
    //
    APPX_E_INVALID_MANIFEST = 0x80080204L,

    //
    // MessageId: APPX_E_INVALID_BLOCKMAP
    //
    // MessageText:
    //
    // The Appx package's block map is invalid.
    //
    APPX_E_INVALID_BLOCKMAP = 0x80080205L,

    //
    // MessageId: APPX_E_CORRUPT_CONTENT
    //
    // MessageText:
    //
    // The Appx package's content cannot be read because it is corrupt.
    //
    APPX_E_CORRUPT_CONTENT = 0x80080206L,

    //
    // MessageId: APPX_E_BLOCK_HASH_INVALID
    //
    // MessageText:
    //
    // The computed hash value of the block does not match the one stored in the block map.
    //
    APPX_E_BLOCK_HASH_INVALID = 0x80080207L,

    //
    // MessageId: APPX_E_REQUESTED_RANGE_TOO_LARGE
    //
    // MessageText:
    //
    // The requested byte range is over 4GB when translated to byte range of blocks.
    //
    APPX_E_REQUESTED_RANGE_TOO_LARGE = 0x80080208L,

    //
    // MessageId: APPX_E_INVALID_SIP_CLIENT_DATA
    //
    // MessageText:
    //
    // The SIP_SUBJECTINFO structure used to sign the package didn't contain the required data.
    //
    APPX_E_INVALID_SIP_CLIENT_DATA = 0x80080209L,

    //
    // Codes 0x0300-0x030f are reserved for background task error codes.
    //
    //
    // MessageId: BT_E_SPURIOUS_ACTIVATION
    //
    // MessageText:
    //
    // The background task activation is spurious.
    //
    BT_E_SPURIOUS_ACTIVATION = 0x80080300L,

    // ******************
    // FACILITY_DISPATCH
    // ******************
    //
    // MessageId: DISP_E_UNKNOWNINTERFACE
    //
    // MessageText:
    //
    // Unknown interface.
    //
    DISP_E_UNKNOWNINTERFACE = 0x80020001L,

    //
    // MessageId: DISP_E_MEMBERNOTFOUND
    //
    // MessageText:
    //
    // Member not found.
    //
    DISP_E_MEMBERNOTFOUND = 0x80020003L,

    //
    // MessageId: DISP_E_PARAMNOTFOUND
    //
    // MessageText:
    //
    // Parameter not found.
    //
    DISP_E_PARAMNOTFOUND = 0x80020004L,

    //
    // MessageId: DISP_E_TYPEMISMATCH
    //
    // MessageText:
    //
    // Type mismatch.
    //
    DISP_E_TYPEMISMATCH = 0x80020005L,

    //
    // MessageId: DISP_E_UNKNOWNNAME
    //
    // MessageText:
    //
    // Unknown name.
    //
    DISP_E_UNKNOWNNAME = 0x80020006L,

    //
    // MessageId: DISP_E_NONAMEDARGS
    //
    // MessageText:
    //
    // No named arguments.
    //
    DISP_E_NONAMEDARGS = 0x80020007L,

    //
    // MessageId: DISP_E_BADVARTYPE
    //
    // MessageText:
    //
    // Bad variable type.
    //
    DISP_E_BADVARTYPE = 0x80020008L,

    //
    // MessageId: DISP_E_EXCEPTION
    //
    // MessageText:
    //
    // Exception occurred.
    //
    DISP_E_EXCEPTION = 0x80020009L,

    //
    // MessageId: DISP_E_OVERFLOW
    //
    // MessageText:
    //
    // Out of present range.
    //
    DISP_E_OVERFLOW = 0x8002000AL,

    //
    // MessageId: DISP_E_BADINDEX
    //
    // MessageText:
    //
    // Invalid index.
    //
    DISP_E_BADINDEX = 0x8002000BL,

    //
    // MessageId: DISP_E_UNKNOWNLCID
    //
    // MessageText:
    //
    // Unknown language.
    //
    DISP_E_UNKNOWNLCID = 0x8002000CL,

    //
    // MessageId: DISP_E_ARRAYISLOCKED
    //
    // MessageText:
    //
    // Memory is locked.
    //
    DISP_E_ARRAYISLOCKED = 0x8002000DL,

    //
    // MessageId: DISP_E_BADPARAMCOUNT
    //
    // MessageText:
    //
    // Invalid number of parameters.
    //
    DISP_E_BADPARAMCOUNT = 0x8002000EL,

    //
    // MessageId: DISP_E_PARAMNOTOPTIONAL
    //
    // MessageText:
    //
    // Parameter not optional.
    //
    DISP_E_PARAMNOTOPTIONAL = 0x8002000FL,

    //
    // MessageId: DISP_E_BADCALLEE
    //
    // MessageText:
    //
    // Invalid callee.
    //
    DISP_E_BADCALLEE = 0x80020010L,

    //
    // MessageId: DISP_E_NOTACOLLECTION
    //
    // MessageText:
    //
    // Does not support a collection.
    //
    DISP_E_NOTACOLLECTION = 0x80020011L,

    //
    // MessageId: DISP_E_DIVBYZERO
    //
    // MessageText:
    //
    // Division by zero.
    //
    DISP_E_DIVBYZERO = 0x80020012L,

    //
    // MessageId: DISP_E_BUFFERTOOSMALL
    //
    // MessageText:
    //
    // Buffer too small
    //
    DISP_E_BUFFERTOOSMALL = 0x80020013L,

    //
    // MessageId: TYPE_E_BUFFERTOOSMALL
    //
    // MessageText:
    //
    // Buffer too small.
    //
    TYPE_E_BUFFERTOOSMALL = 0x80028016L,

    //
    // MessageId: TYPE_E_FIELDNOTFOUND
    //
    // MessageText:
    //
    // Field name not defined in the record.
    //
    TYPE_E_FIELDNOTFOUND = 0x80028017L,

    //
    // MessageId: TYPE_E_INVDATAREAD
    //
    // MessageText:
    //
    // Old format or invalid type library.
    //
    TYPE_E_INVDATAREAD = 0x80028018L,

    //
    // MessageId: TYPE_E_UNSUPFORMAT
    //
    // MessageText:
    //
    // Old format or invalid type library.
    //
    TYPE_E_UNSUPFORMAT = 0x80028019L,

    //
    // MessageId: TYPE_E_REGISTRYACCESS
    //
    // MessageText:
    //
    // Error accessing the OLE registry.
    //
    TYPE_E_REGISTRYACCESS = 0x8002801CL,

    //
    // MessageId: TYPE_E_LIBNOTREGISTERED
    //
    // MessageText:
    //
    // Library not registered.
    //
    TYPE_E_LIBNOTREGISTERED = 0x8002801DL,

    //
    // MessageId: TYPE_E_UNDEFINEDTYPE
    //
    // MessageText:
    //
    // Bound to unknown type.
    //
    TYPE_E_UNDEFINEDTYPE = 0x80028027L,

    //
    // MessageId: TYPE_E_QUALIFIEDNAMEDISALLOWED
    //
    // MessageText:
    //
    // Qualified name disallowed.
    //
    TYPE_E_QUALIFIEDNAMEDISALLOWED = 0x80028028L,

    //
    // MessageId: TYPE_E_INVALIDSTATE
    //
    // MessageText:
    //
    // Invalid forward reference, or reference to uncompiled type.
    //
    TYPE_E_INVALIDSTATE = 0x80028029L,

    //
    // MessageId: TYPE_E_WRONGTYPEKIND
    //
    // MessageText:
    //
    // Type mismatch.
    //
    TYPE_E_WRONGTYPEKIND = 0x8002802AL,

    //
    // MessageId: TYPE_E_ELEMENTNOTFOUND
    //
    // MessageText:
    //
    // Element not found.
    //
    TYPE_E_ELEMENTNOTFOUND = 0x8002802BL,

    //
    // MessageId: TYPE_E_AMBIGUOUSNAME
    //
    // MessageText:
    //
    // Ambiguous name.
    //
    TYPE_E_AMBIGUOUSNAME = 0x8002802CL,

    //
    // MessageId: TYPE_E_NAMECONFLICT
    //
    // MessageText:
    //
    // Name already exists in the library.
    //
    TYPE_E_NAMECONFLICT = 0x8002802DL,

    //
    // MessageId: TYPE_E_UNKNOWNLCID
    //
    // MessageText:
    //
    // Unknown LCID.
    //
    TYPE_E_UNKNOWNLCID = 0x8002802EL,

    //
    // MessageId: TYPE_E_DLLFUNCTIONNOTFOUND
    //
    // MessageText:
    //
    // Function not defined in specified DLL.
    //
    TYPE_E_DLLFUNCTIONNOTFOUND = 0x8002802FL,

    //
    // MessageId: TYPE_E_BADMODULEKIND
    //
    // MessageText:
    //
    // Wrong module kind for the operation.
    //
    TYPE_E_BADMODULEKIND = 0x800288BDL,

    //
    // MessageId: TYPE_E_SIZETOOBIG
    //
    // MessageText:
    //
    // Size may not exceed 64K.
    //
    TYPE_E_SIZETOOBIG = 0x800288C5L,

    //
    // MessageId: TYPE_E_DUPLICATEID
    //
    // MessageText:
    //
    // Duplicate ID in inheritance hierarchy.
    //
    TYPE_E_DUPLICATEID = 0x800288C6L,

    //
    // MessageId: TYPE_E_INVALIDID
    //
    // MessageText:
    //
    // Incorrect inheritance depth in standard OLE hmember.
    //
    TYPE_E_INVALIDID = 0x800288CFL,

    //
    // MessageId: TYPE_E_TYPEMISMATCH
    //
    // MessageText:
    //
    // Type mismatch.
    //
    TYPE_E_TYPEMISMATCH = 0x80028CA0L,

    //
    // MessageId: TYPE_E_OUTOFBOUNDS
    //
    // MessageText:
    //
    // Invalid number of arguments.
    //
    TYPE_E_OUTOFBOUNDS = 0x80028CA1L,

    //
    // MessageId: TYPE_E_IOERROR
    //
    // MessageText:
    //
    // I/O Error.
    //
    TYPE_E_IOERROR = 0x80028CA2L,

    //
    // MessageId: TYPE_E_CANTCREATETMPFILE
    //
    // MessageText:
    //
    // Error creating unique tmp file.
    //
    TYPE_E_CANTCREATETMPFILE = 0x80028CA3L,

    //
    // MessageId: TYPE_E_CANTLOADLIBRARY
    //
    // MessageText:
    //
    // Error loading type library/DLL.
    //
    TYPE_E_CANTLOADLIBRARY = 0x80029C4AL,

    //
    // MessageId: TYPE_E_INCONSISTENTPROPFUNCS
    //
    // MessageText:
    //
    // Inconsistent property functions.
    //
    TYPE_E_INCONSISTENTPROPFUNCS = 0x80029C83L,

    //
    // MessageId: TYPE_E_CIRCULARTYPE
    //
    // MessageText:
    //
    // Circular dependency between types/modules.
    //
    TYPE_E_CIRCULARTYPE = 0x80029C84L,

    // ******************
    // FACILITY_STORAGE
    // ******************
    //
    // MessageId: STG_E_INVALIDFUNCTION
    //
    // MessageText:
    //
    // Unable to perform requested operation.
    //
    STG_E_INVALIDFUNCTION = 0x80030001L,

    //
    // MessageId: STG_E_FILENOTFOUND
    //
    // MessageText:
    //
    // %1 could not be found.
    //
    STG_E_FILENOTFOUND = 0x80030002L,

    //
    // MessageId: STG_E_PATHNOTFOUND
    //
    // MessageText:
    //
    // The path %1 could not be found.
    //
    STG_E_PATHNOTFOUND = 0x80030003L,

    //
    // MessageId: STG_E_TOOMANYOPENFILES
    //
    // MessageText:
    //
    // There are insufficient resources to open another file.
    //
    STG_E_TOOMANYOPENFILES = 0x80030004L,

    //
    // MessageId: STG_E_ACCESSDENIED
    //
    // MessageText:
    //
    // Access Denied.
    //
    STG_E_ACCESSDENIED = 0x80030005L,

    //
    // MessageId: STG_E_INVALIDHANDLE
    //
    // MessageText:
    //
    // Attempted an operation on an invalid object.
    //
    STG_E_INVALIDHANDLE = 0x80030006L,

    //
    // MessageId: STG_E_INSUFFICIENTMEMORY
    //
    // MessageText:
    //
    // There is insufficient memory available to complete operation.
    //
    STG_E_INSUFFICIENTMEMORY = 0x80030008L,

    //
    // MessageId: STG_E_INVALIDPOINTER
    //
    // MessageText:
    //
    // Invalid pointer error.
    //
    STG_E_INVALIDPOINTER = 0x80030009L,

    //
    // MessageId: STG_E_NOMOREFILES
    //
    // MessageText:
    //
    // There are no more entries to return.
    //
    STG_E_NOMOREFILES = 0x80030012L,

    //
    // MessageId: STG_E_DISKISWRITEPROTECTED
    //
    // MessageText:
    //
    // Disk is write-protected.
    //
    STG_E_DISKISWRITEPROTECTED = 0x80030013L,

    //
    // MessageId: STG_E_SEEKERROR
    //
    // MessageText:
    //
    // An error occurred during a seek operation.
    //
    STG_E_SEEKERROR = 0x80030019L,

    //
    // MessageId: STG_E_WRITEFAULT
    //
    // MessageText:
    //
    // A disk error occurred during a write operation.
    //
    STG_E_WRITEFAULT = 0x8003001DL,

    //
    // MessageId: STG_E_READFAULT
    //
    // MessageText:
    //
    // A disk error occurred during a read operation.
    //
    STG_E_READFAULT = 0x8003001EL,

    //
    // MessageId: STG_E_SHAREVIOLATION
    //
    // MessageText:
    //
    // A share violation has occurred.
    //
    STG_E_SHAREVIOLATION = 0x80030020L,

    //
    // MessageId: STG_E_LOCKVIOLATION
    //
    // MessageText:
    //
    // A lock violation has occurred.
    //
    STG_E_LOCKVIOLATION = 0x80030021L,

    //
    // MessageId: STG_E_FILEALREADYEXISTS
    //
    // MessageText:
    //
    // %1 already exists.
    //
    STG_E_FILEALREADYEXISTS = 0x80030050L,

    //
    // MessageId: STG_E_INVALIDPARAMETER
    //
    // MessageText:
    //
    // Invalid parameter error.
    //
    STG_E_INVALIDPARAMETER = 0x80030057L,

    //
    // MessageId: STG_E_MEDIUMFULL
    //
    // MessageText:
    //
    // There is insufficient disk space to complete operation.
    //
    STG_E_MEDIUMFULL = 0x80030070L,

    //
    // MessageId: STG_E_PROPSETMISMATCHED
    //
    // MessageText:
    //
    // Illegal write of non-simple property to simple property set.
    //
    STG_E_PROPSETMISMATCHED = 0x800300F0L,

    //
    // MessageId: STG_E_ABNORMALAPIEXIT
    //
    // MessageText:
    //
    // An API call exited abnormally.
    //
    STG_E_ABNORMALAPIEXIT = 0x800300FAL,

    //
    // MessageId: STG_E_INVALIDHEADER
    //
    // MessageText:
    //
    // The file %1 is not a valid compound file.
    //
    STG_E_INVALIDHEADER = 0x800300FBL,

    //
    // MessageId: STG_E_INVALIDNAME
    //
    // MessageText:
    //
    // The name %1 is not valid.
    //
    STG_E_INVALIDNAME = 0x800300FCL,

    //
    // MessageId: STG_E_UNKNOWN
    //
    // MessageText:
    //
    // An unexpected error occurred.
    //
    STG_E_UNKNOWN = 0x800300FDL,

    //
    // MessageId: STG_E_UNIMPLEMENTEDFUNCTION
    //
    // MessageText:
    //
    // That function is not implemented.
    //
    STG_E_UNIMPLEMENTEDFUNCTION = 0x800300FEL,

    //
    // MessageId: STG_E_INVALIDFLAG
    //
    // MessageText:
    //
    // Invalid flag error.
    //
    STG_E_INVALIDFLAG = 0x800300FFL,

    //
    // MessageId: STG_E_INUSE
    //
    // MessageText:
    //
    // Attempted to use an object that is busy.
    //
    STG_E_INUSE = 0x80030100L,

    //
    // MessageId: STG_E_NOTCURRENT
    //
    // MessageText:
    //
    // The storage has been changed since the last commit.
    //
    STG_E_NOTCURRENT = 0x80030101L,

    //
    // MessageId: STG_E_REVERTED
    //
    // MessageText:
    //
    // Attempted to use an object that has ceased to exist.
    //
    STG_E_REVERTED = 0x80030102L,

    //
    // MessageId: STG_E_CANTSAVE
    //
    // MessageText:
    //
    // Can't save.
    //
    STG_E_CANTSAVE = 0x80030103L,

    //
    // MessageId: STG_E_OLDFORMAT
    //
    // MessageText:
    //
    // The compound file %1 was produced with an incompatible version of storage.
    //
    STG_E_OLDFORMAT = 0x80030104L,

    //
    // MessageId: STG_E_OLDDLL
    //
    // MessageText:
    //
    // The compound file %1 was produced with a newer version of storage.
    //
    STG_E_OLDDLL = 0x80030105L,

    //
    // MessageId: STG_E_SHAREREQUIRED
    //
    // MessageText:
    //
    // Share.exe or equivalent is required for operation.
    //
    STG_E_SHAREREQUIRED = 0x80030106L,

    //
    // MessageId: STG_E_NOTFILEBASEDSTORAGE
    //
    // MessageText:
    //
    // Illegal operation called on non-file based storage.
    //
    STG_E_NOTFILEBASEDSTORAGE = 0x80030107L,

    //
    // MessageId: STG_E_EXTANTMARSHALLINGS
    //
    // MessageText:
    //
    // Illegal operation called on object with extant marshallings.
    //
    STG_E_EXTANTMARSHALLINGS = 0x80030108L,

    //
    // MessageId: STG_E_DOCFILECORRUPT
    //
    // MessageText:
    //
    // The docfile has been corrupted.
    //
    STG_E_DOCFILECORRUPT = 0x80030109L,

    //
    // MessageId: STG_E_BADBASEADDRESS
    //
    // MessageText:
    //
    // OLE32.DLL has been loaded at the wrong address.
    //
    STG_E_BADBASEADDRESS = 0x80030110L,

    //
    // MessageId: STG_E_DOCFILETOOLARGE
    //
    // MessageText:
    //
    // The compound file is too large for the current implementation
    //
    STG_E_DOCFILETOOLARGE = 0x80030111L,

    //
    // MessageId: STG_E_NOTSIMPLEFORMAT
    //
    // MessageText:
    //
    // The compound file was not created with the STGM_SIMPLE flag
    //
    STG_E_NOTSIMPLEFORMAT = 0x80030112L,

    //
    // MessageId: STG_E_INCOMPLETE
    //
    // MessageText:
    //
    // The file download was aborted abnormally. The file is incomplete.
    //
    STG_E_INCOMPLETE = 0x80030201L,

    //
    // MessageId: STG_E_TERMINATED
    //
    // MessageText:
    //
    // The file download has been terminated.
    //
    STG_E_TERMINATED = 0x80030202L,

    //
    // MessageId: STG_S_CONVERTED
    //
    // MessageText:
    //
    // The underlying file was converted to compound file format.
    //
    STG_S_CONVERTED = 0x00030200L,

    //
    // MessageId: STG_S_BLOCK
    //
    // MessageText:
    //
    // The storage operation should block until more data is available.
    //
    STG_S_BLOCK = 0x00030201L,

    //
    // MessageId: STG_S_RETRYNOW
    //
    // MessageText:
    //
    // The storage operation should retry immediately.
    //
    STG_S_RETRYNOW = 0x00030202L,

    //
    // MessageId: STG_S_MONITORING
    //
    // MessageText:
    //
    // The notified event sink will not influence the storage operation.
    //
    STG_S_MONITORING = 0x00030203L,

    //
    // MessageId: STG_S_MULTIPLEOPENS
    //
    // MessageText:
    //
    // Multiple opens prevent consolidated. (commit succeeded).
    //
    STG_S_MULTIPLEOPENS = 0x00030204L,

    //
    // MessageId: STG_S_CONSOLIDATIONFAILED
    //
    // MessageText:
    //
    // Consolidation of the storage file failed. (commit succeeded).
    //
    STG_S_CONSOLIDATIONFAILED = 0x00030205L,

    //
    // MessageId: STG_S_CANNOTCONSOLIDATE
    //
    // MessageText:
    //
    // Consolidation of the storage file is inappropriate. (commit succeeded).
    //
    STG_S_CANNOTCONSOLIDATE = 0x00030206L,

    /*++

 MessageId's 0x0305 - 0x031f (inclusive) are reserved for **STORAGE**
 copy protection errors.

--*/
    //
    // MessageId: STG_E_STATUS_COPY_PROTECTION_FAILURE
    //
    // MessageText:
    //
    // Generic Copy Protection Error.
    //
    STG_E_STATUS_COPY_PROTECTION_FAILURE = 0x80030305L,

    //
    // MessageId: STG_E_CSS_AUTHENTICATION_FAILURE
    //
    // MessageText:
    //
    // Copy Protection Error - DVD CSS Authentication failed.
    //
    STG_E_CSS_AUTHENTICATION_FAILURE = 0x80030306L,

    //
    // MessageId: STG_E_CSS_KEY_NOT_PRESENT
    //
    // MessageText:
    //
    // Copy Protection Error - The given sector does not have a valid CSS key.
    //
    STG_E_CSS_KEY_NOT_PRESENT = 0x80030307L,

    //
    // MessageId: STG_E_CSS_KEY_NOT_ESTABLISHED
    //
    // MessageText:
    //
    // Copy Protection Error - DVD session key not established.
    //
    STG_E_CSS_KEY_NOT_ESTABLISHED = 0x80030308L,

    //
    // MessageId: STG_E_CSS_SCRAMBLED_SECTOR
    //
    // MessageText:
    //
    // Copy Protection Error - The read failed because the sector is encrypted.
    //
    STG_E_CSS_SCRAMBLED_SECTOR = 0x80030309L,

    //
    // MessageId: STG_E_CSS_REGION_MISMATCH
    //
    // MessageText:
    //
    // Copy Protection Error - The current DVD's region does not correspond to the region setting of the drive.
    //
    STG_E_CSS_REGION_MISMATCH = 0x8003030AL,

    //
    // MessageId: STG_E_RESETS_EXHAUSTED
    //
    // MessageText:
    //
    // Copy Protection Error - The drive's region setting may be permanent or the number of user resets has been exhausted.
    //
    STG_E_RESETS_EXHAUSTED = 0x8003030BL,

    /*++

 MessageId's 0x0305 - 0x031f (inclusive) are reserved for **STORAGE**
 copy protection errors.

--*/
    // ******************
    // FACILITY_RPC
    // ******************
    //
    // Codes 0x0-0x11 are propagated from 16 bit OLE.
    //
    //
    // MessageId: RPC_E_CALL_REJECTED
    //
    // MessageText:
    //
    // Call was rejected by callee.
    //
    RPC_E_CALL_REJECTED = 0x80010001L,

    //
    // MessageId: RPC_E_CALL_CANCELED
    //
    // MessageText:
    //
    // Call was canceled by the message filter.
    //
    RPC_E_CALL_CANCELED = 0x80010002L,

    //
    // MessageId: RPC_E_CANTPOST_INSENDCALL
    //
    // MessageText:
    //
    // The caller is dispatching an intertask SendMessage call and cannot call out via PostMessage.
    //
    RPC_E_CANTPOST_INSENDCALL = 0x80010003L,

    //
    // MessageId: RPC_E_CANTCALLOUT_INASYNCCALL
    //
    // MessageText:
    //
    // The caller is dispatching an asynchronous call and cannot make an outgoing call on behalf of this call.
    //
    RPC_E_CANTCALLOUT_INASYNCCALL = 0x80010004L,

    //
    // MessageId: RPC_E_CANTCALLOUT_INEXTERNALCALL
    //
    // MessageText:
    //
    // It is illegal to call out while inside message filter.
    //
    RPC_E_CANTCALLOUT_INEXTERNALCALL = 0x80010005L,

    //
    // MessageId: RPC_E_CONNECTION_TERMINATED
    //
    // MessageText:
    //
    // The connection terminated or is in a bogus state and cannot be used any more. Other connections are still valid.
    //
    RPC_E_CONNECTION_TERMINATED = 0x80010006L,

    //
    // MessageId: RPC_E_SERVER_DIED
    //
    // MessageText:
    //
    // The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call may have executed.
    //
    RPC_E_SERVER_DIED = 0x80010007L,

    //
    // MessageId: RPC_E_CLIENT_DIED
    //
    // MessageText:
    //
    // The caller (client) disappeared while the callee (server) was processing a call.
    //
    RPC_E_CLIENT_DIED = 0x80010008L,

    //
    // MessageId: RPC_E_INVALID_DATAPACKET
    //
    // MessageText:
    //
    // The data packet with the marshalled parameter data is incorrect.
    //
    RPC_E_INVALID_DATAPACKET = 0x80010009L,

    //
    // MessageId: RPC_E_CANTTRANSMIT_CALL
    //
    // MessageText:
    //
    // The call was not transmitted properly; the message queue was full and was not emptied after yielding.
    //
    RPC_E_CANTTRANSMIT_CALL = 0x8001000AL,

    //
    // MessageId: RPC_E_CLIENT_CANTMARSHAL_DATA
    //
    // MessageText:
    //
    // The client (caller) cannot marshall the parameter data - low memory, etc.
    //
    RPC_E_CLIENT_CANTMARSHAL_DATA = 0x8001000BL,

    //
    // MessageId: RPC_E_CLIENT_CANTUNMARSHAL_DATA
    //
    // MessageText:
    //
    // The client (caller) cannot unmarshall the return data - low memory, etc.
    //
    RPC_E_CLIENT_CANTUNMARSHAL_DATA = 0x8001000CL,

    //
    // MessageId: RPC_E_SERVER_CANTMARSHAL_DATA
    //
    // MessageText:
    //
    // The server (callee) cannot marshall the return data - low memory, etc.
    //
    RPC_E_SERVER_CANTMARSHAL_DATA = 0x8001000DL,

    //
    // MessageId: RPC_E_SERVER_CANTUNMARSHAL_DATA
    //
    // MessageText:
    //
    // The server (callee) cannot unmarshall the parameter data - low memory, etc.
    //
    RPC_E_SERVER_CANTUNMARSHAL_DATA = 0x8001000EL,

    //
    // MessageId: RPC_E_INVALID_DATA
    //
    // MessageText:
    //
    // Received data is invalid; could be server or client data.
    //
    RPC_E_INVALID_DATA = 0x8001000FL,

    //
    // MessageId: RPC_E_INVALID_PARAMETER
    //
    // MessageText:
    //
    // A particular parameter is invalid and cannot be (un)marshalled.
    //
    RPC_E_INVALID_PARAMETER = 0x80010010L,

    //
    // MessageId: RPC_E_CANTCALLOUT_AGAIN
    //
    // MessageText:
    //
    // There is no second outgoing call on same channel in DDE conversation.
    //
    RPC_E_CANTCALLOUT_AGAIN = 0x80010011L,

    //
    // MessageId: RPC_E_SERVER_DIED_DNE
    //
    // MessageText:
    //
    // The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call did not execute.
    //
    RPC_E_SERVER_DIED_DNE = 0x80010012L,

    //
    // MessageId: RPC_E_SYS_CALL_FAILED
    //
    // MessageText:
    //
    // System call failed.
    //
    RPC_E_SYS_CALL_FAILED = 0x80010100L,

    //
    // MessageId: RPC_E_OUT_OF_RESOURCES
    //
    // MessageText:
    //
    // Could not allocate some required resource (memory, events, ...)
    //
    RPC_E_OUT_OF_RESOURCES = 0x80010101L,

    //
    // MessageId: RPC_E_ATTEMPTED_MULTITHREAD
    //
    // MessageText:
    //
    // Attempted to make calls on more than one thread in single threaded mode.
    //
    RPC_E_ATTEMPTED_MULTITHREAD = 0x80010102L,

    //
    // MessageId: RPC_E_NOT_REGISTERED
    //
    // MessageText:
    //
    // The requested interface is not registered on the server object.
    //
    RPC_E_NOT_REGISTERED = 0x80010103L,

    //
    // MessageId: RPC_E_FAULT
    //
    // MessageText:
    //
    // RPC could not call the server or could not return the results of calling the server.
    //
    RPC_E_FAULT = 0x80010104L,

    //
    // MessageId: RPC_E_SERVERFAULT
    //
    // MessageText:
    //
    // The server threw an exception.
    //
    RPC_E_SERVERFAULT = 0x80010105L,

    //
    // MessageId: RPC_E_CHANGED_MODE
    //
    // MessageText:
    //
    // Cannot change thread mode after it is set.
    //
    RPC_E_CHANGED_MODE = 0x80010106L,

    //
    // MessageId: RPC_E_INVALIDMETHOD
    //
    // MessageText:
    //
    // The method called does not exist on the server.
    //
    RPC_E_INVALIDMETHOD = 0x80010107L,

    //
    // MessageId: RPC_E_DISCONNECTED
    //
    // MessageText:
    //
    // The object invoked has disconnected from its clients.
    //
    RPC_E_DISCONNECTED = 0x80010108L,

    //
    // MessageId: RPC_E_RETRY
    //
    // MessageText:
    //
    // The object invoked chose not to process the call now. Try again later.
    //
    RPC_E_RETRY = 0x80010109L,

    //
    // MessageId: RPC_E_SERVERCALL_RETRYLATER
    //
    // MessageText:
    //
    // The message filter indicated that the application is busy.
    //
    RPC_E_SERVERCALL_RETRYLATER = 0x8001010AL,

    //
    // MessageId: RPC_E_SERVERCALL_REJECTED
    //
    // MessageText:
    //
    // The message filter rejected the call.
    //
    RPC_E_SERVERCALL_REJECTED = 0x8001010BL,

    //
    // MessageId: RPC_E_INVALID_CALLDATA
    //
    // MessageText:
    //
    // A call control interfaces was called with invalid data.
    //
    RPC_E_INVALID_CALLDATA = 0x8001010CL,

    //
    // MessageId: RPC_E_CANTCALLOUT_ININPUTSYNCCALL
    //
    // MessageText:
    //
    // An outgoing call cannot be made since the application is dispatching an input-synchronous call.
    //
    RPC_E_CANTCALLOUT_ININPUTSYNCCALL = 0x8001010DL,

    //
    // MessageId: RPC_E_WRONG_THREAD
    //
    // MessageText:
    //
    // The application called an interface that was marshalled for a different thread.
    //
    RPC_E_WRONG_THREAD = 0x8001010EL,

    //
    // MessageId: RPC_E_THREAD_NOT_INIT
    //
    // MessageText:
    //
    // CoInitialize has not been called on the current thread.
    //
    RPC_E_THREAD_NOT_INIT = 0x8001010FL,

    //
    // MessageId: RPC_E_VERSION_MISMATCH
    //
    // MessageText:
    //
    // The version of OLE on the client and server machines does not match.
    //
    RPC_E_VERSION_MISMATCH = 0x80010110L,

    //
    // MessageId: RPC_E_INVALID_HEADER
    //
    // MessageText:
    //
    // OLE received a packet with an invalid header.
    //
    RPC_E_INVALID_HEADER = 0x80010111L,

    //
    // MessageId: RPC_E_INVALID_EXTENSION
    //
    // MessageText:
    //
    // OLE received a packet with an invalid extension.
    //
    RPC_E_INVALID_EXTENSION = 0x80010112L,

    //
    // MessageId: RPC_E_INVALID_IPID
    //
    // MessageText:
    //
    // The requested object or interface does not exist.
    //
    RPC_E_INVALID_IPID = 0x80010113L,

    //
    // MessageId: RPC_E_INVALID_OBJECT
    //
    // MessageText:
    //
    // The requested object does not exist.
    //
    RPC_E_INVALID_OBJECT = 0x80010114L,

    //
    // MessageId: RPC_S_CALLPENDING
    //
    // MessageText:
    //
    // OLE has sent a request and is waiting for a reply.
    //
    RPC_S_CALLPENDING = 0x80010115L,

    //
    // MessageId: RPC_S_WAITONTIMER
    //
    // MessageText:
    //
    // OLE is waiting before retrying a request.
    //
    RPC_S_WAITONTIMER = 0x80010116L,

    //
    // MessageId: RPC_E_CALL_COMPLETE
    //
    // MessageText:
    //
    // Call context cannot be accessed after call completed.
    //
    RPC_E_CALL_COMPLETE = 0x80010117L,

    //
    // MessageId: RPC_E_UNSECURE_CALL
    //
    // MessageText:
    //
    // Impersonate on unsecure calls is not supported.
    //
    RPC_E_UNSECURE_CALL = 0x80010118L,

    //
    // MessageId: RPC_E_TOO_LATE
    //
    // MessageText:
    //
    // Security must be initialized before any interfaces are marshalled or unmarshalled. It cannot be changed once initialized.
    //
    RPC_E_TOO_LATE = 0x80010119L,

    //
    // MessageId: RPC_E_NO_GOOD_SECURITY_PACKAGES
    //
    // MessageText:
    //
    // No security packages are installed on this machine or the user is not logged on or there are no compatible security packages between the client and server.
    //
    RPC_E_NO_GOOD_SECURITY_PACKAGES = 0x8001011AL,

    //
    // MessageId: RPC_E_ACCESS_DENIED
    //
    // MessageText:
    //
    // Access is denied.
    //
    RPC_E_ACCESS_DENIED = 0x8001011BL,

    //
    // MessageId: RPC_E_REMOTE_DISABLED
    //
    // MessageText:
    //
    // Remote calls are not allowed for this process.
    //
    RPC_E_REMOTE_DISABLED = 0x8001011CL,

    //
    // MessageId: RPC_E_INVALID_OBJREF
    //
    // MessageText:
    //
    // The marshaled interface data packet (OBJREF) has an invalid or unknown format.
    //
    RPC_E_INVALID_OBJREF = 0x8001011DL,

    //
    // MessageId: RPC_E_NO_CONTEXT
    //
    // MessageText:
    //
    // No context is associated with this call. This happens for some custom marshalled calls and on the client side of the call.
    //
    RPC_E_NO_CONTEXT = 0x8001011EL,

    //
    // MessageId: RPC_E_TIMEOUT
    //
    // MessageText:
    //
    // This operation returned because the timeout period expired.
    //
    RPC_E_TIMEOUT = 0x8001011FL,

    //
    // MessageId: RPC_E_NO_SYNC
    //
    // MessageText:
    //
    // There are no synchronize objects to wait on.
    //
    RPC_E_NO_SYNC = 0x80010120L,

    //
    // MessageId: RPC_E_FULLSIC_REQUIRED
    //
    // MessageText:
    //
    // Full subject issuer chain SSL principal name expected from the server.
    //
    RPC_E_FULLSIC_REQUIRED = 0x80010121L,

    //
    // MessageId: RPC_E_INVALID_STD_NAME
    //
    // MessageText:
    //
    // Principal name is not a valid MSSTD name.
    //
    RPC_E_INVALID_STD_NAME = 0x80010122L,

    //
    // MessageId: CO_E_FAILEDTOIMPERSONATE
    //
    // MessageText:
    //
    // Unable to impersonate DCOM client
    //
    CO_E_FAILEDTOIMPERSONATE = 0x80010123L,

    //
    // MessageId: CO_E_FAILEDTOGETSECCTX
    //
    // MessageText:
    //
    // Unable to obtain server's security context
    //
    CO_E_FAILEDTOGETSECCTX = 0x80010124L,

    //
    // MessageId: CO_E_FAILEDTOOPENTHREADTOKEN
    //
    // MessageText:
    //
    // Unable to open the access token of the current thread
    //
    CO_E_FAILEDTOOPENTHREADTOKEN = 0x80010125L,

    //
    // MessageId: CO_E_FAILEDTOGETTOKENINFO
    //
    // MessageText:
    //
    // Unable to obtain user info from an access token
    //
    CO_E_FAILEDTOGETTOKENINFO = 0x80010126L,

    //
    // MessageId: CO_E_TRUSTEEDOESNTMATCHCLIENT
    //
    // MessageText:
    //
    // The client who called IAccessControl::IsAccessPermitted was not the trustee provided to the method
    //
    CO_E_TRUSTEEDOESNTMATCHCLIENT = 0x80010127L,

    //
    // MessageId: CO_E_FAILEDTOQUERYCLIENTBLANKET
    //
    // MessageText:
    //
    // Unable to obtain the client's security blanket
    //
    CO_E_FAILEDTOQUERYCLIENTBLANKET = 0x80010128L,

    //
    // MessageId: CO_E_FAILEDTOSETDACL
    //
    // MessageText:
    //
    // Unable to set a discretionary ACL into a security descriptor
    //
    CO_E_FAILEDTOSETDACL = 0x80010129L,

    //
    // MessageId: CO_E_ACCESSCHECKFAILED
    //
    // MessageText:
    //
    // The system function, AccessCheck, returned false
    //
    CO_E_ACCESSCHECKFAILED = 0x8001012AL,

    //
    // MessageId: CO_E_NETACCESSAPIFAILED
    //
    // MessageText:
    //
    // Either NetAccessDel or NetAccessAdd returned an error code.
    //
    CO_E_NETACCESSAPIFAILED = 0x8001012BL,

    //
    // MessageId: CO_E_WRONGTRUSTEENAMESYNTAX
    //
    // MessageText:
    //
    // One of the trustee strings provided by the user did not conform to the <Domain>\<Name> syntax and it was not the "*" string
    //
    CO_E_WRONGTRUSTEENAMESYNTAX = 0x8001012CL,

    //
    // MessageId: CO_E_INVALIDSID
    //
    // MessageText:
    //
    // One of the security identifiers provided by the user was invalid
    //
    CO_E_INVALIDSID = 0x8001012DL,

    //
    // MessageId: CO_E_CONVERSIONFAILED
    //
    // MessageText:
    //
    // Unable to convert a wide character trustee string to a multibyte trustee string
    //
    CO_E_CONVERSIONFAILED = 0x8001012EL,

    //
    // MessageId: CO_E_NOMATCHINGSIDFOUND
    //
    // MessageText:
    //
    // Unable to find a security identifier that corresponds to a trustee string provided by the user
    //
    CO_E_NOMATCHINGSIDFOUND = 0x8001012FL,

    //
    // MessageId: CO_E_LOOKUPACCSIDFAILED
    //
    // MessageText:
    //
    // The system function, LookupAccountSID, failed
    //
    CO_E_LOOKUPACCSIDFAILED = 0x80010130L,

    //
    // MessageId: CO_E_NOMATCHINGNAMEFOUND
    //
    // MessageText:
    //
    // Unable to find a trustee name that corresponds to a security identifier provided by the user
    //
    CO_E_NOMATCHINGNAMEFOUND = 0x80010131L,

    //
    // MessageId: CO_E_LOOKUPACCNAMEFAILED
    //
    // MessageText:
    //
    // The system function, LookupAccountName, failed
    //
    CO_E_LOOKUPACCNAMEFAILED = 0x80010132L,

    //
    // MessageId: CO_E_SETSERLHNDLFAILED
    //
    // MessageText:
    //
    // Unable to set or reset a serialization handle
    //
    CO_E_SETSERLHNDLFAILED = 0x80010133L,

    //
    // MessageId: CO_E_FAILEDTOGETWINDIR
    //
    // MessageText:
    //
    // Unable to obtain the Windows directory
    //
    CO_E_FAILEDTOGETWINDIR = 0x80010134L,

    //
    // MessageId: CO_E_PATHTOOLONG
    //
    // MessageText:
    //
    // Path too long
    //
    CO_E_PATHTOOLONG = 0x80010135L,

    //
    // MessageId: CO_E_FAILEDTOGENUUID
    //
    // MessageText:
    //
    // Unable to generate a uuid.
    //
    CO_E_FAILEDTOGENUUID = 0x80010136L,

    //
    // MessageId: CO_E_FAILEDTOCREATEFILE
    //
    // MessageText:
    //
    // Unable to create file
    //
    CO_E_FAILEDTOCREATEFILE = 0x80010137L,

    //
    // MessageId: CO_E_FAILEDTOCLOSEHANDLE
    //
    // MessageText:
    //
    // Unable to close a serialization handle or a file handle.
    //
    CO_E_FAILEDTOCLOSEHANDLE = 0x80010138L,

    //
    // MessageId: CO_E_EXCEEDSYSACLLIMIT
    //
    // MessageText:
    //
    // The number of ACEs in an ACL exceeds the system limit.
    //
    CO_E_EXCEEDSYSACLLIMIT = 0x80010139L,

    //
    // MessageId: CO_E_ACESINWRONGORDER
    //
    // MessageText:
    //
    // Not all the DENY_ACCESS ACEs are arranged in front of the GRANT_ACCESS ACEs in the stream.
    //
    CO_E_ACESINWRONGORDER = 0x8001013AL,

    //
    // MessageId: CO_E_INCOMPATIBLESTREAMVERSION
    //
    // MessageText:
    //
    // The version of ACL format in the stream is not supported by this implementation of IAccessControl
    //
    CO_E_INCOMPATIBLESTREAMVERSION = 0x8001013BL,

    //
    // MessageId: CO_E_FAILEDTOOPENPROCESSTOKEN
    //
    // MessageText:
    //
    // Unable to open the access token of the server process
    //
    CO_E_FAILEDTOOPENPROCESSTOKEN = 0x8001013CL,

    //
    // MessageId: CO_E_DECODEFAILED
    //
    // MessageText:
    //
    // Unable to decode the ACL in the stream provided by the user
    //
    CO_E_DECODEFAILED = 0x8001013DL,

    //
    // MessageId: CO_E_ACNOTINITIALIZED
    //
    // MessageText:
    //
    // The COM IAccessControl object is not initialized
    //
    CO_E_ACNOTINITIALIZED = 0x8001013FL,

    //
    // MessageId: CO_E_CANCEL_DISABLED
    //
    // MessageText:
    //
    // Call Cancellation is disabled
    //
    CO_E_CANCEL_DISABLED = 0x80010140L,

    //
    // MessageId: RPC_E_UNEXPECTED
    //
    // MessageText:
    //
    // An internal error occurred.
    //
    RPC_E_UNEXPECTED = 0x8001FFFFL,

    //////////////////////////////////////
    //                                  //
    // Additional Security Status Codes //
    //                                  //
    // Facility=Security                //
    //                                  //
    //////////////////////////////////////

    //
    // MessageId: ERROR_AUDITING_DISABLED
    //
    // MessageText:
    //
    // The specified event is currently not being audited.
    //
    ERROR_AUDITING_DISABLED = 0xC0090001L,

    //
    // MessageId: ERROR_ALL_SIDS_FILTERED
    //
    // MessageText:
    //
    // The SID filtering operation removed all SIDs.
    //
    ERROR_ALL_SIDS_FILTERED = 0xC0090002L,

    //
    // MessageId: ERROR_BIZRULES_NOT_ENABLED
    //
    // MessageText:
    //
    // Business rule scripts are disabled for the calling application.
    //
    ERROR_BIZRULES_NOT_ENABLED = 0xC0090003L,

    /////////////////////////////////////////////
    //                                         //
    // end of Additional Security Status Codes //
    //                                         //
    /////////////////////////////////////////////

    /////////////////
    //
    //  FACILITY_SSPI
    //
    /////////////////

    //
    // MessageId: NTE_BAD_UID
    //
    // MessageText:
    //
    // Bad UID.
    //
    NTE_BAD_UID = 0x80090001L,

    //
    // MessageId: NTE_BAD_HASH
    //
    // MessageText:
    //
    // Bad Hash.
    //
    NTE_BAD_HASH = 0x80090002L,

    //
    // MessageId: NTE_BAD_KEY
    //
    // MessageText:
    //
    // Bad Key.
    //
    NTE_BAD_KEY = 0x80090003L,

    //
    // MessageId: NTE_BAD_LEN
    //
    // MessageText:
    //
    // Bad Length.
    //
    NTE_BAD_LEN = 0x80090004L,

    //
    // MessageId: NTE_BAD_DATA
    //
    // MessageText:
    //
    // Bad Data.
    //
    NTE_BAD_DATA = 0x80090005L,

    //
    // MessageId: NTE_BAD_SIGNATURE
    //
    // MessageText:
    //
    // Invalid Signature.
    //
    NTE_BAD_SIGNATURE = 0x80090006L,

    //
    // MessageId: NTE_BAD_VER
    //
    // MessageText:
    //
    // Bad Version of provider.
    //
    NTE_BAD_VER = 0x80090007L,

    //
    // MessageId: NTE_BAD_ALGID
    //
    // MessageText:
    //
    // Invalid algorithm specified.
    //
    NTE_BAD_ALGID = 0x80090008L,

    //
    // MessageId: NTE_BAD_FLAGS
    //
    // MessageText:
    //
    // Invalid flags specified.
    //
    NTE_BAD_FLAGS = 0x80090009L,

    //
    // MessageId: NTE_BAD_TYPE
    //
    // MessageText:
    //
    // Invalid type specified.
    //
    NTE_BAD_TYPE = 0x8009000AL,

    //
    // MessageId: NTE_BAD_KEY_STATE
    //
    // MessageText:
    //
    // Key not valid for use in specified state.
    //
    NTE_BAD_KEY_STATE = 0x8009000BL,

    //
    // MessageId: NTE_BAD_HASH_STATE
    //
    // MessageText:
    //
    // Hash not valid for use in specified state.
    //
    NTE_BAD_HASH_STATE = 0x8009000CL,

    //
    // MessageId: NTE_NO_KEY
    //
    // MessageText:
    //
    // Key does not exist.
    //
    NTE_NO_KEY = 0x8009000DL,

    //
    // MessageId: NTE_NO_MEMORY
    //
    // MessageText:
    //
    // Insufficient memory available for the operation.
    //
    NTE_NO_MEMORY = 0x8009000EL,

    //
    // MessageId: NTE_EXISTS
    //
    // MessageText:
    //
    // Object already exists.
    //
    NTE_EXISTS = 0x8009000FL,

    //
    // MessageId: NTE_PERM
    //
    // MessageText:
    //
    // Access denied.
    //
    NTE_PERM = 0x80090010L,

    //
    // MessageId: NTE_NOT_FOUND
    //
    // MessageText:
    //
    // Object was not found.
    //
    NTE_NOT_FOUND = 0x80090011L,

    //
    // MessageId: NTE_DOUBLE_ENCRYPT
    //
    // MessageText:
    //
    // Data already encrypted.
    //
    NTE_DOUBLE_ENCRYPT = 0x80090012L,

    //
    // MessageId: NTE_BAD_PROVIDER
    //
    // MessageText:
    //
    // Invalid provider specified.
    //
    NTE_BAD_PROVIDER = 0x80090013L,

    //
    // MessageId: NTE_BAD_PROV_TYPE
    //
    // MessageText:
    //
    // Invalid provider type specified.
    //
    NTE_BAD_PROV_TYPE = 0x80090014L,

    //
    // MessageId: NTE_BAD_PUBLIC_KEY
    //
    // MessageText:
    //
    // Provider's public key is invalid.
    //
    NTE_BAD_PUBLIC_KEY = 0x80090015L,

    //
    // MessageId: NTE_BAD_KEYSET
    //
    // MessageText:
    //
    // Keyset does not exist
    //
    NTE_BAD_KEYSET = 0x80090016L,

    //
    // MessageId: NTE_PROV_TYPE_NOT_DEF
    //
    // MessageText:
    //
    // Provider type not defined.
    //
    NTE_PROV_TYPE_NOT_DEF = 0x80090017L,

    //
    // MessageId: NTE_PROV_TYPE_ENTRY_BAD
    //
    // MessageText:
    //
    // Provider type as registered is invalid.
    //
    NTE_PROV_TYPE_ENTRY_BAD = 0x80090018L,

    //
    // MessageId: NTE_KEYSET_NOT_DEF
    //
    // MessageText:
    //
    // The keyset is not defined.
    //
    NTE_KEYSET_NOT_DEF = 0x80090019L,

    //
    // MessageId: NTE_KEYSET_ENTRY_BAD
    //
    // MessageText:
    //
    // Keyset as registered is invalid.
    //
    NTE_KEYSET_ENTRY_BAD = 0x8009001AL,

    //
    // MessageId: NTE_PROV_TYPE_NO_MATCH
    //
    // MessageText:
    //
    // Provider type does not match registered value.
    //
    NTE_PROV_TYPE_NO_MATCH = 0x8009001BL,

    //
    // MessageId: NTE_SIGNATURE_FILE_BAD
    //
    // MessageText:
    //
    // The digital signature file is corrupt.
    //
    NTE_SIGNATURE_FILE_BAD = 0x8009001CL,

    //
    // MessageId: NTE_PROVIDER_DLL_FAIL
    //
    // MessageText:
    //
    // Provider DLL failed to initialize correctly.
    //
    NTE_PROVIDER_DLL_FAIL = 0x8009001DL,

    //
    // MessageId: NTE_PROV_DLL_NOT_FOUND
    //
    // MessageText:
    //
    // Provider DLL could not be found.
    //
    NTE_PROV_DLL_NOT_FOUND = 0x8009001EL,

    //
    // MessageId: NTE_BAD_KEYSET_PARAM
    //
    // MessageText:
    //
    // The Keyset parameter is invalid.
    //
    NTE_BAD_KEYSET_PARAM = 0x8009001FL,

    //
    // MessageId: NTE_FAIL
    //
    // MessageText:
    //
    // An internal error occurred.
    //
    NTE_FAIL = 0x80090020L,

    //
    // MessageId: NTE_SYS_ERR
    //
    // MessageText:
    //
    // A base error occurred.
    //
    NTE_SYS_ERR = 0x80090021L,

    //
    // MessageId: NTE_SILENT_CONTEXT
    //
    // MessageText:
    //
    // Provider could not perform the action since the context was acquired as silent.
    //
    NTE_SILENT_CONTEXT = 0x80090022L,

    //
    // MessageId: NTE_TOKEN_KEYSET_STORAGE_FULL
    //
    // MessageText:
    //
    // The security token does not have storage space available for an additional container.
    //
    NTE_TOKEN_KEYSET_STORAGE_FULL = 0x80090023L,

    //
    // MessageId: NTE_TEMPORARY_PROFILE
    //
    // MessageText:
    //
    // The profile for the user is a temporary profile.
    //
    NTE_TEMPORARY_PROFILE = 0x80090024L,

    //
    // MessageId: NTE_FIXEDPARAMETER
    //
    // MessageText:
    //
    // The key parameters could not be set because the CSP uses fixed parameters.
    //
    NTE_FIXEDPARAMETER = 0x80090025L,

    //
    // MessageId: NTE_INVALID_HANDLE
    //
    // MessageText:
    //
    // The supplied handle is invalid.
    //
    NTE_INVALID_HANDLE = 0x80090026L,

    //
    // MessageId: NTE_INVALID_PARAMETER
    //
    // MessageText:
    //
    // The parameter is incorrect.
    //
    NTE_INVALID_PARAMETER = 0x80090027L,

    //
    // MessageId: NTE_BUFFER_TOO_SMALL
    //
    // MessageText:
    //
    // The buffer supplied to a function was too small.
    //
    NTE_BUFFER_TOO_SMALL = 0x80090028L,

    //
    // MessageId: NTE_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The requested operation is not supported.
    //
    NTE_NOT_SUPPORTED = 0x80090029L,

    //
    // MessageId: NTE_NO_MORE_ITEMS
    //
    // MessageText:
    //
    // No more data is available.
    //
    NTE_NO_MORE_ITEMS = 0x8009002AL,

    //
    // MessageId: NTE_BUFFERS_OVERLAP
    //
    // MessageText:
    //
    // The supplied buffers overlap incorrectly.
    //
    NTE_BUFFERS_OVERLAP = 0x8009002BL,

    //
    // MessageId: NTE_DECRYPTION_FAILURE
    //
    // MessageText:
    //
    // The specified data could not be decrypted.
    //
    NTE_DECRYPTION_FAILURE = 0x8009002CL,

    //
    // MessageId: NTE_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal consistency check failed.
    //
    NTE_INTERNAL_ERROR = 0x8009002DL,

    //
    // MessageId: NTE_UI_REQUIRED
    //
    // MessageText:
    //
    // This operation requires input from the user.
    //
    NTE_UI_REQUIRED = 0x8009002EL,

    //
    // MessageId: NTE_HMAC_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The cryptographic provider does not support HMAC.
    //
    NTE_HMAC_NOT_SUPPORTED = 0x8009002FL,

    //
    // MessageId: NTE_DEVICE_NOT_READY
    //
    // MessageText:
    //
    // The device that is required by this cryptographic provider is not ready for use.
    //
    NTE_DEVICE_NOT_READY = 0x80090030L,

    //
    // MessageId: NTE_AUTHENTICATION_IGNORED
    //
    // MessageText:
    //
    // The dictionary attack mitigation is triggered and the provided authorization was ignored by the provider.
    //
    NTE_AUTHENTICATION_IGNORED = 0x80090031L,

    //
    // MessageId: NTE_VALIDATION_FAILED
    //
    // MessageText:
    //
    // The validation of the provided data failed the integrity or signature validation.
    //
    NTE_VALIDATION_FAILED = 0x80090032L,

    //
    // MessageId: NTE_INCORRECT_PASSWORD
    //
    // MessageText:
    //
    // Incorrect password.
    //
    NTE_INCORRECT_PASSWORD = 0x80090033L,

    //
    // MessageId: NTE_ENCRYPTION_FAILURE
    //
    // MessageText:
    //
    // Encryption failed.
    //
    NTE_ENCRYPTION_FAILURE = 0x80090034L,

    //
    // MessageId: NTE_DEVICE_NOT_FOUND
    //
    // MessageText:
    //
    // The device that is required by this cryptographic provider is not found on this platform.
    //
    NTE_DEVICE_NOT_FOUND = 0x80090035L,

    //
    // MessageId: SEC_E_INSUFFICIENT_MEMORY
    //
    // MessageText:
    //
    // Not enough memory is available to complete this request
    //
    SEC_E_INSUFFICIENT_MEMORY = 0x80090300L,

    //
    // MessageId: SEC_E_INVALID_HANDLE
    //
    // MessageText:
    //
    // The handle specified is invalid
    //
    SEC_E_INVALID_HANDLE = 0x80090301L,

    //
    // MessageId: SEC_E_UNSUPPORTED_FUNCTION
    //
    // MessageText:
    //
    // The function requested is not supported
    //
    SEC_E_UNSUPPORTED_FUNCTION = 0x80090302L,

    //
    // MessageId: SEC_E_TARGET_UNKNOWN
    //
    // MessageText:
    //
    // The specified target is unknown or unreachable
    //
    SEC_E_TARGET_UNKNOWN = 0x80090303L,

    //
    // MessageId: SEC_E_INTERNAL_ERROR
    //
    // MessageText:
    //
    // The Local Security Authority cannot be contacted
    //
    SEC_E_INTERNAL_ERROR = 0x80090304L,

    //
    // MessageId: SEC_E_SECPKG_NOT_FOUND
    //
    // MessageText:
    //
    // The requested security package does not exist
    //
    SEC_E_SECPKG_NOT_FOUND = 0x80090305L,

    //
    // MessageId: SEC_E_NOT_OWNER
    //
    // MessageText:
    //
    // The caller is not the owner of the desired credentials
    //
    SEC_E_NOT_OWNER = 0x80090306L,

    //
    // MessageId: SEC_E_CANNOT_INSTALL
    //
    // MessageText:
    //
    // The security package failed to initialize, and cannot be installed
    //
    SEC_E_CANNOT_INSTALL = 0x80090307L,

    //
    // MessageId: SEC_E_INVALID_TOKEN
    //
    // MessageText:
    //
    // The token supplied to the function is invalid
    //
    SEC_E_INVALID_TOKEN = 0x80090308L,

    //
    // MessageId: SEC_E_CANNOT_PACK
    //
    // MessageText:
    //
    // The security package is not able to marshall the logon buffer, so the logon attempt has failed
    //
    SEC_E_CANNOT_PACK = 0x80090309L,

    //
    // MessageId: SEC_E_QOP_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The per-message Quality of Protection is not supported by the security package
    //
    SEC_E_QOP_NOT_SUPPORTED = 0x8009030AL,

    //
    // MessageId: SEC_E_NO_IMPERSONATION
    //
    // MessageText:
    //
    // The security context does not allow impersonation of the client
    //
    SEC_E_NO_IMPERSONATION = 0x8009030BL,

    //
    // MessageId: SEC_E_LOGON_DENIED
    //
    // MessageText:
    //
    // The logon attempt failed
    //
    SEC_E_LOGON_DENIED = 0x8009030CL,

    //
    // MessageId: SEC_E_UNKNOWN_CREDENTIALS
    //
    // MessageText:
    //
    // The credentials supplied to the package were not recognized
    //
    SEC_E_UNKNOWN_CREDENTIALS = 0x8009030DL,

    //
    // MessageId: SEC_E_NO_CREDENTIALS
    //
    // MessageText:
    //
    // No credentials are available in the security package
    //
    SEC_E_NO_CREDENTIALS = 0x8009030EL,

    //
    // MessageId: SEC_E_MESSAGE_ALTERED
    //
    // MessageText:
    //
    // The message or signature supplied for verification has been altered
    //
    SEC_E_MESSAGE_ALTERED = 0x8009030FL,

    //
    // MessageId: SEC_E_OUT_OF_SEQUENCE
    //
    // MessageText:
    //
    // The message supplied for verification is out of sequence
    //
    SEC_E_OUT_OF_SEQUENCE = 0x80090310L,

    //
    // MessageId: SEC_E_NO_AUTHENTICATING_AUTHORITY
    //
    // MessageText:
    //
    // No authority could be contacted for authentication.
    //
    SEC_E_NO_AUTHENTICATING_AUTHORITY = 0x80090311L,

    //
    // MessageId: SEC_I_CONTINUE_NEEDED
    //
    // MessageText:
    //
    // The function completed successfully, but must be called again to complete the context
    //
    SEC_I_CONTINUE_NEEDED = 0x00090312L,

    //
    // MessageId: SEC_I_COMPLETE_NEEDED
    //
    // MessageText:
    //
    // The function completed successfully, but CompleteToken must be called
    //
    SEC_I_COMPLETE_NEEDED = 0x00090313L,

    //
    // MessageId: SEC_I_COMPLETE_AND_CONTINUE
    //
    // MessageText:
    //
    // The function completed successfully, but both CompleteToken and this function must be called to complete the context
    //
    SEC_I_COMPLETE_AND_CONTINUE = 0x00090314L,

    //
    // MessageId: SEC_I_LOCAL_LOGON
    //
    // MessageText:
    //
    // The logon was completed, but no network authority was available. The logon was made using locally known information
    //
    SEC_I_LOCAL_LOGON = 0x00090315L,

    //
    // MessageId: SEC_E_BAD_PKGID
    //
    // MessageText:
    //
    // The requested security package does not exist
    //
    SEC_E_BAD_PKGID = 0x80090316L,

    //
    // MessageId: SEC_E_CONTEXT_EXPIRED
    //
    // MessageText:
    //
    // The context has expired and can no longer be used.
    //
    SEC_E_CONTEXT_EXPIRED = 0x80090317L,

    //
    // MessageId: SEC_I_CONTEXT_EXPIRED
    //
    // MessageText:
    //
    // The context has expired and can no longer be used.
    //
    SEC_I_CONTEXT_EXPIRED = 0x00090317L,

    //
    // MessageId: SEC_E_INCOMPLETE_MESSAGE
    //
    // MessageText:
    //
    // The supplied message is incomplete. The signature was not verified.
    //
    SEC_E_INCOMPLETE_MESSAGE = 0x80090318L,

    //
    // MessageId: SEC_E_INCOMPLETE_CREDENTIALS
    //
    // MessageText:
    //
    // The credentials supplied were not complete, and could not be verified. The context could not be initialized.
    //
    SEC_E_INCOMPLETE_CREDENTIALS = 0x80090320L,

    //
    // MessageId: SEC_E_BUFFER_TOO_SMALL
    //
    // MessageText:
    //
    // The buffers supplied to a function was too small.
    //
    SEC_E_BUFFER_TOO_SMALL = 0x80090321L,

    //
    // MessageId: SEC_I_INCOMPLETE_CREDENTIALS
    //
    // MessageText:
    //
    // The credentials supplied were not complete, and could not be verified. Additional information can be returned from the context.
    //
    SEC_I_INCOMPLETE_CREDENTIALS = 0x00090320L,

    //
    // MessageId: SEC_I_RENEGOTIATE
    //
    // MessageText:
    //
    // The context data must be renegotiated with the peer.
    //
    SEC_I_RENEGOTIATE = 0x00090321L,

    //
    // MessageId: SEC_E_WRONG_PRINCIPAL
    //
    // MessageText:
    //
    // The target principal name is incorrect.
    //
    SEC_E_WRONG_PRINCIPAL = 0x80090322L,

    //
    // MessageId: SEC_I_NO_LSA_CONTEXT
    //
    // MessageText:
    //
    // There is no LSA mode context associated with this context.
    //
    SEC_I_NO_LSA_CONTEXT = 0x00090323L,

    //
    // MessageId: SEC_E_TIME_SKEW
    //
    // MessageText:
    //
    // The clocks on the client and server machines are skewed.
    //
    SEC_E_TIME_SKEW = 0x80090324L,

    //
    // MessageId: SEC_E_UNTRUSTED_ROOT
    //
    // MessageText:
    //
    // The certificate chain was issued by an authority that is not trusted.
    //
    SEC_E_UNTRUSTED_ROOT = 0x80090325L,

    //
    // MessageId: SEC_E_ILLEGAL_MESSAGE
    //
    // MessageText:
    //
    // The message received was unexpected or badly formatted.
    //
    SEC_E_ILLEGAL_MESSAGE = 0x80090326L,

    //
    // MessageId: SEC_E_CERT_UNKNOWN
    //
    // MessageText:
    //
    // An unknown error occurred while processing the certificate.
    //
    SEC_E_CERT_UNKNOWN = 0x80090327L,

    //
    // MessageId: SEC_E_CERT_EXPIRED
    //
    // MessageText:
    //
    // The received certificate has expired.
    //
    SEC_E_CERT_EXPIRED = 0x80090328L,

    //
    // MessageId: SEC_E_ENCRYPT_FAILURE
    //
    // MessageText:
    //
    // The specified data could not be encrypted.
    //
    SEC_E_ENCRYPT_FAILURE = 0x80090329L,

    //
    // MessageId: SEC_E_DECRYPT_FAILURE
    //
    // MessageText:
    //
    // The specified data could not be decrypted.
    //
    //
    SEC_E_DECRYPT_FAILURE = 0x80090330L,

    //
    // MessageId: SEC_E_ALGORITHM_MISMATCH
    //
    // MessageText:
    //
    // The client and server cannot communicate, because they do not possess a common algorithm.
    //
    SEC_E_ALGORITHM_MISMATCH = 0x80090331L,

    //
    // MessageId: SEC_E_SECURITY_QOS_FAILED
    //
    // MessageText:
    //
    // The security context could not be established due to a failure in the requested quality of service (e.g. mutual authentication or delegation).
    //
    SEC_E_SECURITY_QOS_FAILED = 0x80090332L,

    //
    // MessageId: SEC_E_UNFINISHED_CONTEXT_DELETED
    //
    // MessageText:
    //
    // A security context was deleted before the context was completed. This is considered a logon failure.
    //
    SEC_E_UNFINISHED_CONTEXT_DELETED = 0x80090333L,

    //
    // MessageId: SEC_E_NO_TGT_REPLY
    //
    // MessageText:
    //
    // The client is trying to negotiate a context and the server requires user-to-user but didn't send a TGT reply.
    //
    SEC_E_NO_TGT_REPLY = 0x80090334L,

    //
    // MessageId: SEC_E_NO_IP_ADDRESSES
    //
    // MessageText:
    //
    // Unable to accomplish the requested task because the local machine does not have any IP addresses.
    //
    SEC_E_NO_IP_ADDRESSES = 0x80090335L,

    //
    // MessageId: SEC_E_WRONG_CREDENTIAL_HANDLE
    //
    // MessageText:
    //
    // The supplied credential handle does not match the credential associated with the security context.
    //
    SEC_E_WRONG_CREDENTIAL_HANDLE = 0x80090336L,

    //
    // MessageId: SEC_E_CRYPTO_SYSTEM_INVALID
    //
    // MessageText:
    //
    // The crypto system or checksum function is invalid because a required function is unavailable.
    //
    SEC_E_CRYPTO_SYSTEM_INVALID = 0x80090337L,

    //
    // MessageId: SEC_E_MAX_REFERRALS_EXCEEDED
    //
    // MessageText:
    //
    // The number of maximum ticket referrals has been exceeded.
    //
    SEC_E_MAX_REFERRALS_EXCEEDED = 0x80090338L,

    //
    // MessageId: SEC_E_MUST_BE_KDC
    //
    // MessageText:
    //
    // The local machine must be a Kerberos KDC (domain controller) and it is not.
    //
    SEC_E_MUST_BE_KDC = 0x80090339L,

    //
    // MessageId: SEC_E_STRONG_CRYPTO_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The other end of the security negotiation is requires strong crypto but it is not supported on the local machine.
    //
    SEC_E_STRONG_CRYPTO_NOT_SUPPORTED = 0x8009033AL,

    //
    // MessageId: SEC_E_TOO_MANY_PRINCIPALS
    //
    // MessageText:
    //
    // The KDC reply contained more than one principal name.
    //
    SEC_E_TOO_MANY_PRINCIPALS = 0x8009033BL,

    //
    // MessageId: SEC_E_NO_PA_DATA
    //
    // MessageText:
    //
    // Expected to find PA data for a hint of what etype to use, but it was not found.
    //
    SEC_E_NO_PA_DATA = 0x8009033CL,

    //
    // MessageId: SEC_E_PKINIT_NAME_MISMATCH
    //
    // MessageText:
    //
    // The client certificate does not contain a valid UPN, or does not match the client name in the logon request. Please contact your administrator.
    //
    SEC_E_PKINIT_NAME_MISMATCH = 0x8009033DL,

    //
    // MessageId: SEC_E_SMARTCARD_LOGON_REQUIRED
    //
    // MessageText:
    //
    // Smartcard logon is required and was not used.
    //
    SEC_E_SMARTCARD_LOGON_REQUIRED = 0x8009033EL,

    //
    // MessageId: SEC_E_SHUTDOWN_IN_PROGRESS
    //
    // MessageText:
    //
    // A system shutdown is in progress.
    //
    SEC_E_SHUTDOWN_IN_PROGRESS = 0x8009033FL,

    //
    // MessageId: SEC_E_KDC_INVALID_REQUEST
    //
    // MessageText:
    //
    // An invalid request was sent to the KDC.
    //
    SEC_E_KDC_INVALID_REQUEST = 0x80090340L,

    //
    // MessageId: SEC_E_KDC_UNABLE_TO_REFER
    //
    // MessageText:
    //
    // The KDC was unable to generate a referral for the service requested.
    //
    SEC_E_KDC_UNABLE_TO_REFER = 0x80090341L,

    //
    // MessageId: SEC_E_KDC_UNKNOWN_ETYPE
    //
    // MessageText:
    //
    // The encryption type requested is not supported by the KDC.
    //
    SEC_E_KDC_UNKNOWN_ETYPE = 0x80090342L,

    //
    // MessageId: SEC_E_UNSUPPORTED_PREAUTH
    //
    // MessageText:
    //
    // An unsupported preauthentication mechanism was presented to the Kerberos package.
    //
    SEC_E_UNSUPPORTED_PREAUTH = 0x80090343L,

    //
    // MessageId: SEC_E_DELEGATION_REQUIRED
    //
    // MessageText:
    //
    // The requested operation cannot be completed. The computer must be trusted for delegation and the current user account must be configured to allow delegation.
    //
    SEC_E_DELEGATION_REQUIRED = 0x80090345L,

    //
    // MessageId: SEC_E_BAD_BINDINGS
    //
    // MessageText:
    //
    // Client's supplied SSPI channel bindings were incorrect.
    //
    SEC_E_BAD_BINDINGS = 0x80090346L,

    //
    // MessageId: SEC_E_MULTIPLE_ACCOUNTS
    //
    // MessageText:
    //
    // The received certificate was mapped to multiple accounts.
    //
    SEC_E_MULTIPLE_ACCOUNTS = 0x80090347L,

    //
    // MessageId: SEC_E_NO_KERB_KEY
    //
    // MessageText:
    //
    //  SEC_E_NO_KERB_KEY
    //
    SEC_E_NO_KERB_KEY = 0x80090348L,

    //
    // MessageId: SEC_E_CERT_WRONG_USAGE
    //
    // MessageText:
    //
    // The certificate is not valid for the requested usage.
    //
    SEC_E_CERT_WRONG_USAGE = 0x80090349L,

    //
    // MessageId: SEC_E_DOWNGRADE_DETECTED
    //
    // MessageText:
    //
    // The system cannot contact a domain controller to service the authentication request. Please try again later.
    //
    SEC_E_DOWNGRADE_DETECTED = 0x80090350L,

    //
    // MessageId: SEC_E_SMARTCARD_CERT_REVOKED
    //
    // MessageText:
    //
    // The smartcard certificate used for authentication has been revoked. Please contact your system administrator. There may be additional information in the event log.
    //
    SEC_E_SMARTCARD_CERT_REVOKED = 0x80090351L,

    //
    // MessageId: SEC_E_ISSUING_CA_UNTRUSTED
    //
    // MessageText:
    //
    // An untrusted certificate authority was detected while processing the smartcard certificate used for authentication. Please contact your system administrator.
    //
    SEC_E_ISSUING_CA_UNTRUSTED = 0x80090352L,

    //
    // MessageId: SEC_E_REVOCATION_OFFLINE_C
    //
    // MessageText:
    //
    // The revocation status of the smartcard certificate used for authentication could not be determined. Please contact your system administrator.
    //
    SEC_E_REVOCATION_OFFLINE_C = 0x80090353L,

    //
    // MessageId: SEC_E_PKINIT_CLIENT_FAILURE
    //
    // MessageText:
    //
    // The smartcard certificate used for authentication was not trusted. Please contact your system administrator.
    //
    SEC_E_PKINIT_CLIENT_FAILURE = 0x80090354L,

    //
    // MessageId: SEC_E_SMARTCARD_CERT_EXPIRED
    //
    // MessageText:
    //
    // The smartcard certificate used for authentication has expired. Please contact your system administrator.
    //
    SEC_E_SMARTCARD_CERT_EXPIRED = 0x80090355L,

    //
    // MessageId: SEC_E_NO_S4U_PROT_SUPPORT
    //
    // MessageText:
    //
    // The Kerberos subsystem encountered an error. A service for user protocol request was made against a domain controller which does not support service for user.
    //
    SEC_E_NO_S4U_PROT_SUPPORT = 0x80090356L,

    //
    // MessageId: SEC_E_CROSSREALM_DELEGATION_FAILURE
    //
    // MessageText:
    //
    // An attempt was made by this server to make a Kerberos constrained delegation request for a target outside of the server's realm. This is not supported, and indicates a misconfiguration on this server's allowed to delegate to list. Please contact your administrator.
    //
    SEC_E_CROSSREALM_DELEGATION_FAILURE = 0x80090357L,

    //
    // MessageId: SEC_E_REVOCATION_OFFLINE_KDC
    //
    // MessageText:
    //
    // The revocation status of the domain controller certificate used for smartcard authentication could not be determined. There is additional information in the system event log. Please contact your system administrator.
    //
    SEC_E_REVOCATION_OFFLINE_KDC = 0x80090358L,

    //
    // MessageId: SEC_E_ISSUING_CA_UNTRUSTED_KDC
    //
    // MessageText:
    //
    // An untrusted certificate authority was detected while processing the domain controller certificate used for authentication. There is additional information in the system event log. Please contact your system administrator.
    //
    SEC_E_ISSUING_CA_UNTRUSTED_KDC = 0x80090359L,

    //
    // MessageId: SEC_E_KDC_CERT_EXPIRED
    //
    // MessageText:
    //
    // The domain controller certificate used for smartcard logon has expired. Please contact your system administrator with the contents of your system event log.
    //
    SEC_E_KDC_CERT_EXPIRED = 0x8009035AL,

    //
    // MessageId: SEC_E_KDC_CERT_REVOKED
    //
    // MessageText:
    //
    // The domain controller certificate used for smartcard logon has been revoked. Please contact your system administrator with the contents of your system event log.
    //
    SEC_E_KDC_CERT_REVOKED = 0x8009035BL,

    //
    // MessageId: SEC_I_SIGNATURE_NEEDED
    //
    // MessageText:
    //
    // A signature operation must be performed before the user can authenticate.
    //
    SEC_I_SIGNATURE_NEEDED = 0x0009035CL,

    //
    // MessageId: SEC_E_INVALID_PARAMETER
    //
    // MessageText:
    //
    // One or more of the parameters passed to the function was invalid.
    //
    SEC_E_INVALID_PARAMETER = 0x8009035DL,

    //
    // MessageId: SEC_E_DELEGATION_POLICY
    //
    // MessageText:
    //
    // Client policy does not allow credential delegation to target server.
    //
    SEC_E_DELEGATION_POLICY = 0x8009035EL,

    //
    // MessageId: SEC_E_POLICY_NLTM_ONLY
    //
    // MessageText:
    //
    // Client policy does not allow credential delegation to target server with NLTM only authentication.
    //
    SEC_E_POLICY_NLTM_ONLY = 0x8009035FL,

    //
    // MessageId: SEC_I_NO_RENEGOTIATION
    //
    // MessageText:
    //
    // The recipient rejected the renegotiation request.
    //
    SEC_I_NO_RENEGOTIATION = 0x00090360L,

    //
    // MessageId: SEC_E_NO_CONTEXT
    //
    // MessageText:
    //
    // The required security context does not exist.
    //
    SEC_E_NO_CONTEXT = 0x80090361L,

    //
    // MessageId: SEC_E_PKU2U_CERT_FAILURE
    //
    // MessageText:
    //
    // The PKU2U protocol encountered an error while attempting to utilize the associated certificates.
    //
    SEC_E_PKU2U_CERT_FAILURE = 0x80090362L,

    //
    // MessageId: SEC_E_MUTUAL_AUTH_FAILED
    //
    // MessageText:
    //
    // The identity of the server computer could not be verified.
    //
    SEC_E_MUTUAL_AUTH_FAILED = 0x80090363L,

    //
    // MessageId: SEC_I_MESSAGE_FRAGMENT
    //
    // MessageText:
    //
    // The returned buffer is only a fragment of the message.  More fragments need to be returned.
    //
    SEC_I_MESSAGE_FRAGMENT = 0x00090364L,

    //
    // MessageId: SEC_E_ONLY_HTTPS_ALLOWED
    //
    // MessageText:
    //
    // Only https scheme is allowed.
    //
    SEC_E_ONLY_HTTPS_ALLOWED = 0x80090365L,

    //
    // MessageId: SEC_I_CONTINUE_NEEDED_MESSAGE_OK
    //
    // MessageText:
    //
    // The function completed successfully, but must be called again to complete the context.  Early start can be used.
    //
    SEC_I_CONTINUE_NEEDED_MESSAGE_OK = 0x00090366L,

    //
    // MessageId: SEC_E_APPLICATION_PROTOCOL_MISMATCH
    //
    // MessageText:
    //
    // No common application protocol exists between the client and the server. Application protocol negotiation failed.
    //
    SEC_E_APPLICATION_PROTOCOL_MISMATCH = 0x80090367L,

    SEC_E_NO_SPM = SEC_E_INTERNAL_ERROR,
    SEC_E_NOT_SUPPORTED = SEC_E_UNSUPPORTED_FUNCTION,

    //
    // MessageId: CRYPT_E_MSG_ERROR
    //
    // MessageText:
    //
    // An error occurred while performing an operation on a cryptographic message.
    //
    CRYPT_E_MSG_ERROR = 0x80091001L,

    //
    // MessageId: CRYPT_E_UNKNOWN_ALGO
    //
    // MessageText:
    //
    // Unknown cryptographic algorithm.
    //
    CRYPT_E_UNKNOWN_ALGO = 0x80091002L,

    //
    // MessageId: CRYPT_E_OID_FORMAT
    //
    // MessageText:
    //
    // The object identifier is poorly formatted.
    //
    CRYPT_E_OID_FORMAT = 0x80091003L,

    //
    // MessageId: CRYPT_E_INVALID_MSG_TYPE
    //
    // MessageText:
    //
    // Invalid cryptographic message type.
    //
    CRYPT_E_INVALID_MSG_TYPE = 0x80091004L,

    //
    // MessageId: CRYPT_E_UNEXPECTED_ENCODING
    //
    // MessageText:
    //
    // Unexpected cryptographic message encoding.
    //
    CRYPT_E_UNEXPECTED_ENCODING = 0x80091005L,

    //
    // MessageId: CRYPT_E_AUTH_ATTR_MISSING
    //
    // MessageText:
    //
    // The cryptographic message does not contain an expected authenticated attribute.
    //
    CRYPT_E_AUTH_ATTR_MISSING = 0x80091006L,

    //
    // MessageId: CRYPT_E_HASH_VALUE
    //
    // MessageText:
    //
    // The hash value is not correct.
    //
    CRYPT_E_HASH_VALUE = 0x80091007L,

    //
    // MessageId: CRYPT_E_INVALID_INDEX
    //
    // MessageText:
    //
    // The index value is not valid.
    //
    CRYPT_E_INVALID_INDEX = 0x80091008L,

    //
    // MessageId: CRYPT_E_ALREADY_DECRYPTED
    //
    // MessageText:
    //
    // The content of the cryptographic message has already been decrypted.
    //
    CRYPT_E_ALREADY_DECRYPTED = 0x80091009L,

    //
    // MessageId: CRYPT_E_NOT_DECRYPTED
    //
    // MessageText:
    //
    // The content of the cryptographic message has not been decrypted yet.
    //
    CRYPT_E_NOT_DECRYPTED = 0x8009100AL,

    //
    // MessageId: CRYPT_E_RECIPIENT_NOT_FOUND
    //
    // MessageText:
    //
    // The enveloped-data message does not contain the specified recipient.
    //
    CRYPT_E_RECIPIENT_NOT_FOUND = 0x8009100BL,

    //
    // MessageId: CRYPT_E_CONTROL_TYPE
    //
    // MessageText:
    //
    // Invalid control type.
    //
    CRYPT_E_CONTROL_TYPE = 0x8009100CL,

    //
    // MessageId: CRYPT_E_ISSUER_SERIALNUMBER
    //
    // MessageText:
    //
    // Invalid issuer and/or serial number.
    //
    CRYPT_E_ISSUER_SERIALNUMBER = 0x8009100DL,

    //
    // MessageId: CRYPT_E_SIGNER_NOT_FOUND
    //
    // MessageText:
    //
    // Cannot find the original signer.
    //
    CRYPT_E_SIGNER_NOT_FOUND = 0x8009100EL,

    //
    // MessageId: CRYPT_E_ATTRIBUTES_MISSING
    //
    // MessageText:
    //
    // The cryptographic message does not contain all of the requested attributes.
    //
    CRYPT_E_ATTRIBUTES_MISSING = 0x8009100FL,

    //
    // MessageId: CRYPT_E_STREAM_MSG_NOT_READY
    //
    // MessageText:
    //
    // The streamed cryptographic message is not ready to return data.
    //
    CRYPT_E_STREAM_MSG_NOT_READY = 0x80091010L,

    //
    // MessageId: CRYPT_E_STREAM_INSUFFICIENT_DATA
    //
    // MessageText:
    //
    // The streamed cryptographic message requires more data to complete the decode operation.
    //
    CRYPT_E_STREAM_INSUFFICIENT_DATA = 0x80091011L,

    //
    // MessageId: CRYPT_I_NEW_PROTECTION_REQUIRED
    //
    // MessageText:
    //
    // The protected data needs to be re-protected.
    //
    CRYPT_I_NEW_PROTECTION_REQUIRED = 0x00091012L,

    //
    // MessageId: CRYPT_E_BAD_LEN
    //
    // MessageText:
    //
    // The length specified for the output data was insufficient.
    //
    CRYPT_E_BAD_LEN = 0x80092001L,

    //
    // MessageId: CRYPT_E_BAD_ENCODE
    //
    // MessageText:
    //
    // An error occurred during encode or decode operation.
    //
    CRYPT_E_BAD_ENCODE = 0x80092002L,

    //
    // MessageId: CRYPT_E_FILE_ERROR
    //
    // MessageText:
    //
    // An error occurred while reading or writing to a file.
    //
    CRYPT_E_FILE_ERROR = 0x80092003L,

    //
    // MessageId: CRYPT_E_NOT_FOUND
    //
    // MessageText:
    //
    // Cannot find object or property.
    //
    CRYPT_E_NOT_FOUND = 0x80092004L,

    //
    // MessageId: CRYPT_E_EXISTS
    //
    // MessageText:
    //
    // The object or property already exists.
    //
    CRYPT_E_EXISTS = 0x80092005L,

    //
    // MessageId: CRYPT_E_NO_PROVIDER
    //
    // MessageText:
    //
    // No provider was specified for the store or object.
    //
    CRYPT_E_NO_PROVIDER = 0x80092006L,

    //
    // MessageId: CRYPT_E_SELF_SIGNED
    //
    // MessageText:
    //
    // The specified certificate is self signed.
    //
    CRYPT_E_SELF_SIGNED = 0x80092007L,

    //
    // MessageId: CRYPT_E_DELETED_PREV
    //
    // MessageText:
    //
    // The previous certificate or CRL context was deleted.
    //
    CRYPT_E_DELETED_PREV = 0x80092008L,

    //
    // MessageId: CRYPT_E_NO_MATCH
    //
    // MessageText:
    //
    // Cannot find the requested object.
    //
    CRYPT_E_NO_MATCH = 0x80092009L,

    //
    // MessageId: CRYPT_E_UNEXPECTED_MSG_TYPE
    //
    // MessageText:
    //
    // The certificate does not have a property that references a private key.
    //
    CRYPT_E_UNEXPECTED_MSG_TYPE = 0x8009200AL,

    //
    // MessageId: CRYPT_E_NO_KEY_PROPERTY
    //
    // MessageText:
    //
    // Cannot find the certificate and private key for decryption.
    //
    CRYPT_E_NO_KEY_PROPERTY = 0x8009200BL,

    //
    // MessageId: CRYPT_E_NO_DECRYPT_CERT
    //
    // MessageText:
    //
    // Cannot find the certificate and private key to use for decryption.
    //
    CRYPT_E_NO_DECRYPT_CERT = 0x8009200CL,

    //
    // MessageId: CRYPT_E_BAD_MSG
    //
    // MessageText:
    //
    // Not a cryptographic message or the cryptographic message is not formatted correctly.
    //
    CRYPT_E_BAD_MSG = 0x8009200DL,

    //
    // MessageId: CRYPT_E_NO_SIGNER
    //
    // MessageText:
    //
    // The signed cryptographic message does not have a signer for the specified signer index.
    //
    CRYPT_E_NO_SIGNER = 0x8009200EL,

    //
    // MessageId: CRYPT_E_PENDING_CLOSE
    //
    // MessageText:
    //
    // Final closure is pending until additional frees or closes.
    //
    CRYPT_E_PENDING_CLOSE = 0x8009200FL,

    //
    // MessageId: CRYPT_E_REVOKED
    //
    // MessageText:
    //
    // The certificate is revoked.
    //
    CRYPT_E_REVOKED = 0x80092010L,

    //
    // MessageId: CRYPT_E_NO_REVOCATION_DLL
    //
    // MessageText:
    //
    // No Dll or exported function was found to verify revocation.
    //
    CRYPT_E_NO_REVOCATION_DLL = 0x80092011L,

    //
    // MessageId: CRYPT_E_NO_REVOCATION_CHECK
    //
    // MessageText:
    //
    // The revocation function was unable to check revocation for the certificate.
    //
    CRYPT_E_NO_REVOCATION_CHECK = 0x80092012L,

    //
    // MessageId: CRYPT_E_REVOCATION_OFFLINE
    //
    // MessageText:
    //
    // The revocation function was unable to check revocation because the revocation server was offline.
    //
    CRYPT_E_REVOCATION_OFFLINE = 0x80092013L,

    //
    // MessageId: CRYPT_E_NOT_IN_REVOCATION_DATABASE
    //
    // MessageText:
    //
    // The certificate is not in the revocation server's database.
    //
    CRYPT_E_NOT_IN_REVOCATION_DATABASE = 0x80092014L,

    //
    // MessageId: CRYPT_E_INVALID_NUMERIC_STRING
    //
    // MessageText:
    //
    // The string contains a non-numeric character.
    //
    CRYPT_E_INVALID_NUMERIC_STRING = 0x80092020L,

    //
    // MessageId: CRYPT_E_INVALID_PRINTABLE_STRING
    //
    // MessageText:
    //
    // The string contains a non-printable character.
    //
    CRYPT_E_INVALID_PRINTABLE_STRING = 0x80092021L,

    //
    // MessageId: CRYPT_E_INVALID_IA5_STRING
    //
    // MessageText:
    //
    // The string contains a character not in the 7 bit ASCII character set.
    //
    CRYPT_E_INVALID_IA5_STRING = 0x80092022L,

    //
    // MessageId: CRYPT_E_INVALID_X500_STRING
    //
    // MessageText:
    //
    // The string contains an invalid X500 name attribute key, oid, value or delimiter.
    //
    CRYPT_E_INVALID_X500_STRING = 0x80092023L,

    //
    // MessageId: CRYPT_E_NOT_CHAR_STRING
    //
    // MessageText:
    //
    // The dwValueType for the CERT_NAME_VALUE is not one of the character strings. Most likely it is either a CERT_RDN_ENCODED_BLOB or CERT_RDN_OCTET_STRING.
    //
    CRYPT_E_NOT_CHAR_STRING = 0x80092024L,

    //
    // MessageId: CRYPT_E_FILERESIZED
    //
    // MessageText:
    //
    // The Put operation cannot continue. The file needs to be resized. However, there is already a signature present. A complete signing operation must be done.
    //
    CRYPT_E_FILERESIZED = 0x80092025L,

    //
    // MessageId: CRYPT_E_SECURITY_SETTINGS
    //
    // MessageText:
    //
    // The cryptographic operation failed due to a local security option setting.
    //
    CRYPT_E_SECURITY_SETTINGS = 0x80092026L,

    //
    // MessageId: CRYPT_E_NO_VERIFY_USAGE_DLL
    //
    // MessageText:
    //
    // No DLL or exported function was found to verify subject usage.
    //
    CRYPT_E_NO_VERIFY_USAGE_DLL = 0x80092027L,

    //
    // MessageId: CRYPT_E_NO_VERIFY_USAGE_CHECK
    //
    // MessageText:
    //
    // The called function was unable to do a usage check on the subject.
    //
    CRYPT_E_NO_VERIFY_USAGE_CHECK = 0x80092028L,

    //
    // MessageId: CRYPT_E_VERIFY_USAGE_OFFLINE
    //
    // MessageText:
    //
    // Since the server was offline, the called function was unable to complete the usage check.
    //
    CRYPT_E_VERIFY_USAGE_OFFLINE = 0x80092029L,

    //
    // MessageId: CRYPT_E_NOT_IN_CTL
    //
    // MessageText:
    //
    // The subject was not found in a Certificate Trust List (CTL).
    //
    CRYPT_E_NOT_IN_CTL = 0x8009202AL,

    //
    // MessageId: CRYPT_E_NO_TRUSTED_SIGNER
    //
    // MessageText:
    //
    // None of the signers of the cryptographic message or certificate trust list is trusted.
    //
    CRYPT_E_NO_TRUSTED_SIGNER = 0x8009202BL,

    //
    // MessageId: CRYPT_E_MISSING_PUBKEY_PARA
    //
    // MessageText:
    //
    // The public key's algorithm parameters are missing.
    //
    CRYPT_E_MISSING_PUBKEY_PARA = 0x8009202CL,

    //
    // MessageId: CRYPT_E_OBJECT_LOCATOR_OBJECT_NOT_FOUND
    //
    // MessageText:
    //
    // An object could not be located using the object locator infrastructure with the given name.
    //
    CRYPT_E_OBJECT_LOCATOR_OBJECT_NOT_FOUND = 0x8009202DL,

    //
    // MessageId: CRYPT_E_OSS_ERROR
    //
    // MessageText:
    //
    // OSS Certificate encode/decode error code base
    //
    // See asn1code.h for a definition of the OSS runtime errors. The OSS error values are offset by CRYPT_E_OSS_ERROR.
    //
    CRYPT_E_OSS_ERROR = 0x80093000L,

    //
    // MessageId: OSS_MORE_BUF
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Output Buffer is too small.
    //
    OSS_MORE_BUF = 0x80093001L,

    //
    // MessageId: OSS_NEGATIVE_UINTEGER
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Signed integer is encoded as a unsigned integer.
    //
    OSS_NEGATIVE_UINTEGER = 0x80093002L,

    //
    // MessageId: OSS_PDU_RANGE
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Unknown ASN.1 data type.
    //
    OSS_PDU_RANGE = 0x80093003L,

    //
    // MessageId: OSS_MORE_INPUT
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Output buffer is too small, the decoded data has been truncated.
    //
    OSS_MORE_INPUT = 0x80093004L,

    //
    // MessageId: OSS_DATA_ERROR
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_DATA_ERROR = 0x80093005L,

    //
    // MessageId: OSS_BAD_ARG
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid argument.
    //
    OSS_BAD_ARG = 0x80093006L,

    //
    // MessageId: OSS_BAD_VERSION
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Encode/Decode version mismatch.
    //
    OSS_BAD_VERSION = 0x80093007L,

    //
    // MessageId: OSS_OUT_MEMORY
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Out of memory.
    //
    OSS_OUT_MEMORY = 0x80093008L,

    //
    // MessageId: OSS_PDU_MISMATCH
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Encode/Decode Error.
    //
    OSS_PDU_MISMATCH = 0x80093009L,

    //
    // MessageId: OSS_LIMITED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Internal Error.
    //
    OSS_LIMITED = 0x8009300AL,

    //
    // MessageId: OSS_BAD_PTR
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_BAD_PTR = 0x8009300BL,

    //
    // MessageId: OSS_BAD_TIME
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_BAD_TIME = 0x8009300CL,

    //
    // MessageId: OSS_INDEFINITE_NOT_SUPPORTED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Unsupported BER indefinite-length encoding.
    //
    OSS_INDEFINITE_NOT_SUPPORTED = 0x8009300DL,

    //
    // MessageId: OSS_MEM_ERROR
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Access violation.
    //
    OSS_MEM_ERROR = 0x8009300EL,

    //
    // MessageId: OSS_BAD_TABLE
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_BAD_TABLE = 0x8009300FL,

    //
    // MessageId: OSS_TOO_LONG
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_TOO_LONG = 0x80093010L,

    //
    // MessageId: OSS_CONSTRAINT_VIOLATED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_CONSTRAINT_VIOLATED = 0x80093011L,

    //
    // MessageId: OSS_FATAL_ERROR
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Internal Error.
    //
    OSS_FATAL_ERROR = 0x80093012L,

    //
    // MessageId: OSS_ACCESS_SERIALIZATION_ERROR
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Multi-threading conflict.
    //
    OSS_ACCESS_SERIALIZATION_ERROR = 0x80093013L,

    //
    // MessageId: OSS_NULL_TBL
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_NULL_TBL = 0x80093014L,

    //
    // MessageId: OSS_NULL_FCN
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_NULL_FCN = 0x80093015L,

    //
    // MessageId: OSS_BAD_ENCRULES
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_BAD_ENCRULES = 0x80093016L,

    //
    // MessageId: OSS_UNAVAIL_ENCRULES
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Encode/Decode function not implemented.
    //
    OSS_UNAVAIL_ENCRULES = 0x80093017L,

    //
    // MessageId: OSS_CANT_OPEN_TRACE_WINDOW
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Trace file error.
    //
    OSS_CANT_OPEN_TRACE_WINDOW = 0x80093018L,

    //
    // MessageId: OSS_UNIMPLEMENTED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Function not implemented.
    //
    OSS_UNIMPLEMENTED = 0x80093019L,

    //
    // MessageId: OSS_OID_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_OID_DLL_NOT_LINKED = 0x8009301AL,

    //
    // MessageId: OSS_CANT_OPEN_TRACE_FILE
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Trace file error.
    //
    OSS_CANT_OPEN_TRACE_FILE = 0x8009301BL,

    //
    // MessageId: OSS_TRACE_FILE_ALREADY_OPEN
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Trace file error.
    //
    OSS_TRACE_FILE_ALREADY_OPEN = 0x8009301CL,

    //
    // MessageId: OSS_TABLE_MISMATCH
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_TABLE_MISMATCH = 0x8009301DL,

    //
    // MessageId: OSS_TYPE_NOT_SUPPORTED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Invalid data.
    //
    OSS_TYPE_NOT_SUPPORTED = 0x8009301EL,

    //
    // MessageId: OSS_REAL_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_REAL_DLL_NOT_LINKED = 0x8009301FL,

    //
    // MessageId: OSS_REAL_CODE_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_REAL_CODE_NOT_LINKED = 0x80093020L,

    //
    // MessageId: OSS_OUT_OF_RANGE
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_OUT_OF_RANGE = 0x80093021L,

    //
    // MessageId: OSS_COPIER_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_COPIER_DLL_NOT_LINKED = 0x80093022L,

    //
    // MessageId: OSS_CONSTRAINT_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_CONSTRAINT_DLL_NOT_LINKED = 0x80093023L,

    //
    // MessageId: OSS_COMPARATOR_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_COMPARATOR_DLL_NOT_LINKED = 0x80093024L,

    //
    // MessageId: OSS_COMPARATOR_CODE_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_COMPARATOR_CODE_NOT_LINKED = 0x80093025L,

    //
    // MessageId: OSS_MEM_MGR_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_MEM_MGR_DLL_NOT_LINKED = 0x80093026L,

    //
    // MessageId: OSS_PDV_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_PDV_DLL_NOT_LINKED = 0x80093027L,

    //
    // MessageId: OSS_PDV_CODE_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_PDV_CODE_NOT_LINKED = 0x80093028L,

    //
    // MessageId: OSS_API_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_API_DLL_NOT_LINKED = 0x80093029L,

    //
    // MessageId: OSS_BERDER_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_BERDER_DLL_NOT_LINKED = 0x8009302AL,

    //
    // MessageId: OSS_PER_DLL_NOT_LINKED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_PER_DLL_NOT_LINKED = 0x8009302BL,

    //
    // MessageId: OSS_OPEN_TYPE_ERROR
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Program link error.
    //
    OSS_OPEN_TYPE_ERROR = 0x8009302CL,

    //
    // MessageId: OSS_MUTEX_NOT_CREATED
    //
    // MessageText:
    //
    // OSS ASN.1 Error: System resource error.
    //
    OSS_MUTEX_NOT_CREATED = 0x8009302DL,

    //
    // MessageId: OSS_CANT_CLOSE_TRACE_FILE
    //
    // MessageText:
    //
    // OSS ASN.1 Error: Trace file error.
    //
    OSS_CANT_CLOSE_TRACE_FILE = 0x8009302EL,

    //
    // MessageId: CRYPT_E_ASN1_ERROR
    //
    // MessageText:
    //
    // ASN1 Certificate encode/decode error code base. The ASN1 error values are offset by CRYPT_E_ASN1_ERROR.
    //
    CRYPT_E_ASN1_ERROR = 0x80093100L,

    //
    // MessageId: CRYPT_E_ASN1_INTERNAL
    //
    // MessageText:
    //
    // ASN1 internal encode or decode error.
    //
    CRYPT_E_ASN1_INTERNAL = 0x80093101L,

    //
    // MessageId: CRYPT_E_ASN1_EOD
    //
    // MessageText:
    //
    // ASN1 unexpected end of data.
    //
    CRYPT_E_ASN1_EOD = 0x80093102L,

    //
    // MessageId: CRYPT_E_ASN1_CORRUPT
    //
    // MessageText:
    //
    // ASN1 corrupted data.
    //
    CRYPT_E_ASN1_CORRUPT = 0x80093103L,

    //
    // MessageId: CRYPT_E_ASN1_LARGE
    //
    // MessageText:
    //
    // ASN1 value too large.
    //
    CRYPT_E_ASN1_LARGE = 0x80093104L,

    //
    // MessageId: CRYPT_E_ASN1_CONSTRAINT
    //
    // MessageText:
    //
    // ASN1 constraint violated.
    //
    CRYPT_E_ASN1_CONSTRAINT = 0x80093105L,

    //
    // MessageId: CRYPT_E_ASN1_MEMORY
    //
    // MessageText:
    //
    // ASN1 out of memory.
    //
    CRYPT_E_ASN1_MEMORY = 0x80093106L,

    //
    // MessageId: CRYPT_E_ASN1_OVERFLOW
    //
    // MessageText:
    //
    // ASN1 buffer overflow.
    //
    CRYPT_E_ASN1_OVERFLOW = 0x80093107L,

    //
    // MessageId: CRYPT_E_ASN1_BADPDU
    //
    // MessageText:
    //
    // ASN1 function not supported for this PDU.
    //
    CRYPT_E_ASN1_BADPDU = 0x80093108L,

    //
    // MessageId: CRYPT_E_ASN1_BADARGS
    //
    // MessageText:
    //
    // ASN1 bad arguments to function call.
    //
    CRYPT_E_ASN1_BADARGS = 0x80093109L,

    //
    // MessageId: CRYPT_E_ASN1_BADREAL
    //
    // MessageText:
    //
    // ASN1 bad real value.
    //
    CRYPT_E_ASN1_BADREAL = 0x8009310AL,

    //
    // MessageId: CRYPT_E_ASN1_BADTAG
    //
    // MessageText:
    //
    // ASN1 bad tag value met.
    //
    CRYPT_E_ASN1_BADTAG = 0x8009310BL,

    //
    // MessageId: CRYPT_E_ASN1_CHOICE
    //
    // MessageText:
    //
    // ASN1 bad choice value.
    //
    CRYPT_E_ASN1_CHOICE = 0x8009310CL,

    //
    // MessageId: CRYPT_E_ASN1_RULE
    //
    // MessageText:
    //
    // ASN1 bad encoding rule.
    //
    CRYPT_E_ASN1_RULE = 0x8009310DL,

    //
    // MessageId: CRYPT_E_ASN1_UTF8
    //
    // MessageText:
    //
    // ASN1 bad unicode (UTF8).
    //
    CRYPT_E_ASN1_UTF8 = 0x8009310EL,

    //
    // MessageId: CRYPT_E_ASN1_PDU_TYPE
    //
    // MessageText:
    //
    // ASN1 bad PDU type.
    //
    CRYPT_E_ASN1_PDU_TYPE = 0x80093133L,

    //
    // MessageId: CRYPT_E_ASN1_NYI
    //
    // MessageText:
    //
    // ASN1 not yet implemented.
    //
    CRYPT_E_ASN1_NYI = 0x80093134L,

    //
    // MessageId: CRYPT_E_ASN1_EXTENDED
    //
    // MessageText:
    //
    // ASN1 skipped unknown extension(s).
    //
    CRYPT_E_ASN1_EXTENDED = 0x80093201L,

    //
    // MessageId: CRYPT_E_ASN1_NOEOD
    //
    // MessageText:
    //
    // ASN1 end of data expected
    //
    CRYPT_E_ASN1_NOEOD = 0x80093202L,

    //
    // MessageId: CERTSRV_E_BAD_REQUESTSUBJECT
    //
    // MessageText:
    //
    // The request subject name is invalid or too long.
    //
    CERTSRV_E_BAD_REQUESTSUBJECT = 0x80094001L,

    //
    // MessageId: CERTSRV_E_NO_REQUEST
    //
    // MessageText:
    //
    // The request does not exist.
    //
    CERTSRV_E_NO_REQUEST = 0x80094002L,

    //
    // MessageId: CERTSRV_E_BAD_REQUESTSTATUS
    //
    // MessageText:
    //
    // The request's current status does not allow this operation.
    //
    CERTSRV_E_BAD_REQUESTSTATUS = 0x80094003L,

    //
    // MessageId: CERTSRV_E_PROPERTY_EMPTY
    //
    // MessageText:
    //
    // The requested property value is empty.
    //
    CERTSRV_E_PROPERTY_EMPTY = 0x80094004L,

    //
    // MessageId: CERTSRV_E_INVALID_CA_CERTIFICATE
    //
    // MessageText:
    //
    // The certification authority's certificate contains invalid data.
    //
    CERTSRV_E_INVALID_CA_CERTIFICATE = 0x80094005L,

    //
    // MessageId: CERTSRV_E_SERVER_SUSPENDED
    //
    // MessageText:
    //
    // Certificate service has been suspended for a database restore operation.
    //
    CERTSRV_E_SERVER_SUSPENDED = 0x80094006L,

    //
    // MessageId: CERTSRV_E_ENCODING_LENGTH
    //
    // MessageText:
    //
    // The certificate contains an encoded length that is potentially incompatible with older enrollment software.
    //
    CERTSRV_E_ENCODING_LENGTH = 0x80094007L,

    //
    // MessageId: CERTSRV_E_ROLECONFLICT
    //
    // MessageText:
    //
    // The operation is denied. The user has multiple roles assigned and the certification authority is configured to enforce role separation.
    //
    CERTSRV_E_ROLECONFLICT = 0x80094008L,

    //
    // MessageId: CERTSRV_E_RESTRICTEDOFFICER
    //
    // MessageText:
    //
    // The operation is denied. It can only be performed by a certificate manager that is allowed to manage certificates for the current requester.
    //
    CERTSRV_E_RESTRICTEDOFFICER = 0x80094009L,

    //
    // MessageId: CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED
    //
    // MessageText:
    //
    // Cannot archive private key. The certification authority is not configured for key archival.
    //
    CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED = 0x8009400AL,

    //
    // MessageId: CERTSRV_E_NO_VALID_KRA
    //
    // MessageText:
    //
    // Cannot archive private key. The certification authority could not verify one or more key recovery certificates.
    //
    CERTSRV_E_NO_VALID_KRA = 0x8009400BL,

    //
    // MessageId: CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL
    //
    // MessageText:
    //
    // The request is incorrectly formatted. The encrypted private key must be in an unauthenticated attribute in an outermost signature.
    //
    CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL = 0x8009400CL,

    //
    // MessageId: CERTSRV_E_NO_CAADMIN_DEFINED
    //
    // MessageText:
    //
    // At least one security principal must have the permission to manage this CA.
    //
    CERTSRV_E_NO_CAADMIN_DEFINED = 0x8009400DL,

    //
    // MessageId: CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE
    //
    // MessageText:
    //
    // The request contains an invalid renewal certificate attribute.
    //
    CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE = 0x8009400EL,

    //
    // MessageId: CERTSRV_E_NO_DB_SESSIONS
    //
    // MessageText:
    //
    // An attempt was made to open a Certification Authority database session, but there are already too many active sessions. The server may need to be configured to allow additional sessions.
    //
    CERTSRV_E_NO_DB_SESSIONS = 0x8009400FL,

    //
    // MessageId: CERTSRV_E_ALIGNMENT_FAULT
    //
    // MessageText:
    //
    // A memory reference caused a data alignment fault.
    //
    CERTSRV_E_ALIGNMENT_FAULT = 0x80094010L,

    //
    // MessageId: CERTSRV_E_ENROLL_DENIED
    //
    // MessageText:
    //
    // The permissions on this certification authority do not allow the current user to enroll for certificates.
    //
    CERTSRV_E_ENROLL_DENIED = 0x80094011L,

    //
    // MessageId: CERTSRV_E_TEMPLATE_DENIED
    //
    // MessageText:
    //
    // The permissions on the certificate template do not allow the current user to enroll for this type of certificate.
    //
    CERTSRV_E_TEMPLATE_DENIED = 0x80094012L,

    //
    // MessageId: CERTSRV_E_DOWNLEVEL_DC_SSL_OR_UPGRADE
    //
    // MessageText:
    //
    // The contacted domain controller cannot support signed LDAP traffic. Update the domain controller or configure Certificate Services to use SSL for Active Directory access.
    //
    CERTSRV_E_DOWNLEVEL_DC_SSL_OR_UPGRADE = 0x80094013L,

    //
    // MessageId: CERTSRV_E_ADMIN_DENIED_REQUEST
    //
    // MessageText:
    //
    // The request was denied by a certificate manager or CA administrator.
    //
    CERTSRV_E_ADMIN_DENIED_REQUEST = 0x80094014L,

    //
    // MessageId: CERTSRV_E_NO_POLICY_SERVER
    //
    // MessageText:
    //
    // An enrollment policy server cannot be located.
    //
    CERTSRV_E_NO_POLICY_SERVER = 0x80094015L,

    //
    // MessageId: CERTSRV_E_WEAK_SIGNATURE_OR_KEY
    //
    // MessageText:
    //
    // A signature algorithm or public key length does not meet the system's minimum required strength.
    //
    CERTSRV_E_WEAK_SIGNATURE_OR_KEY = 0x80094016L,

    //
    // MessageId: CERTSRV_E_KEY_ATTESTATION_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Failed to create an attested key.  This computer or the cryptographic provider may not meet the hardware requirements to support key attestation.
    //
    CERTSRV_E_KEY_ATTESTATION_NOT_SUPPORTED = 0x80094017L,

    //
    // MessageId: CERTSRV_E_ENCRYPTION_CERT_REQUIRED
    //
    // MessageText:
    //
    // No encryption certificate was specified.
    //
    CERTSRV_E_ENCRYPTION_CERT_REQUIRED = 0x80094018L,

    //
    // MessageId: CERTSRV_E_UNSUPPORTED_CERT_TYPE
    //
    // MessageText:
    //
    // The requested certificate template is not supported by this CA.
    //
    CERTSRV_E_UNSUPPORTED_CERT_TYPE = 0x80094800L,

    //
    // MessageId: CERTSRV_E_NO_CERT_TYPE
    //
    // MessageText:
    //
    // The request contains no certificate template information.
    //
    CERTSRV_E_NO_CERT_TYPE = 0x80094801L,

    //
    // MessageId: CERTSRV_E_TEMPLATE_CONFLICT
    //
    // MessageText:
    //
    // The request contains conflicting template information.
    //
    CERTSRV_E_TEMPLATE_CONFLICT = 0x80094802L,

    //
    // MessageId: CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED
    //
    // MessageText:
    //
    // The request is missing a required Subject Alternate name extension.
    //
    CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED = 0x80094803L,

    //
    // MessageId: CERTSRV_E_ARCHIVED_KEY_REQUIRED
    //
    // MessageText:
    //
    // The request is missing a required private key for archival by the server.
    //
    CERTSRV_E_ARCHIVED_KEY_REQUIRED = 0x80094804L,

    //
    // MessageId: CERTSRV_E_SMIME_REQUIRED
    //
    // MessageText:
    //
    // The request is missing a required SMIME capabilities extension.
    //
    CERTSRV_E_SMIME_REQUIRED = 0x80094805L,

    //
    // MessageId: CERTSRV_E_BAD_RENEWAL_SUBJECT
    //
    // MessageText:
    //
    // The request was made on behalf of a subject other than the caller. The certificate template must be configured to require at least one signature to authorize the request.
    //
    CERTSRV_E_BAD_RENEWAL_SUBJECT = 0x80094806L,

    //
    // MessageId: CERTSRV_E_BAD_TEMPLATE_VERSION
    //
    // MessageText:
    //
    // The request template version is newer than the supported template version.
    //
    CERTSRV_E_BAD_TEMPLATE_VERSION = 0x80094807L,

    //
    // MessageId: CERTSRV_E_TEMPLATE_POLICY_REQUIRED
    //
    // MessageText:
    //
    // The template is missing a required signature policy attribute.
    //
    CERTSRV_E_TEMPLATE_POLICY_REQUIRED = 0x80094808L,

    //
    // MessageId: CERTSRV_E_SIGNATURE_POLICY_REQUIRED
    //
    // MessageText:
    //
    // The request is missing required signature policy information.
    //
    CERTSRV_E_SIGNATURE_POLICY_REQUIRED = 0x80094809L,

    //
    // MessageId: CERTSRV_E_SIGNATURE_COUNT
    //
    // MessageText:
    //
    // The request is missing one or more required signatures.
    //
    CERTSRV_E_SIGNATURE_COUNT = 0x8009480AL,

    //
    // MessageId: CERTSRV_E_SIGNATURE_REJECTED
    //
    // MessageText:
    //
    // One or more signatures did not include the required application or issuance policies. The request is missing one or more required valid signatures.
    //
    CERTSRV_E_SIGNATURE_REJECTED = 0x8009480BL,

    //
    // MessageId: CERTSRV_E_ISSUANCE_POLICY_REQUIRED
    //
    // MessageText:
    //
    // The request is missing one or more required signature issuance policies.
    //
    CERTSRV_E_ISSUANCE_POLICY_REQUIRED = 0x8009480CL,

    //
    // MessageId: CERTSRV_E_SUBJECT_UPN_REQUIRED
    //
    // MessageText:
    //
    // The UPN is unavailable and cannot be added to the Subject Alternate name.
    //
    CERTSRV_E_SUBJECT_UPN_REQUIRED = 0x8009480DL,

    //
    // MessageId: CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED
    //
    // MessageText:
    //
    // The Active Directory GUID is unavailable and cannot be added to the Subject Alternate name.
    //
    CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED = 0x8009480EL,

    //
    // MessageId: CERTSRV_E_SUBJECT_DNS_REQUIRED
    //
    // MessageText:
    //
    // The DNS name is unavailable and cannot be added to the Subject Alternate name.
    //
    CERTSRV_E_SUBJECT_DNS_REQUIRED = 0x8009480FL,

    //
    // MessageId: CERTSRV_E_ARCHIVED_KEY_UNEXPECTED
    //
    // MessageText:
    //
    // The request includes a private key for archival by the server, but key archival is not enabled for the specified certificate template.
    //
    CERTSRV_E_ARCHIVED_KEY_UNEXPECTED = 0x80094810L,

    //
    // MessageId: CERTSRV_E_KEY_LENGTH
    //
    // MessageText:
    //
    // The public key does not meet the minimum size required by the specified certificate template.
    //
    CERTSRV_E_KEY_LENGTH = 0x80094811L,

    //
    // MessageId: CERTSRV_E_SUBJECT_EMAIL_REQUIRED
    //
    // MessageText:
    //
    // The EMail name is unavailable and cannot be added to the Subject or Subject Alternate name.
    //
    CERTSRV_E_SUBJECT_EMAIL_REQUIRED = 0x80094812L,

    //
    // MessageId: CERTSRV_E_UNKNOWN_CERT_TYPE
    //
    // MessageText:
    //
    // One or more certificate templates to be enabled on this certification authority could not be found.
    //
    CERTSRV_E_UNKNOWN_CERT_TYPE = 0x80094813L,

    //
    // MessageId: CERTSRV_E_CERT_TYPE_OVERLAP
    //
    // MessageText:
    //
    // The certificate template renewal period is longer than the certificate validity period. The template should be reconfigured or the CA certificate renewed.
    //
    CERTSRV_E_CERT_TYPE_OVERLAP = 0x80094814L,

    //
    // MessageId: CERTSRV_E_TOO_MANY_SIGNATURES
    //
    // MessageText:
    //
    // The certificate template requires too many RA signatures. Only one RA signature is allowed.
    //
    CERTSRV_E_TOO_MANY_SIGNATURES = 0x80094815L,

    //
    // MessageId: CERTSRV_E_RENEWAL_BAD_PUBLIC_KEY
    //
    // MessageText:
    //
    // The certificate template requires renewal with the same public key, but the request uses a different public key.
    //
    CERTSRV_E_RENEWAL_BAD_PUBLIC_KEY = 0x80094816L,

    //
    // MessageId: CERTSRV_E_INVALID_EK
    //
    // MessageText:
    //
    // The certification authority cannot interpret or verify the endorsement key information supplied in the request, or the information is inconsistent.
    //
    CERTSRV_E_INVALID_EK = 0x80094817L,

    //
    // MessageId: CERTSRV_E_INVALID_IDBINDING
    //
    // MessageText:
    //
    // The certification authority cannot validate the Attestation Identity Key Id Binding.
    //
    CERTSRV_E_INVALID_IDBINDING = 0x80094818L,

    //
    // MessageId: CERTSRV_E_INVALID_ATTESTATION
    //
    // MessageText:
    //
    // The certification authority cannot validate the private key attestation data.
    //
    CERTSRV_E_INVALID_ATTESTATION = 0x80094819L,

    //
    // MessageId: CERTSRV_E_KEY_ATTESTATION
    //
    // MessageText:
    //
    // The request does not support private key attestation as defined in the certificate template.
    //
    CERTSRV_E_KEY_ATTESTATION = 0x8009481AL,

    //
    // MessageId: CERTSRV_E_CORRUPT_KEY_ATTESTATION
    //
    // MessageText:
    //
    // The request public key is not consistent with the private key attestation data.
    //
    CERTSRV_E_CORRUPT_KEY_ATTESTATION = 0x8009481BL,

    //
    // MessageId: CERTSRV_E_EXPIRED_CHALLENGE
    //
    // MessageText:
    //
    // The private key attestation challenge cannot be validated because the encryption certificate has expired, or the certificate or key is unavailable.
    //
    CERTSRV_E_EXPIRED_CHALLENGE = 0x8009481CL,

    //
    // MessageId: CERTSRV_E_INVALID_RESPONSE
    //
    // MessageText:
    //
    // The attestation response could not be validated. It is either unexpected or incorrect.
    //
    CERTSRV_E_INVALID_RESPONSE = 0x8009481DL,

    //
    // MessageId: CERTSRV_E_INVALID_REQUESTID
    //
    // MessageText:
    //
    // A valid Request ID was not detected in the request attributes, or an invalid one was submitted.
    //
    CERTSRV_E_INVALID_REQUESTID = 0x8009481EL,

    //
    // The range 0x5000-0x51ff is reserved for XENROLL errors.
    //
    //
    // MessageId: XENROLL_E_KEY_NOT_EXPORTABLE
    //
    // MessageText:
    //
    // The key is not exportable.
    //
    XENROLL_E_KEY_NOT_EXPORTABLE = 0x80095000L,

    //
    // MessageId: XENROLL_E_CANNOT_ADD_ROOT_CERT
    //
    // MessageText:
    //
    // You cannot add the root CA certificate into your local store.
    //
    XENROLL_E_CANNOT_ADD_ROOT_CERT = 0x80095001L,

    //
    // MessageId: XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND
    //
    // MessageText:
    //
    // The key archival hash attribute was not found in the response.
    //
    XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND = 0x80095002L,

    //
    // MessageId: XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH
    //
    // MessageText:
    //
    // An unexpected key archival hash attribute was found in the response.
    //
    XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH = 0x80095003L,

    //
    // MessageId: XENROLL_E_RESPONSE_KA_HASH_MISMATCH
    //
    // MessageText:
    //
    // There is a key archival hash mismatch between the request and the response.
    //
    XENROLL_E_RESPONSE_KA_HASH_MISMATCH = 0x80095004L,

    //
    // MessageId: XENROLL_E_KEYSPEC_SMIME_MISMATCH
    //
    // MessageText:
    //
    // Signing certificate cannot include SMIME extension.
    //
    XENROLL_E_KEYSPEC_SMIME_MISMATCH = 0x80095005L,

    //
    // MessageId: TRUST_E_SYSTEM_ERROR
    //
    // MessageText:
    //
    // A system-level error occurred while verifying trust.
    //
    TRUST_E_SYSTEM_ERROR = 0x80096001L,

    //
    // MessageId: TRUST_E_NO_SIGNER_CERT
    //
    // MessageText:
    //
    // The certificate for the signer of the message is invalid or not found.
    //
    TRUST_E_NO_SIGNER_CERT = 0x80096002L,

    //
    // MessageId: TRUST_E_COUNTER_SIGNER
    //
    // MessageText:
    //
    // One of the counter signatures was invalid.
    //
    TRUST_E_COUNTER_SIGNER = 0x80096003L,

    //
    // MessageId: TRUST_E_CERT_SIGNATURE
    //
    // MessageText:
    //
    // The signature of the certificate cannot be verified.
    //
    TRUST_E_CERT_SIGNATURE = 0x80096004L,

    //
    // MessageId: TRUST_E_TIME_STAMP
    //
    // MessageText:
    //
    // The timestamp signature and/or certificate could not be verified or is malformed.
    //
    TRUST_E_TIME_STAMP = 0x80096005L,

    //
    // MessageId: TRUST_E_BAD_DIGEST
    //
    // MessageText:
    //
    // The digital signature of the object did not verify.
    //
    TRUST_E_BAD_DIGEST = 0x80096010L,

    //
    // MessageId: TRUST_E_BASIC_CONSTRAINTS
    //
    // MessageText:
    //
    // A certificate's basic constraint extension has not been observed.
    //
    TRUST_E_BASIC_CONSTRAINTS = 0x80096019L,

    //
    // MessageId: TRUST_E_FINANCIAL_CRITERIA
    //
    // MessageText:
    //
    // The certificate does not meet or contain the Authenticode(tm) financial extensions.
    //
    TRUST_E_FINANCIAL_CRITERIA = 0x8009601EL,

    //
    // Error codes for mssipotf.dll
    // Most of the error codes can only occur when an error occurs
    //    during font file signing
    //
    //
    //
    // MessageId: MSSIPOTF_E_OUTOFMEMRANGE
    //
    // MessageText:
    //
    // Tried to reference a part of the file outside the proper range.
    //
    MSSIPOTF_E_OUTOFMEMRANGE = 0x80097001L,

    //
    // MessageId: MSSIPOTF_E_CANTGETOBJECT
    //
    // MessageText:
    //
    // Could not retrieve an object from the file.
    //
    MSSIPOTF_E_CANTGETOBJECT = 0x80097002L,

    //
    // MessageId: MSSIPOTF_E_NOHEADTABLE
    //
    // MessageText:
    //
    // Could not find the head table in the file.
    //
    MSSIPOTF_E_NOHEADTABLE = 0x80097003L,

    //
    // MessageId: MSSIPOTF_E_BAD_MAGICNUMBER
    //
    // MessageText:
    //
    // The magic number in the head table is incorrect.
    //
    MSSIPOTF_E_BAD_MAGICNUMBER = 0x80097004L,

    //
    // MessageId: MSSIPOTF_E_BAD_OFFSET_TABLE
    //
    // MessageText:
    //
    // The offset table has incorrect values.
    //
    MSSIPOTF_E_BAD_OFFSET_TABLE = 0x80097005L,

    //
    // MessageId: MSSIPOTF_E_TABLE_TAGORDER
    //
    // MessageText:
    //
    // Duplicate table tags or tags out of alphabetical order.
    //
    MSSIPOTF_E_TABLE_TAGORDER = 0x80097006L,

    //
    // MessageId: MSSIPOTF_E_TABLE_LONGWORD
    //
    // MessageText:
    //
    // A table does not start on a long word boundary.
    //
    MSSIPOTF_E_TABLE_LONGWORD = 0x80097007L,

    //
    // MessageId: MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT
    //
    // MessageText:
    //
    // First table does not appear after header information.
    //
    MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT = 0x80097008L,

    //
    // MessageId: MSSIPOTF_E_TABLES_OVERLAP
    //
    // MessageText:
    //
    // Two or more tables overlap.
    //
    MSSIPOTF_E_TABLES_OVERLAP = 0x80097009L,

    //
    // MessageId: MSSIPOTF_E_TABLE_PADBYTES
    //
    // MessageText:
    //
    // Too many pad bytes between tables or pad bytes are not 0.
    //
    MSSIPOTF_E_TABLE_PADBYTES = 0x8009700AL,

    //
    // MessageId: MSSIPOTF_E_FILETOOSMALL
    //
    // MessageText:
    //
    // File is too small to contain the last table.
    //
    MSSIPOTF_E_FILETOOSMALL = 0x8009700BL,

    //
    // MessageId: MSSIPOTF_E_TABLE_CHECKSUM
    //
    // MessageText:
    //
    // A table checksum is incorrect.
    //
    MSSIPOTF_E_TABLE_CHECKSUM = 0x8009700CL,

    //
    // MessageId: MSSIPOTF_E_FILE_CHECKSUM
    //
    // MessageText:
    //
    // The file checksum is incorrect.
    //
    MSSIPOTF_E_FILE_CHECKSUM = 0x8009700DL,

    //
    // MessageId: MSSIPOTF_E_FAILED_POLICY
    //
    // MessageText:
    //
    // The signature does not have the correct attributes for the policy.
    //
    MSSIPOTF_E_FAILED_POLICY = 0x80097010L,

    //
    // MessageId: MSSIPOTF_E_FAILED_HINTS_CHECK
    //
    // MessageText:
    //
    // The file did not pass the hints check.
    //
    MSSIPOTF_E_FAILED_HINTS_CHECK = 0x80097011L,

    //
    // MessageId: MSSIPOTF_E_NOT_OPENTYPE
    //
    // MessageText:
    //
    // The file is not an OpenType file.
    //
    MSSIPOTF_E_NOT_OPENTYPE = 0x80097012L,

    //
    // MessageId: MSSIPOTF_E_FILE
    //
    // MessageText:
    //
    // Failed on a file operation (open, map, read, write).
    //
    MSSIPOTF_E_FILE = 0x80097013L,

    //
    // MessageId: MSSIPOTF_E_CRYPT
    //
    // MessageText:
    //
    // A call to a CryptoAPI function failed.
    //
    MSSIPOTF_E_CRYPT = 0x80097014L,

    //
    // MessageId: MSSIPOTF_E_BADVERSION
    //
    // MessageText:
    //
    // There is a bad version number in the file.
    //
    MSSIPOTF_E_BADVERSION = 0x80097015L,

    //
    // MessageId: MSSIPOTF_E_DSIG_STRUCTURE
    //
    // MessageText:
    //
    // The structure of the DSIG table is incorrect.
    //
    MSSIPOTF_E_DSIG_STRUCTURE = 0x80097016L,

    //
    // MessageId: MSSIPOTF_E_PCONST_CHECK
    //
    // MessageText:
    //
    // A check failed in a partially constant table.
    //
    MSSIPOTF_E_PCONST_CHECK = 0x80097017L,

    //
    // MessageId: MSSIPOTF_E_STRUCTURE
    //
    // MessageText:
    //
    // Some kind of structural error.
    //
    MSSIPOTF_E_STRUCTURE = 0x80097018L,

    //
    // MessageId: ERROR_CRED_REQUIRES_CONFIRMATION
    //
    // MessageText:
    //
    // The requested credential requires confirmation.
    //
    ERROR_CRED_REQUIRES_CONFIRMATION = 0x80097019L,

    NTE_OP_OK = 0x00000000L,

    //
    // Note that additional FACILITY_SSPI errors are in issperr.h
    //
    // ******************
    // FACILITY_CERT
    // ******************
    //
    // MessageId: TRUST_E_PROVIDER_UNKNOWN
    //
    // MessageText:
    //
    // Unknown trust provider.
    //
    TRUST_E_PROVIDER_UNKNOWN = 0x800B0001L,

    //
    // MessageId: TRUST_E_ACTION_UNKNOWN
    //
    // MessageText:
    //
    // The trust verification action specified is not supported by the specified trust provider.
    //
    TRUST_E_ACTION_UNKNOWN = 0x800B0002L,

    //
    // MessageId: TRUST_E_SUBJECT_FORM_UNKNOWN
    //
    // MessageText:
    //
    // The form specified for the subject is not one supported or known by the specified trust provider.
    //
    TRUST_E_SUBJECT_FORM_UNKNOWN = 0x800B0003L,

    //
    // MessageId: TRUST_E_SUBJECT_NOT_TRUSTED
    //
    // MessageText:
    //
    // The subject is not trusted for the specified action.
    //
    TRUST_E_SUBJECT_NOT_TRUSTED = 0x800B0004L,

    //
    // MessageId: DIGSIG_E_ENCODE
    //
    // MessageText:
    //
    // Error due to problem in ASN.1 encoding process.
    //
    DIGSIG_E_ENCODE = 0x800B0005L,

    //
    // MessageId: DIGSIG_E_DECODE
    //
    // MessageText:
    //
    // Error due to problem in ASN.1 decoding process.
    //
    DIGSIG_E_DECODE = 0x800B0006L,

    //
    // MessageId: DIGSIG_E_EXTENSIBILITY
    //
    // MessageText:
    //
    // Reading / writing Extensions where Attributes are appropriate, and vice versa.
    //
    DIGSIG_E_EXTENSIBILITY = 0x800B0007L,

    //
    // MessageId: DIGSIG_E_CRYPTO
    //
    // MessageText:
    //
    // Unspecified cryptographic failure.
    //
    DIGSIG_E_CRYPTO = 0x800B0008L,

    //
    // MessageId: PERSIST_E_SIZEDEFINITE
    //
    // MessageText:
    //
    // The size of the data could not be determined.
    //
    PERSIST_E_SIZEDEFINITE = 0x800B0009L,

    //
    // MessageId: PERSIST_E_SIZEINDEFINITE
    //
    // MessageText:
    //
    // The size of the indefinite-sized data could not be determined.
    //
    PERSIST_E_SIZEINDEFINITE = 0x800B000AL,

    //
    // MessageId: PERSIST_E_NOTSELFSIZING
    //
    // MessageText:
    //
    // This object does not read and write self-sizing data.
    //
    PERSIST_E_NOTSELFSIZING = 0x800B000BL,

    //
    // MessageId: TRUST_E_NOSIGNATURE
    //
    // MessageText:
    //
    // No signature was present in the subject.
    //
    TRUST_E_NOSIGNATURE = 0x800B0100L,

    //
    // MessageId: CERT_E_EXPIRED
    //
    // MessageText:
    //
    // A required certificate is not within its validity period when verifying against the current system clock or the timestamp in the signed file.
    //
    CERT_E_EXPIRED = 0x800B0101L,

    //
    // MessageId: CERT_E_VALIDITYPERIODNESTING
    //
    // MessageText:
    //
    // The validity periods of the certification chain do not nest correctly.
    //
    CERT_E_VALIDITYPERIODNESTING = 0x800B0102L,

    //
    // MessageId: CERT_E_ROLE
    //
    // MessageText:
    //
    // A certificate that can only be used as an end-entity is being used as a CA or vice versa.
    //
    CERT_E_ROLE = 0x800B0103L,

    //
    // MessageId: CERT_E_PATHLENCONST
    //
    // MessageText:
    //
    // A path length constraint in the certification chain has been violated.
    //
    CERT_E_PATHLENCONST = 0x800B0104L,

    //
    // MessageId: CERT_E_CRITICAL
    //
    // MessageText:
    //
    // A certificate contains an unknown extension that is marked 'critical'.
    //
    CERT_E_CRITICAL = 0x800B0105L,

    //
    // MessageId: CERT_E_PURPOSE
    //
    // MessageText:
    //
    // A certificate being used for a purpose other than the ones specified by its CA.
    //
    CERT_E_PURPOSE = 0x800B0106L,

    //
    // MessageId: CERT_E_ISSUERCHAINING
    //
    // MessageText:
    //
    // A parent of a given certificate in fact did not issue that child certificate.
    //
    CERT_E_ISSUERCHAINING = 0x800B0107L,

    //
    // MessageId: CERT_E_MALFORMED
    //
    // MessageText:
    //
    // A certificate is missing or has an empty value for an important field, such as a subject or issuer name.
    //
    CERT_E_MALFORMED = 0x800B0108L,

    //
    // MessageId: CERT_E_UNTRUSTEDROOT
    //
    // MessageText:
    //
    // A certificate chain processed, but terminated in a root certificate which is not trusted by the trust provider.
    //
    CERT_E_UNTRUSTEDROOT = 0x800B0109L,

    //
    // MessageId: CERT_E_CHAINING
    //
    // MessageText:
    //
    // A certificate chain could not be built to a trusted root authority.
    //
    CERT_E_CHAINING = 0x800B010AL,

    //
    // MessageId: TRUST_E_FAIL
    //
    // MessageText:
    //
    // Generic trust failure.
    //
    TRUST_E_FAIL = 0x800B010BL,

    //
    // MessageId: CERT_E_REVOKED
    //
    // MessageText:
    //
    // A certificate was explicitly revoked by its issuer.
    //
    CERT_E_REVOKED = 0x800B010CL,

    //
    // MessageId: CERT_E_UNTRUSTEDTESTROOT
    //
    // MessageText:
    //
    // The certification path terminates with the test root which is not trusted with the current policy settings.
    //
    CERT_E_UNTRUSTEDTESTROOT = 0x800B010DL,

    //
    // MessageId: CERT_E_REVOCATION_FAILURE
    //
    // MessageText:
    //
    // The revocation process could not continue - the certificate(s) could not be checked.
    //
    CERT_E_REVOCATION_FAILURE = 0x800B010EL,

    //
    // MessageId: CERT_E_CN_NO_MATCH
    //
    // MessageText:
    //
    // The certificate's CN name does not match the passed value.
    //
    CERT_E_CN_NO_MATCH = 0x800B010FL,

    //
    // MessageId: CERT_E_WRONG_USAGE
    //
    // MessageText:
    //
    // The certificate is not valid for the requested usage.
    //
    CERT_E_WRONG_USAGE = 0x800B0110L,

    //
    // MessageId: TRUST_E_EXPLICIT_DISTRUST
    //
    // MessageText:
    //
    // The certificate was explicitly marked as untrusted by the user.
    //
    TRUST_E_EXPLICIT_DISTRUST = 0x800B0111L,

    //
    // MessageId: CERT_E_UNTRUSTEDCA
    //
    // MessageText:
    //
    // A certification chain processed correctly, but one of the CA certificates is not trusted by the policy provider.
    //
    CERT_E_UNTRUSTEDCA = 0x800B0112L,

    //
    // MessageId: CERT_E_INVALID_POLICY
    //
    // MessageText:
    //
    // The certificate has invalid policy.
    //
    CERT_E_INVALID_POLICY = 0x800B0113L,

    //
    // MessageId: CERT_E_INVALID_NAME
    //
    // MessageText:
    //
    // The certificate has an invalid name. The name is not included in the permitted list or is explicitly excluded.
    //
    CERT_E_INVALID_NAME = 0x800B0114L,

    //
    // MessageId: SPAPI_E_EXPECTED_SECTION_NAME
    //
    // MessageText:
    //
    // A non-empty line was encountered in the INF before the start of a section.
    //
    SPAPI_E_EXPECTED_SECTION_NAME = 0x800F0000L,

    //
    // MessageId: SPAPI_E_BAD_SECTION_NAME_LINE
    //
    // MessageText:
    //
    // A section name marker in the INF is not complete, or does not exist on a line by itself.
    //
    SPAPI_E_BAD_SECTION_NAME_LINE = 0x800F0001L,

    //
    // MessageId: SPAPI_E_SECTION_NAME_TOO_LONG
    //
    // MessageText:
    //
    // An INF section was encountered whose name exceeds the maximum section name length.
    //
    SPAPI_E_SECTION_NAME_TOO_LONG = 0x800F0002L,

    //
    // MessageId: SPAPI_E_GENERAL_SYNTAX
    //
    // MessageText:
    //
    // The syntax of the INF is invalid.
    //
    SPAPI_E_GENERAL_SYNTAX = 0x800F0003L,

    //
    // MessageId: SPAPI_E_WRONG_INF_STYLE
    //
    // MessageText:
    //
    // The style of the INF is different than what was requested.
    //
    SPAPI_E_WRONG_INF_STYLE = 0x800F0100L,

    //
    // MessageId: SPAPI_E_SECTION_NOT_FOUND
    //
    // MessageText:
    //
    // The required section was not found in the INF.
    //
    SPAPI_E_SECTION_NOT_FOUND = 0x800F0101L,

    //
    // MessageId: SPAPI_E_LINE_NOT_FOUND
    //
    // MessageText:
    //
    // The required line was not found in the INF.
    //
    SPAPI_E_LINE_NOT_FOUND = 0x800F0102L,

    //
    // MessageId: SPAPI_E_NO_BACKUP
    //
    // MessageText:
    //
    // The files affected by the installation of this file queue have not been backed up for uninstall.
    //
    SPAPI_E_NO_BACKUP = 0x800F0103L,

    //
    // MessageId: SPAPI_E_NO_ASSOCIATED_CLASS
    //
    // MessageText:
    //
    // The INF or the device information set or element does not have an associated install class.
    //
    SPAPI_E_NO_ASSOCIATED_CLASS = 0x800F0200L,

    //
    // MessageId: SPAPI_E_CLASS_MISMATCH
    //
    // MessageText:
    //
    // The INF or the device information set or element does not match the specified install class.
    //
    SPAPI_E_CLASS_MISMATCH = 0x800F0201L,

    //
    // MessageId: SPAPI_E_DUPLICATE_FOUND
    //
    // MessageText:
    //
    // An existing device was found that is a duplicate of the device being manually installed.
    //
    SPAPI_E_DUPLICATE_FOUND = 0x800F0202L,

    //
    // MessageId: SPAPI_E_NO_DRIVER_SELECTED
    //
    // MessageText:
    //
    // There is no driver selected for the device information set or element.
    //
    SPAPI_E_NO_DRIVER_SELECTED = 0x800F0203L,

    //
    // MessageId: SPAPI_E_KEY_DOES_NOT_EXIST
    //
    // MessageText:
    //
    // The requested device registry key does not exist.
    //
    SPAPI_E_KEY_DOES_NOT_EXIST = 0x800F0204L,

    //
    // MessageId: SPAPI_E_INVALID_DEVINST_NAME
    //
    // MessageText:
    //
    // The device instance name is invalid.
    //
    SPAPI_E_INVALID_DEVINST_NAME = 0x800F0205L,

    //
    // MessageId: SPAPI_E_INVALID_CLASS
    //
    // MessageText:
    //
    // The install class is not present or is invalid.
    //
    SPAPI_E_INVALID_CLASS = 0x800F0206L,

    //
    // MessageId: SPAPI_E_DEVINST_ALREADY_EXISTS
    //
    // MessageText:
    //
    // The device instance cannot be created because it already exists.
    //
    SPAPI_E_DEVINST_ALREADY_EXISTS = 0x800F0207L,

    //
    // MessageId: SPAPI_E_DEVINFO_NOT_REGISTERED
    //
    // MessageText:
    //
    // The operation cannot be performed on a device information element that has not been registered.
    //
    SPAPI_E_DEVINFO_NOT_REGISTERED = 0x800F0208L,

    //
    // MessageId: SPAPI_E_INVALID_REG_PROPERTY
    //
    // MessageText:
    //
    // The device property code is invalid.
    //
    SPAPI_E_INVALID_REG_PROPERTY = 0x800F0209L,

    //
    // MessageId: SPAPI_E_NO_INF
    //
    // MessageText:
    //
    // The INF from which a driver list is to be built does not exist.
    //
    SPAPI_E_NO_INF = 0x800F020AL,

    //
    // MessageId: SPAPI_E_NO_SUCH_DEVINST
    //
    // MessageText:
    //
    // The device instance does not exist in the hardware tree.
    //
    SPAPI_E_NO_SUCH_DEVINST = 0x800F020BL,

    //
    // MessageId: SPAPI_E_CANT_LOAD_CLASS_ICON
    //
    // MessageText:
    //
    // The icon representing this install class cannot be loaded.
    //
    SPAPI_E_CANT_LOAD_CLASS_ICON = 0x800F020CL,

    //
    // MessageId: SPAPI_E_INVALID_CLASS_INSTALLER
    //
    // MessageText:
    //
    // The class installer registry entry is invalid.
    //
    SPAPI_E_INVALID_CLASS_INSTALLER = 0x800F020DL,

    //
    // MessageId: SPAPI_E_DI_DO_DEFAULT
    //
    // MessageText:
    //
    // The class installer has indicated that the default action should be performed for this installation request.
    //
    SPAPI_E_DI_DO_DEFAULT = 0x800F020EL,

    //
    // MessageId: SPAPI_E_DI_NOFILECOPY
    //
    // MessageText:
    //
    // The operation does not require any files to be copied.
    //
    SPAPI_E_DI_NOFILECOPY = 0x800F020FL,

    //
    // MessageId: SPAPI_E_INVALID_HWPROFILE
    //
    // MessageText:
    //
    // The specified hardware profile does not exist.
    //
    SPAPI_E_INVALID_HWPROFILE = 0x800F0210L,

    //
    // MessageId: SPAPI_E_NO_DEVICE_SELECTED
    //
    // MessageText:
    //
    // There is no device information element currently selected for this device information set.
    //
    SPAPI_E_NO_DEVICE_SELECTED = 0x800F0211L,

    //
    // MessageId: SPAPI_E_DEVINFO_LIST_LOCKED
    //
    // MessageText:
    //
    // The operation cannot be performed because the device information set is locked.
    //
    SPAPI_E_DEVINFO_LIST_LOCKED = 0x800F0212L,

    //
    // MessageId: SPAPI_E_DEVINFO_DATA_LOCKED
    //
    // MessageText:
    //
    // The operation cannot be performed because the device information element is locked.
    //
    SPAPI_E_DEVINFO_DATA_LOCKED = 0x800F0213L,

    //
    // MessageId: SPAPI_E_DI_BAD_PATH
    //
    // MessageText:
    //
    // The specified path does not contain any applicable device INFs.
    //
    SPAPI_E_DI_BAD_PATH = 0x800F0214L,

    //
    // MessageId: SPAPI_E_NO_CLASSINSTALL_PARAMS
    //
    // MessageText:
    //
    // No class installer parameters have been set for the device information set or element.
    //
    SPAPI_E_NO_CLASSINSTALL_PARAMS = 0x800F0215L,

    //
    // MessageId: SPAPI_E_FILEQUEUE_LOCKED
    //
    // MessageText:
    //
    // The operation cannot be performed because the file queue is locked.
    //
    SPAPI_E_FILEQUEUE_LOCKED = 0x800F0216L,

    //
    // MessageId: SPAPI_E_BAD_SERVICE_INSTALLSECT
    //
    // MessageText:
    //
    // A service installation section in this INF is invalid.
    //
    SPAPI_E_BAD_SERVICE_INSTALLSECT = 0x800F0217L,

    //
    // MessageId: SPAPI_E_NO_CLASS_DRIVER_LIST
    //
    // MessageText:
    //
    // There is no class driver list for the device information element.
    //
    SPAPI_E_NO_CLASS_DRIVER_LIST = 0x800F0218L,

    //
    // MessageId: SPAPI_E_NO_ASSOCIATED_SERVICE
    //
    // MessageText:
    //
    // The installation failed because a function driver was not specified for this device instance.
    //
    SPAPI_E_NO_ASSOCIATED_SERVICE = 0x800F0219L,

    //
    // MessageId: SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE
    //
    // MessageText:
    //
    // There is presently no default device interface designated for this interface class.
    //
    SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE = 0x800F021AL,

    //
    // MessageId: SPAPI_E_DEVICE_INTERFACE_ACTIVE
    //
    // MessageText:
    //
    // The operation cannot be performed because the device interface is currently active.
    //
    SPAPI_E_DEVICE_INTERFACE_ACTIVE = 0x800F021BL,

    //
    // MessageId: SPAPI_E_DEVICE_INTERFACE_REMOVED
    //
    // MessageText:
    //
    // The operation cannot be performed because the device interface has been removed from the system.
    //
    SPAPI_E_DEVICE_INTERFACE_REMOVED = 0x800F021CL,

    //
    // MessageId: SPAPI_E_BAD_INTERFACE_INSTALLSECT
    //
    // MessageText:
    //
    // An interface installation section in this INF is invalid.
    //
    SPAPI_E_BAD_INTERFACE_INSTALLSECT = 0x800F021DL,

    //
    // MessageId: SPAPI_E_NO_SUCH_INTERFACE_CLASS
    //
    // MessageText:
    //
    // This interface class does not exist in the system.
    //
    SPAPI_E_NO_SUCH_INTERFACE_CLASS = 0x800F021EL,

    //
    // MessageId: SPAPI_E_INVALID_REFERENCE_STRING
    //
    // MessageText:
    //
    // The reference string supplied for this interface device is invalid.
    //
    SPAPI_E_INVALID_REFERENCE_STRING = 0x800F021FL,

    //
    // MessageId: SPAPI_E_INVALID_MACHINENAME
    //
    // MessageText:
    //
    // The specified machine name does not conform to UNC naming conventions.
    //
    SPAPI_E_INVALID_MACHINENAME = 0x800F0220L,

    //
    // MessageId: SPAPI_E_REMOTE_COMM_FAILURE
    //
    // MessageText:
    //
    // A general remote communication error occurred.
    //
    SPAPI_E_REMOTE_COMM_FAILURE = 0x800F0221L,

    //
    // MessageId: SPAPI_E_MACHINE_UNAVAILABLE
    //
    // MessageText:
    //
    // The machine selected for remote communication is not available at this time.
    //
    SPAPI_E_MACHINE_UNAVAILABLE = 0x800F0222L,

    //
    // MessageId: SPAPI_E_NO_CONFIGMGR_SERVICES
    //
    // MessageText:
    //
    // The Plug and Play service is not available on the remote machine.
    //
    SPAPI_E_NO_CONFIGMGR_SERVICES = 0x800F0223L,

    //
    // MessageId: SPAPI_E_INVALID_PROPPAGE_PROVIDER
    //
    // MessageText:
    //
    // The property page provider registry entry is invalid.
    //
    SPAPI_E_INVALID_PROPPAGE_PROVIDER = 0x800F0224L,

    //
    // MessageId: SPAPI_E_NO_SUCH_DEVICE_INTERFACE
    //
    // MessageText:
    //
    // The requested device interface is not present in the system.
    //
    SPAPI_E_NO_SUCH_DEVICE_INTERFACE = 0x800F0225L,

    //
    // MessageId: SPAPI_E_DI_POSTPROCESSING_REQUIRED
    //
    // MessageText:
    //
    // The device's co-installer has additional work to perform after installation is complete.
    //
    SPAPI_E_DI_POSTPROCESSING_REQUIRED = 0x800F0226L,

    //
    // MessageId: SPAPI_E_INVALID_COINSTALLER
    //
    // MessageText:
    //
    // The device's co-installer is invalid.
    //
    SPAPI_E_INVALID_COINSTALLER = 0x800F0227L,

    //
    // MessageId: SPAPI_E_NO_COMPAT_DRIVERS
    //
    // MessageText:
    //
    // There are no compatible drivers for this device.
    //
    SPAPI_E_NO_COMPAT_DRIVERS = 0x800F0228L,

    //
    // MessageId: SPAPI_E_NO_DEVICE_ICON
    //
    // MessageText:
    //
    // There is no icon that represents this device or device type.
    //
    SPAPI_E_NO_DEVICE_ICON = 0x800F0229L,

    //
    // MessageId: SPAPI_E_INVALID_INF_LOGCONFIG
    //
    // MessageText:
    //
    // A logical configuration specified in this INF is invalid.
    //
    SPAPI_E_INVALID_INF_LOGCONFIG = 0x800F022AL,

    //
    // MessageId: SPAPI_E_DI_DONT_INSTALL
    //
    // MessageText:
    //
    // The class installer has denied the request to install or upgrade this device.
    //
    SPAPI_E_DI_DONT_INSTALL = 0x800F022BL,

    //
    // MessageId: SPAPI_E_INVALID_FILTER_DRIVER
    //
    // MessageText:
    //
    // One of the filter drivers installed for this device is invalid.
    //
    SPAPI_E_INVALID_FILTER_DRIVER = 0x800F022CL,

    //
    // MessageId: SPAPI_E_NON_WINDOWS_NT_DRIVER
    //
    // MessageText:
    //
    // The driver selected for this device does not support this version of Windows.
    //
    SPAPI_E_NON_WINDOWS_NT_DRIVER = 0x800F022DL,

    //
    // MessageId: SPAPI_E_NON_WINDOWS_DRIVER
    //
    // MessageText:
    //
    // The driver selected for this device does not support Windows.
    //
    SPAPI_E_NON_WINDOWS_DRIVER = 0x800F022EL,

    //
    // MessageId: SPAPI_E_NO_CATALOG_FOR_OEM_INF
    //
    // MessageText:
    //
    // The third-party INF does not contain digital signature information.
    //
    SPAPI_E_NO_CATALOG_FOR_OEM_INF = 0x800F022FL,

    //
    // MessageId: SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE
    //
    // MessageText:
    //
    // An invalid attempt was made to use a device installation file queue for verification of digital signatures relative to other platforms.
    //
    SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE = 0x800F0230L,

    //
    // MessageId: SPAPI_E_NOT_DISABLEABLE
    //
    // MessageText:
    //
    // The device cannot be disabled.
    //
    SPAPI_E_NOT_DISABLEABLE = 0x800F0231L,

    //
    // MessageId: SPAPI_E_CANT_REMOVE_DEVINST
    //
    // MessageText:
    //
    // The device could not be dynamically removed.
    //
    SPAPI_E_CANT_REMOVE_DEVINST = 0x800F0232L,

    //
    // MessageId: SPAPI_E_INVALID_TARGET
    //
    // MessageText:
    //
    // Cannot copy to specified target.
    //
    SPAPI_E_INVALID_TARGET = 0x800F0233L,

    //
    // MessageId: SPAPI_E_DRIVER_NONNATIVE
    //
    // MessageText:
    //
    // Driver is not intended for this platform.
    //
    SPAPI_E_DRIVER_NONNATIVE = 0x800F0234L,

    //
    // MessageId: SPAPI_E_IN_WOW64
    //
    // MessageText:
    //
    // Operation not allowed in WOW64.
    //
    SPAPI_E_IN_WOW64 = 0x800F0235L,

    //
    // MessageId: SPAPI_E_SET_SYSTEM_RESTORE_POINT
    //
    // MessageText:
    //
    // The operation involving unsigned file copying was rolled back, so that a system restore point could be set.
    //
    SPAPI_E_SET_SYSTEM_RESTORE_POINT = 0x800F0236L,

    //
    // MessageId: SPAPI_E_INCORRECTLY_COPIED_INF
    //
    // MessageText:
    //
    // An INF was copied into the Windows INF directory in an improper manner.
    //
    SPAPI_E_INCORRECTLY_COPIED_INF = 0x800F0237L,

    //
    // MessageId: SPAPI_E_SCE_DISABLED
    //
    // MessageText:
    //
    // The Security Configuration Editor (SCE) APIs have been disabled on this Embedded product.
    //
    SPAPI_E_SCE_DISABLED = 0x800F0238L,

    //
    // MessageId: SPAPI_E_UNKNOWN_EXCEPTION
    //
    // MessageText:
    //
    // An unknown exception was encountered.
    //
    SPAPI_E_UNKNOWN_EXCEPTION = 0x800F0239L,

    //
    // MessageId: SPAPI_E_PNP_REGISTRY_ERROR
    //
    // MessageText:
    //
    // A problem was encountered when accessing the Plug and Play registry database.
    //
    SPAPI_E_PNP_REGISTRY_ERROR = 0x800F023AL,

    //
    // MessageId: SPAPI_E_REMOTE_REQUEST_UNSUPPORTED
    //
    // MessageText:
    //
    // The requested operation is not supported for a remote machine.
    //
    SPAPI_E_REMOTE_REQUEST_UNSUPPORTED = 0x800F023BL,

    //
    // MessageId: SPAPI_E_NOT_AN_INSTALLED_OEM_INF
    //
    // MessageText:
    //
    // The specified file is not an installed OEM INF.
    //
    SPAPI_E_NOT_AN_INSTALLED_OEM_INF = 0x800F023CL,

    //
    // MessageId: SPAPI_E_INF_IN_USE_BY_DEVICES
    //
    // MessageText:
    //
    // One or more devices are presently installed using the specified INF.
    //
    SPAPI_E_INF_IN_USE_BY_DEVICES = 0x800F023DL,

    //
    // MessageId: SPAPI_E_DI_FUNCTION_OBSOLETE
    //
    // MessageText:
    //
    // The requested device install operation is obsolete.
    //
    SPAPI_E_DI_FUNCTION_OBSOLETE = 0x800F023EL,

    //
    // MessageId: SPAPI_E_NO_AUTHENTICODE_CATALOG
    //
    // MessageText:
    //
    // A file could not be verified because it does not have an associated catalog signed via Authenticode(tm).
    //
    SPAPI_E_NO_AUTHENTICODE_CATALOG = 0x800F023FL,

    //
    // MessageId: SPAPI_E_AUTHENTICODE_DISALLOWED
    //
    // MessageText:
    //
    // Authenticode(tm) signature verification is not supported for the specified INF.
    //
    SPAPI_E_AUTHENTICODE_DISALLOWED = 0x800F0240L,

    //
    // MessageId: SPAPI_E_AUTHENTICODE_TRUSTED_PUBLISHER
    //
    // MessageText:
    //
    // The INF was signed with an Authenticode(tm) catalog from a trusted publisher.
    //
    SPAPI_E_AUTHENTICODE_TRUSTED_PUBLISHER = 0x800F0241L,

    //
    // MessageId: SPAPI_E_AUTHENTICODE_TRUST_NOT_ESTABLISHED
    //
    // MessageText:
    //
    // The publisher of an Authenticode(tm) signed catalog has not yet been established as trusted.
    //
    SPAPI_E_AUTHENTICODE_TRUST_NOT_ESTABLISHED = 0x800F0242L,

    //
    // MessageId: SPAPI_E_AUTHENTICODE_PUBLISHER_NOT_TRUSTED
    //
    // MessageText:
    //
    // The publisher of an Authenticode(tm) signed catalog was not established as trusted.
    //
    SPAPI_E_AUTHENTICODE_PUBLISHER_NOT_TRUSTED = 0x800F0243L,

    //
    // MessageId: SPAPI_E_SIGNATURE_OSATTRIBUTE_MISMATCH
    //
    // MessageText:
    //
    // The software was tested for compliance with Windows Logo requirements on a different version of Windows, and may not be compatible with this version.
    //
    SPAPI_E_SIGNATURE_OSATTRIBUTE_MISMATCH = 0x800F0244L,

    //
    // MessageId: SPAPI_E_ONLY_VALIDATE_VIA_AUTHENTICODE
    //
    // MessageText:
    //
    // The file may only be validated by a catalog signed via Authenticode(tm).
    //
    SPAPI_E_ONLY_VALIDATE_VIA_AUTHENTICODE = 0x800F0245L,

    //
    // MessageId: SPAPI_E_DEVICE_INSTALLER_NOT_READY
    //
    // MessageText:
    //
    // One of the installers for this device cannot perform the installation at this time.
    //
    SPAPI_E_DEVICE_INSTALLER_NOT_READY = 0x800F0246L,

    //
    // MessageId: SPAPI_E_DRIVER_STORE_ADD_FAILED
    //
    // MessageText:
    //
    // A problem was encountered while attempting to add the driver to the store.
    //
    SPAPI_E_DRIVER_STORE_ADD_FAILED = 0x800F0247L,

    //
    // MessageId: SPAPI_E_DEVICE_INSTALL_BLOCKED
    //
    // MessageText:
    //
    // The installation of this device is forbidden by system policy. Contact your system administrator.
    //
    SPAPI_E_DEVICE_INSTALL_BLOCKED = 0x800F0248L,

    //
    // MessageId: SPAPI_E_DRIVER_INSTALL_BLOCKED
    //
    // MessageText:
    //
    // The installation of this driver is forbidden by system policy. Contact your system administrator.
    //
    SPAPI_E_DRIVER_INSTALL_BLOCKED = 0x800F0249L,

    //
    // MessageId: SPAPI_E_WRONG_INF_TYPE
    //
    // MessageText:
    //
    // The specified INF is the wrong type for this operation.
    //
    SPAPI_E_WRONG_INF_TYPE = 0x800F024AL,

    //
    // MessageId: SPAPI_E_FILE_HASH_NOT_IN_CATALOG
    //
    // MessageText:
    //
    // The hash for the file is not present in the specified catalog file. The file is likely corrupt or the victim of tampering.
    //
    SPAPI_E_FILE_HASH_NOT_IN_CATALOG = 0x800F024BL,

    //
    // MessageId: SPAPI_E_DRIVER_STORE_DELETE_FAILED
    //
    // MessageText:
    //
    // A problem was encountered while attempting to delete the driver from the store.
    //
    SPAPI_E_DRIVER_STORE_DELETE_FAILED = 0x800F024CL,

    //
    // MessageId: SPAPI_E_UNRECOVERABLE_STACK_OVERFLOW
    //
    // MessageText:
    //
    // An unrecoverable stack overflow was encountered.
    //
    SPAPI_E_UNRECOVERABLE_STACK_OVERFLOW = 0x800F0300L,

    //
    // MessageId: SPAPI_E_ERROR_NOT_INSTALLED
    //
    // MessageText:
    //
    // No installed components were detected.
    //
    SPAPI_E_ERROR_NOT_INSTALLED = 0x800F1000L,

    // *****************
    // FACILITY_SCARD
    // *****************
    //
    // =============================
    // Facility SCARD Error Messages
    // =============================
    //
    SCARD_S_SUCCESS = S_OK,

    //
    // MessageId: SCARD_F_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal consistency check failed.
    //
    SCARD_F_INTERNAL_ERROR = 0x80100001L,

    //
    // MessageId: SCARD_E_CANCELLED
    //
    // MessageText:
    //
    // The action was cancelled by an SCardCancel request.
    //
    SCARD_E_CANCELLED = 0x80100002L,

    //
    // MessageId: SCARD_E_INVALID_HANDLE
    //
    // MessageText:
    //
    // The supplied handle was invalid.
    //
    SCARD_E_INVALID_HANDLE = 0x80100003L,

    //
    // MessageId: SCARD_E_INVALID_PARAMETER
    //
    // MessageText:
    //
    // One or more of the supplied parameters could not be properly interpreted.
    //
    SCARD_E_INVALID_PARAMETER = 0x80100004L,

    //
    // MessageId: SCARD_E_INVALID_TARGET
    //
    // MessageText:
    //
    // Registry startup information is missing or invalid.
    //
    SCARD_E_INVALID_TARGET = 0x80100005L,

    //
    // MessageId: SCARD_E_NO_MEMORY
    //
    // MessageText:
    //
    // Not enough memory available to complete this command.
    //
    SCARD_E_NO_MEMORY = 0x80100006L,

    //
    // MessageId: SCARD_F_WAITED_TOO_LONG
    //
    // MessageText:
    //
    // An internal consistency timer has expired.
    //
    SCARD_F_WAITED_TOO_LONG = 0x80100007L,

    //
    // MessageId: SCARD_E_INSUFFICIENT_BUFFER
    //
    // MessageText:
    //
    // The data buffer to receive returned data is too small for the returned data.
    //
    SCARD_E_INSUFFICIENT_BUFFER = 0x80100008L,

    //
    // MessageId: SCARD_E_UNKNOWN_READER
    //
    // MessageText:
    //
    // The specified reader name is not recognized.
    //
    SCARD_E_UNKNOWN_READER = 0x80100009L,

    //
    // MessageId: SCARD_E_TIMEOUT
    //
    // MessageText:
    //
    // The user-specified timeout value has expired.
    //
    SCARD_E_TIMEOUT = 0x8010000AL,

    //
    // MessageId: SCARD_E_SHARING_VIOLATION
    //
    // MessageText:
    //
    // The smart card cannot be accessed because of other connections outstanding.
    //
    SCARD_E_SHARING_VIOLATION = 0x8010000BL,

    //
    // MessageId: SCARD_E_NO_SMARTCARD
    //
    // MessageText:
    //
    // The operation requires a smart card, but no smart card is currently in the device.
    //
    SCARD_E_NO_SMARTCARD = 0x8010000CL,

    //
    // MessageId: SCARD_E_UNKNOWN_CARD
    //
    // MessageText:
    //
    // The specified smart card name is not recognized.
    //
    SCARD_E_UNKNOWN_CARD = 0x8010000DL,

    //
    // MessageId: SCARD_E_CANT_DISPOSE
    //
    // MessageText:
    //
    // The system could not dispose of the media in the requested manner.
    //
    SCARD_E_CANT_DISPOSE = 0x8010000EL,

    //
    // MessageId: SCARD_E_PROTO_MISMATCH
    //
    // MessageText:
    //
    // The requested protocols are incompatible with the protocol currently in use with the smart card.
    //
    SCARD_E_PROTO_MISMATCH = 0x8010000FL,

    //
    // MessageId: SCARD_E_NOT_READY
    //
    // MessageText:
    //
    // The reader or smart card is not ready to accept commands.
    //
    SCARD_E_NOT_READY = 0x80100010L,

    //
    // MessageId: SCARD_E_INVALID_VALUE
    //
    // MessageText:
    //
    // One or more of the supplied parameters values could not be properly interpreted.
    //
    SCARD_E_INVALID_VALUE = 0x80100011L,

    //
    // MessageId: SCARD_E_SYSTEM_CANCELLED
    //
    // MessageText:
    //
    // The action was cancelled by the system, presumably to log off or shut down.
    //
    SCARD_E_SYSTEM_CANCELLED = 0x80100012L,

    //
    // MessageId: SCARD_F_COMM_ERROR
    //
    // MessageText:
    //
    // An internal communications error has been detected.
    //
    SCARD_F_COMM_ERROR = 0x80100013L,

    //
    // MessageId: SCARD_F_UNKNOWN_ERROR
    //
    // MessageText:
    //
    // An internal error has been detected, but the source is unknown.
    //
    SCARD_F_UNKNOWN_ERROR = 0x80100014L,

    //
    // MessageId: SCARD_E_INVALID_ATR
    //
    // MessageText:
    //
    // An ATR obtained from the registry is not a valid ATR string.
    //
    SCARD_E_INVALID_ATR = 0x80100015L,

    //
    // MessageId: SCARD_E_NOT_TRANSACTED
    //
    // MessageText:
    //
    // An attempt was made to end a non-existent transaction.
    //
    SCARD_E_NOT_TRANSACTED = 0x80100016L,

    //
    // MessageId: SCARD_E_READER_UNAVAILABLE
    //
    // MessageText:
    //
    // The specified reader is not currently available for use.
    //
    SCARD_E_READER_UNAVAILABLE = 0x80100017L,

    //
    // MessageId: SCARD_P_SHUTDOWN
    //
    // MessageText:
    //
    // The operation has been aborted to allow the server application to exit.
    //
    SCARD_P_SHUTDOWN = 0x80100018L,

    //
    // MessageId: SCARD_E_PCI_TOO_SMALL
    //
    // MessageText:
    //
    // The PCI Receive buffer was too small.
    //
    SCARD_E_PCI_TOO_SMALL = 0x80100019L,

    //
    // MessageId: SCARD_E_READER_UNSUPPORTED
    //
    // MessageText:
    //
    // The reader driver does not meet minimal requirements for support.
    //
    SCARD_E_READER_UNSUPPORTED = 0x8010001AL,

    //
    // MessageId: SCARD_E_DUPLICATE_READER
    //
    // MessageText:
    //
    // The reader driver did not produce a unique reader name.
    //
    SCARD_E_DUPLICATE_READER = 0x8010001BL,

    //
    // MessageId: SCARD_E_CARD_UNSUPPORTED
    //
    // MessageText:
    //
    // The smart card does not meet minimal requirements for support.
    //
    SCARD_E_CARD_UNSUPPORTED = 0x8010001CL,

    //
    // MessageId: SCARD_E_NO_SERVICE
    //
    // MessageText:
    //
    // The Smart Card Resource Manager is not running.
    //
    SCARD_E_NO_SERVICE = 0x8010001DL,

    //
    // MessageId: SCARD_E_SERVICE_STOPPED
    //
    // MessageText:
    //
    // The Smart Card Resource Manager has shut down.
    //
    SCARD_E_SERVICE_STOPPED = 0x8010001EL,

    //
    // MessageId: SCARD_E_UNEXPECTED
    //
    // MessageText:
    //
    // An unexpected card error has occurred.
    //
    SCARD_E_UNEXPECTED = 0x8010001FL,

    //
    // MessageId: SCARD_E_ICC_INSTALLATION
    //
    // MessageText:
    //
    // No Primary Provider can be found for the smart card.
    //
    SCARD_E_ICC_INSTALLATION = 0x80100020L,

    //
    // MessageId: SCARD_E_ICC_CREATEORDER
    //
    // MessageText:
    //
    // The requested order of object creation is not supported.
    //
    SCARD_E_ICC_CREATEORDER = 0x80100021L,

    //
    // MessageId: SCARD_E_UNSUPPORTED_FEATURE
    //
    // MessageText:
    //
    // This smart card does not support the requested feature.
    //
    SCARD_E_UNSUPPORTED_FEATURE = 0x80100022L,

    //
    // MessageId: SCARD_E_DIR_NOT_FOUND
    //
    // MessageText:
    //
    // The identified directory does not exist in the smart card.
    //
    SCARD_E_DIR_NOT_FOUND = 0x80100023L,

    //
    // MessageId: SCARD_E_FILE_NOT_FOUND
    //
    // MessageText:
    //
    // The identified file does not exist in the smart card.
    //
    SCARD_E_FILE_NOT_FOUND = 0x80100024L,

    //
    // MessageId: SCARD_E_NO_DIR
    //
    // MessageText:
    //
    // The supplied path does not represent a smart card directory.
    //
    SCARD_E_NO_DIR = 0x80100025L,

    //
    // MessageId: SCARD_E_NO_FILE
    //
    // MessageText:
    //
    // The supplied path does not represent a smart card file.
    //
    SCARD_E_NO_FILE = 0x80100026L,

    //
    // MessageId: SCARD_E_NO_ACCESS
    //
    // MessageText:
    //
    // Access is denied to this file.
    //
    SCARD_E_NO_ACCESS = 0x80100027L,

    //
    // MessageId: SCARD_E_WRITE_TOO_MANY
    //
    // MessageText:
    //
    // The smart card does not have enough memory to store the information.
    //
    SCARD_E_WRITE_TOO_MANY = 0x80100028L,

    //
    // MessageId: SCARD_E_BAD_SEEK
    //
    // MessageText:
    //
    // There was an error trying to set the smart card file object pointer.
    //
    SCARD_E_BAD_SEEK = 0x80100029L,

    //
    // MessageId: SCARD_E_INVALID_CHV
    //
    // MessageText:
    //
    // The supplied PIN is incorrect.
    //
    SCARD_E_INVALID_CHV = 0x8010002AL,

    //
    // MessageId: SCARD_E_UNKNOWN_RES_MNG
    //
    // MessageText:
    //
    // An unrecognized error code was returned from a layered component.
    //
    SCARD_E_UNKNOWN_RES_MNG = 0x8010002BL,

    //
    // MessageId: SCARD_E_NO_SUCH_CERTIFICATE
    //
    // MessageText:
    //
    // The requested certificate does not exist.
    //
    SCARD_E_NO_SUCH_CERTIFICATE = 0x8010002CL,

    //
    // MessageId: SCARD_E_CERTIFICATE_UNAVAILABLE
    //
    // MessageText:
    //
    // The requested certificate could not be obtained.
    //
    SCARD_E_CERTIFICATE_UNAVAILABLE = 0x8010002DL,

    //
    // MessageId: SCARD_E_NO_READERS_AVAILABLE
    //
    // MessageText:
    //
    // Cannot find a smart card reader.
    //
    SCARD_E_NO_READERS_AVAILABLE = 0x8010002EL,

    //
    // MessageId: SCARD_E_COMM_DATA_LOST
    //
    // MessageText:
    //
    // A communications error with the smart card has been detected. Retry the operation.
    //
    SCARD_E_COMM_DATA_LOST = 0x8010002FL,

    //
    // MessageId: SCARD_E_NO_KEY_CONTAINER
    //
    // MessageText:
    //
    // The requested key container does not exist on the smart card.
    //
    SCARD_E_NO_KEY_CONTAINER = 0x80100030L,

    //
    // MessageId: SCARD_E_SERVER_TOO_BUSY
    //
    // MessageText:
    //
    // The Smart Card Resource Manager is too busy to complete this operation.
    //
    SCARD_E_SERVER_TOO_BUSY = 0x80100031L,

    //
    // MessageId: SCARD_E_PIN_CACHE_EXPIRED
    //
    // MessageText:
    //
    // The smart card PIN cache has expired.
    //
    SCARD_E_PIN_CACHE_EXPIRED = 0x80100032L,

    //
    // MessageId: SCARD_E_NO_PIN_CACHE
    //
    // MessageText:
    //
    // The smart card PIN cannot be cached.
    //
    SCARD_E_NO_PIN_CACHE = 0x80100033L,

    //
    // MessageId: SCARD_E_READ_ONLY_CARD
    //
    // MessageText:
    //
    // The smart card is read only and cannot be written to.
    //
    SCARD_E_READ_ONLY_CARD = 0x80100034L,

    //
    // These are warning codes.
    //
    //
    // MessageId: SCARD_W_UNSUPPORTED_CARD
    //
    // MessageText:
    //
    // The reader cannot communicate with the smart card, due to ATR configuration conflicts.
    //
    SCARD_W_UNSUPPORTED_CARD = 0x80100065L,

    //
    // MessageId: SCARD_W_UNRESPONSIVE_CARD
    //
    // MessageText:
    //
    // The smart card is not responding to a reset.
    //
    SCARD_W_UNRESPONSIVE_CARD = 0x80100066L,

    //
    // MessageId: SCARD_W_UNPOWERED_CARD
    //
    // MessageText:
    //
    // Power has been removed from the smart card, so that further communication is not possible.
    //
    SCARD_W_UNPOWERED_CARD = 0x80100067L,

    //
    // MessageId: SCARD_W_RESET_CARD
    //
    // MessageText:
    //
    // The smart card has been reset, so any shared state information is invalid.
    //
    SCARD_W_RESET_CARD = 0x80100068L,

    //
    // MessageId: SCARD_W_REMOVED_CARD
    //
    // MessageText:
    //
    // The smart card has been removed, so that further communication is not possible.
    //
    SCARD_W_REMOVED_CARD = 0x80100069L,

    //
    // MessageId: SCARD_W_SECURITY_VIOLATION
    //
    // MessageText:
    //
    // Access was denied because of a security violation.
    //
    SCARD_W_SECURITY_VIOLATION = 0x8010006AL,

    //
    // MessageId: SCARD_W_WRONG_CHV
    //
    // MessageText:
    //
    // The card cannot be accessed because the wrong PIN was presented.
    //
    SCARD_W_WRONG_CHV = 0x8010006BL,

    //
    // MessageId: SCARD_W_CHV_BLOCKED
    //
    // MessageText:
    //
    // The card cannot be accessed because the maximum number of PIN entry attempts has been reached.
    //
    SCARD_W_CHV_BLOCKED = 0x8010006CL,

    //
    // MessageId: SCARD_W_EOF
    //
    // MessageText:
    //
    // The end of the smart card file has been reached.
    //
    SCARD_W_EOF = 0x8010006DL,

    //
    // MessageId: SCARD_W_CANCELLED_BY_USER
    //
    // MessageText:
    //
    // The action was cancelled by the user.
    //
    SCARD_W_CANCELLED_BY_USER = 0x8010006EL,

    //
    // MessageId: SCARD_W_CARD_NOT_AUTHENTICATED
    //
    // MessageText:
    //
    // No PIN was presented to the smart card.
    //
    SCARD_W_CARD_NOT_AUTHENTICATED = 0x8010006FL,

    //
    // MessageId: SCARD_W_CACHE_ITEM_NOT_FOUND
    //
    // MessageText:
    //
    // The requested item could not be found in the cache.
    //
    SCARD_W_CACHE_ITEM_NOT_FOUND = 0x80100070L,

    //
    // MessageId: SCARD_W_CACHE_ITEM_STALE
    //
    // MessageText:
    //
    // The requested cache item is too old and was deleted from the cache.
    //
    SCARD_W_CACHE_ITEM_STALE = 0x80100071L,

    //
    // MessageId: SCARD_W_CACHE_ITEM_TOO_BIG
    //
    // MessageText:
    //
    // The new cache item exceeds the maximum per-item size defined for the cache.
    //
    SCARD_W_CACHE_ITEM_TOO_BIG = 0x80100072L,

    // *****************
    // FACILITY_COMPLUS
    // *****************
    //
    // ===============================
    // Facility COMPLUS Error Messages
    // ===============================
    //
    //
    // The following are the subranges  within the COMPLUS facility
    // 0x400 - 0x4ff               COMADMIN_E_CAT
    // 0x600 - 0x6ff               COMQC errors
    // 0x700 - 0x7ff               MSDTC errors
    // 0x800 - 0x8ff               Other COMADMIN errors
    //
    // COMPLUS Admin errors
    //
    //
    // MessageId: COMADMIN_E_OBJECTERRORS
    //
    // MessageText:
    //
    // Errors occurred accessing one or more objects - the ErrorInfo collection may have more detail
    //
    COMADMIN_E_OBJECTERRORS = 0x80110401L,

    //
    // MessageId: COMADMIN_E_OBJECTINVALID
    //
    // MessageText:
    //
    // One or more of the object's properties are missing or invalid
    //
    COMADMIN_E_OBJECTINVALID = 0x80110402L,

    //
    // MessageId: COMADMIN_E_KEYMISSING
    //
    // MessageText:
    //
    // The object was not found in the catalog
    //
    COMADMIN_E_KEYMISSING = 0x80110403L,

    //
    // MessageId: COMADMIN_E_ALREADYINSTALLED
    //
    // MessageText:
    //
    // The object is already registered
    //
    COMADMIN_E_ALREADYINSTALLED = 0x80110404L,

    //
    // MessageId: COMADMIN_E_APP_FILE_WRITEFAIL
    //
    // MessageText:
    //
    // Error occurred writing to the application file
    //
    COMADMIN_E_APP_FILE_WRITEFAIL = 0x80110407L,

    //
    // MessageId: COMADMIN_E_APP_FILE_READFAIL
    //
    // MessageText:
    //
    // Error occurred reading the application file
    //
    COMADMIN_E_APP_FILE_READFAIL = 0x80110408L,

    //
    // MessageId: COMADMIN_E_APP_FILE_VERSION
    //
    // MessageText:
    //
    // Invalid version number in application file
    //
    COMADMIN_E_APP_FILE_VERSION = 0x80110409L,

    //
    // MessageId: COMADMIN_E_BADPATH
    //
    // MessageText:
    //
    // The file path is invalid
    //
    COMADMIN_E_BADPATH = 0x8011040AL,

    //
    // MessageId: COMADMIN_E_APPLICATIONEXISTS
    //
    // MessageText:
    //
    // The application is already installed
    //
    COMADMIN_E_APPLICATIONEXISTS = 0x8011040BL,

    //
    // MessageId: COMADMIN_E_ROLEEXISTS
    //
    // MessageText:
    //
    // The role already exists
    //
    COMADMIN_E_ROLEEXISTS = 0x8011040CL,

    //
    // MessageId: COMADMIN_E_CANTCOPYFILE
    //
    // MessageText:
    //
    // An error occurred copying the file
    //
    COMADMIN_E_CANTCOPYFILE = 0x8011040DL,

    //
    // MessageId: COMADMIN_E_NOUSER
    //
    // MessageText:
    //
    // One or more users are not valid
    //
    COMADMIN_E_NOUSER = 0x8011040FL,

    //
    // MessageId: COMADMIN_E_INVALIDUSERIDS
    //
    // MessageText:
    //
    // One or more users in the application file are not valid
    //
    COMADMIN_E_INVALIDUSERIDS = 0x80110410L,

    //
    // MessageId: COMADMIN_E_NOREGISTRYCLSID
    //
    // MessageText:
    //
    // The component's CLSID is missing or corrupt
    //
    COMADMIN_E_NOREGISTRYCLSID = 0x80110411L,

    //
    // MessageId: COMADMIN_E_BADREGISTRYPROGID
    //
    // MessageText:
    //
    // The component's progID is missing or corrupt
    //
    COMADMIN_E_BADREGISTRYPROGID = 0x80110412L,

    //
    // MessageId: COMADMIN_E_AUTHENTICATIONLEVEL
    //
    // MessageText:
    //
    // Unable to set required authentication level for update request
    //
    COMADMIN_E_AUTHENTICATIONLEVEL = 0x80110413L,

    //
    // MessageId: COMADMIN_E_USERPASSWDNOTVALID
    //
    // MessageText:
    //
    // The identity or password set on the application is not valid
    //
    COMADMIN_E_USERPASSWDNOTVALID = 0x80110414L,

    //
    // MessageId: COMADMIN_E_CLSIDORIIDMISMATCH
    //
    // MessageText:
    //
    // Application file CLSIDs or IIDs do not match corresponding DLLs
    //
    COMADMIN_E_CLSIDORIIDMISMATCH = 0x80110418L,

    //
    // MessageId: COMADMIN_E_REMOTEINTERFACE
    //
    // MessageText:
    //
    // Interface information is either missing or changed
    //
    COMADMIN_E_REMOTEINTERFACE = 0x80110419L,

    //
    // MessageId: COMADMIN_E_DLLREGISTERSERVER
    //
    // MessageText:
    //
    // DllRegisterServer failed on component install
    //
    COMADMIN_E_DLLREGISTERSERVER = 0x8011041AL,

    //
    // MessageId: COMADMIN_E_NOSERVERSHARE
    //
    // MessageText:
    //
    // No server file share available
    //
    COMADMIN_E_NOSERVERSHARE = 0x8011041BL,

    //
    // MessageId: COMADMIN_E_DLLLOADFAILED
    //
    // MessageText:
    //
    // DLL could not be loaded
    //
    COMADMIN_E_DLLLOADFAILED = 0x8011041DL,

    //
    // MessageId: COMADMIN_E_BADREGISTRYLIBID
    //
    // MessageText:
    //
    // The registered TypeLib ID is not valid
    //
    COMADMIN_E_BADREGISTRYLIBID = 0x8011041EL,

    //
    // MessageId: COMADMIN_E_APPDIRNOTFOUND
    //
    // MessageText:
    //
    // Application install directory not found
    //
    COMADMIN_E_APPDIRNOTFOUND = 0x8011041FL,

    //
    // MessageId: COMADMIN_E_REGISTRARFAILED
    //
    // MessageText:
    //
    // Errors occurred while in the component registrar
    //
    COMADMIN_E_REGISTRARFAILED = 0x80110423L,

    //
    // MessageId: COMADMIN_E_COMPFILE_DOESNOTEXIST
    //
    // MessageText:
    //
    // The file does not exist
    //
    COMADMIN_E_COMPFILE_DOESNOTEXIST = 0x80110424L,

    //
    // MessageId: COMADMIN_E_COMPFILE_LOADDLLFAIL
    //
    // MessageText:
    //
    // The DLL could not be loaded
    //
    COMADMIN_E_COMPFILE_LOADDLLFAIL = 0x80110425L,

    //
    // MessageId: COMADMIN_E_COMPFILE_GETCLASSOBJ
    //
    // MessageText:
    //
    // GetClassObject failed in the DLL
    //
    COMADMIN_E_COMPFILE_GETCLASSOBJ = 0x80110426L,

    //
    // MessageId: COMADMIN_E_COMPFILE_CLASSNOTAVAIL
    //
    // MessageText:
    //
    // The DLL does not support the components listed in the TypeLib
    //
    COMADMIN_E_COMPFILE_CLASSNOTAVAIL = 0x80110427L,

    //
    // MessageId: COMADMIN_E_COMPFILE_BADTLB
    //
    // MessageText:
    //
    // The TypeLib could not be loaded
    //
    COMADMIN_E_COMPFILE_BADTLB = 0x80110428L,

    //
    // MessageId: COMADMIN_E_COMPFILE_NOTINSTALLABLE
    //
    // MessageText:
    //
    // The file does not contain components or component information
    //
    COMADMIN_E_COMPFILE_NOTINSTALLABLE = 0x80110429L,

    //
    // MessageId: COMADMIN_E_NOTCHANGEABLE
    //
    // MessageText:
    //
    // Changes to this object and its sub-objects have been disabled
    //
    COMADMIN_E_NOTCHANGEABLE = 0x8011042AL,

    //
    // MessageId: COMADMIN_E_NOTDELETEABLE
    //
    // MessageText:
    //
    // The delete function has been disabled for this object
    //
    COMADMIN_E_NOTDELETEABLE = 0x8011042BL,

    //
    // MessageId: COMADMIN_E_SESSION
    //
    // MessageText:
    //
    // The server catalog version is not supported
    //
    COMADMIN_E_SESSION = 0x8011042CL,

    //
    // MessageId: COMADMIN_E_COMP_MOVE_LOCKED
    //
    // MessageText:
    //
    // The component move was disallowed, because the source or destination application is either a system application or currently locked against changes
    //
    COMADMIN_E_COMP_MOVE_LOCKED = 0x8011042DL,

    //
    // MessageId: COMADMIN_E_COMP_MOVE_BAD_DEST
    //
    // MessageText:
    //
    // The component move failed because the destination application no longer exists
    //
    COMADMIN_E_COMP_MOVE_BAD_DEST = 0x8011042EL,

    //
    // MessageId: COMADMIN_E_REGISTERTLB
    //
    // MessageText:
    //
    // The system was unable to register the TypeLib
    //
    COMADMIN_E_REGISTERTLB = 0x80110430L,

    //
    // MessageId: COMADMIN_E_SYSTEMAPP
    //
    // MessageText:
    //
    // This operation cannot be performed on the system application
    //
    COMADMIN_E_SYSTEMAPP = 0x80110433L,

    //
    // MessageId: COMADMIN_E_COMPFILE_NOREGISTRAR
    //
    // MessageText:
    //
    // The component registrar referenced in this file is not available
    //
    COMADMIN_E_COMPFILE_NOREGISTRAR = 0x80110434L,

    //
    // MessageId: COMADMIN_E_COREQCOMPINSTALLED
    //
    // MessageText:
    //
    // A component in the same DLL is already installed
    //
    COMADMIN_E_COREQCOMPINSTALLED = 0x80110435L,

    //
    // MessageId: COMADMIN_E_SERVICENOTINSTALLED
    //
    // MessageText:
    //
    // The service is not installed
    //
    COMADMIN_E_SERVICENOTINSTALLED = 0x80110436L,

    //
    // MessageId: COMADMIN_E_PROPERTYSAVEFAILED
    //
    // MessageText:
    //
    // One or more property settings are either invalid or in conflict with each other
    //
    COMADMIN_E_PROPERTYSAVEFAILED = 0x80110437L,

    //
    // MessageId: COMADMIN_E_OBJECTEXISTS
    //
    // MessageText:
    //
    // The object you are attempting to add or rename already exists
    //
    COMADMIN_E_OBJECTEXISTS = 0x80110438L,

    //
    // MessageId: COMADMIN_E_COMPONENTEXISTS
    //
    // MessageText:
    //
    // The component already exists
    //
    COMADMIN_E_COMPONENTEXISTS = 0x80110439L,

    //
    // MessageId: COMADMIN_E_REGFILE_CORRUPT
    //
    // MessageText:
    //
    // The registration file is corrupt
    //
    COMADMIN_E_REGFILE_CORRUPT = 0x8011043BL,

    //
    // MessageId: COMADMIN_E_PROPERTY_OVERFLOW
    //
    // MessageText:
    //
    // The property value is too large
    //
    COMADMIN_E_PROPERTY_OVERFLOW = 0x8011043CL,

    //
    // MessageId: COMADMIN_E_NOTINREGISTRY
    //
    // MessageText:
    //
    // Object was not found in registry
    //
    COMADMIN_E_NOTINREGISTRY = 0x8011043EL,

    //
    // MessageId: COMADMIN_E_OBJECTNOTPOOLABLE
    //
    // MessageText:
    //
    // This object is not poolable
    //
    COMADMIN_E_OBJECTNOTPOOLABLE = 0x8011043FL,

    //
    // MessageId: COMADMIN_E_APPLID_MATCHES_CLSID
    //
    // MessageText:
    //
    // A CLSID with the same GUID as the new application ID is already installed on this machine
    //
    COMADMIN_E_APPLID_MATCHES_CLSID = 0x80110446L,

    //
    // MessageId: COMADMIN_E_ROLE_DOES_NOT_EXIST
    //
    // MessageText:
    //
    // A role assigned to a component, interface, or method did not exist in the application
    //
    COMADMIN_E_ROLE_DOES_NOT_EXIST = 0x80110447L,

    //
    // MessageId: COMADMIN_E_START_APP_NEEDS_COMPONENTS
    //
    // MessageText:
    //
    // You must have components in an application in order to start the application
    //
    COMADMIN_E_START_APP_NEEDS_COMPONENTS = 0x80110448L,

    //
    // MessageId: COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM
    //
    // MessageText:
    //
    // This operation is not enabled on this platform
    //
    COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM = 0x80110449L,

    //
    // MessageId: COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY
    //
    // MessageText:
    //
    // Application Proxy is not exportable
    //
    COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY = 0x8011044AL,

    //
    // MessageId: COMADMIN_E_CAN_NOT_START_APP
    //
    // MessageText:
    //
    // Failed to start application because it is either a library application or an application proxy
    //
    COMADMIN_E_CAN_NOT_START_APP = 0x8011044BL,

    //
    // MessageId: COMADMIN_E_CAN_NOT_EXPORT_SYS_APP
    //
    // MessageText:
    //
    // System application is not exportable
    //
    COMADMIN_E_CAN_NOT_EXPORT_SYS_APP = 0x8011044CL,

    //
    // MessageId: COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT
    //
    // MessageText:
    //
    // Cannot subscribe to this component (the component may have been imported)
    //
    COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT = 0x8011044DL,

    //
    // MessageId: COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER
    //
    // MessageText:
    //
    // An event class cannot also be a subscriber component
    //
    COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER = 0x8011044EL,

    //
    // MessageId: COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE
    //
    // MessageText:
    //
    // Library applications and application proxies are incompatible
    //
    COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE = 0x8011044FL,

    //
    // MessageId: COMADMIN_E_BASE_PARTITION_ONLY
    //
    // MessageText:
    //
    // This function is valid for the base partition only
    //
    COMADMIN_E_BASE_PARTITION_ONLY = 0x80110450L,

    //
    // MessageId: COMADMIN_E_START_APP_DISABLED
    //
    // MessageText:
    //
    // You cannot start an application that has been disabled
    //
    COMADMIN_E_START_APP_DISABLED = 0x80110451L,

    //
    // MessageId: COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME
    //
    // MessageText:
    //
    // The specified partition name is already in use on this computer
    //
    COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME = 0x80110457L,

    //
    // MessageId: COMADMIN_E_CAT_INVALID_PARTITION_NAME
    //
    // MessageText:
    //
    // The specified partition name is invalid. Check that the name contains at least one visible character
    //
    COMADMIN_E_CAT_INVALID_PARTITION_NAME = 0x80110458L,

    //
    // MessageId: COMADMIN_E_CAT_PARTITION_IN_USE
    //
    // MessageText:
    //
    // The partition cannot be deleted because it is the default partition for one or more users
    //
    COMADMIN_E_CAT_PARTITION_IN_USE = 0x80110459L,

    //
    // MessageId: COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES
    //
    // MessageText:
    //
    // The partition cannot be exported, because one or more components in the partition have the same file name
    //
    COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES = 0x8011045AL,

    //
    // MessageId: COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED
    //
    // MessageText:
    //
    // Applications that contain one or more imported components cannot be installed into a non-base partition
    //
    COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED = 0x8011045BL,

    //
    // MessageId: COMADMIN_E_AMBIGUOUS_APPLICATION_NAME
    //
    // MessageText:
    //
    // The application name is not unique and cannot be resolved to an application id
    //
    COMADMIN_E_AMBIGUOUS_APPLICATION_NAME = 0x8011045CL,

    //
    // MessageId: COMADMIN_E_AMBIGUOUS_PARTITION_NAME
    //
    // MessageText:
    //
    // The partition name is not unique and cannot be resolved to a partition id
    //
    COMADMIN_E_AMBIGUOUS_PARTITION_NAME = 0x8011045DL,

    //
    // MessageId: COMADMIN_E_REGDB_NOTINITIALIZED
    //
    // MessageText:
    //
    // The COM+ registry database has not been initialized
    //
    COMADMIN_E_REGDB_NOTINITIALIZED = 0x80110472L,

    //
    // MessageId: COMADMIN_E_REGDB_NOTOPEN
    //
    // MessageText:
    //
    // The COM+ registry database is not open
    //
    COMADMIN_E_REGDB_NOTOPEN = 0x80110473L,

    //
    // MessageId: COMADMIN_E_REGDB_SYSTEMERR
    //
    // MessageText:
    //
    // The COM+ registry database detected a system error
    //
    COMADMIN_E_REGDB_SYSTEMERR = 0x80110474L,

    //
    // MessageId: COMADMIN_E_REGDB_ALREADYRUNNING
    //
    // MessageText:
    //
    // The COM+ registry database is already running
    //
    COMADMIN_E_REGDB_ALREADYRUNNING = 0x80110475L,

    //
    // MessageId: COMADMIN_E_MIG_VERSIONNOTSUPPORTED
    //
    // MessageText:
    //
    // This version of the COM+ registry database cannot be migrated
    //
    COMADMIN_E_MIG_VERSIONNOTSUPPORTED = 0x80110480L,

    //
    // MessageId: COMADMIN_E_MIG_SCHEMANOTFOUND
    //
    // MessageText:
    //
    // The schema version to be migrated could not be found in the COM+ registry database
    //
    COMADMIN_E_MIG_SCHEMANOTFOUND = 0x80110481L,

    //
    // MessageId: COMADMIN_E_CAT_BITNESSMISMATCH
    //
    // MessageText:
    //
    // There was a type mismatch between binaries
    //
    COMADMIN_E_CAT_BITNESSMISMATCH = 0x80110482L,

    //
    // MessageId: COMADMIN_E_CAT_UNACCEPTABLEBITNESS
    //
    // MessageText:
    //
    // A binary of unknown or invalid type was provided
    //
    COMADMIN_E_CAT_UNACCEPTABLEBITNESS = 0x80110483L,

    //
    // MessageId: COMADMIN_E_CAT_WRONGAPPBITNESS
    //
    // MessageText:
    //
    // There was a type mismatch between a binary and an application
    //
    COMADMIN_E_CAT_WRONGAPPBITNESS = 0x80110484L,

    //
    // MessageId: COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The application cannot be paused or resumed
    //
    COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED = 0x80110485L,

    //
    // MessageId: COMADMIN_E_CAT_SERVERFAULT
    //
    // MessageText:
    //
    // The COM+ Catalog Server threw an exception during execution
    //
    COMADMIN_E_CAT_SERVERFAULT = 0x80110486L,

    //
    // COMPLUS Queued component errors
    //
    //
    // MessageId: COMQC_E_APPLICATION_NOT_QUEUED
    //
    // MessageText:
    //
    // Only COM+ Applications marked "queued" can be invoked using the "queue" moniker
    //
    COMQC_E_APPLICATION_NOT_QUEUED = 0x80110600L,

    //
    // MessageId: COMQC_E_NO_QUEUEABLE_INTERFACES
    //
    // MessageText:
    //
    // At least one interface must be marked "queued" in order to create a queued component instance with the "queue" moniker
    //
    COMQC_E_NO_QUEUEABLE_INTERFACES = 0x80110601L,

    //
    // MessageId: COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE
    //
    // MessageText:
    //
    // MSMQ is required for the requested operation and is not installed
    //
    COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE = 0x80110602L,

    //
    // MessageId: COMQC_E_NO_IPERSISTSTREAM
    //
    // MessageText:
    //
    // Unable to marshal an interface that does not support IPersistStream
    //
    COMQC_E_NO_IPERSISTSTREAM = 0x80110603L,

    //
    // MessageId: COMQC_E_BAD_MESSAGE
    //
    // MessageText:
    //
    // The message is improperly formatted or was damaged in transit
    //
    COMQC_E_BAD_MESSAGE = 0x80110604L,

    //
    // MessageId: COMQC_E_UNAUTHENTICATED
    //
    // MessageText:
    //
    // An unauthenticated message was received by an application that accepts only authenticated messages
    //
    COMQC_E_UNAUTHENTICATED = 0x80110605L,

    //
    // MessageId: COMQC_E_UNTRUSTED_ENQUEUER
    //
    // MessageText:
    //
    // The message was requeued or moved by a user not in the "QC Trusted User" role
    //
    COMQC_E_UNTRUSTED_ENQUEUER = 0x80110606L,

    //
    // The range 0x700-0x7ff is reserved for MSDTC errors.
    //
    //
    // MessageId: MSDTC_E_DUPLICATE_RESOURCE
    //
    // MessageText:
    //
    // Cannot create a duplicate resource of type Distributed Transaction Coordinator
    //
    MSDTC_E_DUPLICATE_RESOURCE = 0x80110701L,

    //
    // More COMADMIN errors from 0x8**
    //
    //
    // MessageId: COMADMIN_E_OBJECT_PARENT_MISSING
    //
    // MessageText:
    //
    // One of the objects being inserted or updated does not belong to a valid parent collection
    //
    COMADMIN_E_OBJECT_PARENT_MISSING = 0x80110808L,

    //
    // MessageId: COMADMIN_E_OBJECT_DOES_NOT_EXIST
    //
    // MessageText:
    //
    // One of the specified objects cannot be found
    //
    COMADMIN_E_OBJECT_DOES_NOT_EXIST = 0x80110809L,

    //
    // MessageId: COMADMIN_E_APP_NOT_RUNNING
    //
    // MessageText:
    //
    // The specified application is not currently running
    //
    COMADMIN_E_APP_NOT_RUNNING = 0x8011080AL,

    //
    // MessageId: COMADMIN_E_INVALID_PARTITION
    //
    // MessageText:
    //
    // The partition(s) specified are not valid.
    //
    COMADMIN_E_INVALID_PARTITION = 0x8011080BL,

    //
    // MessageId: COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE
    //
    // MessageText:
    //
    // COM+ applications that run as NT service may not be pooled or recycled
    //
    COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE = 0x8011080DL,

    //
    // MessageId: COMADMIN_E_USER_IN_SET
    //
    // MessageText:
    //
    // One or more users are already assigned to a local partition set.
    //
    COMADMIN_E_USER_IN_SET = 0x8011080EL,

    //
    // MessageId: COMADMIN_E_CANTRECYCLELIBRARYAPPS
    //
    // MessageText:
    //
    // Library applications may not be recycled.
    //
    COMADMIN_E_CANTRECYCLELIBRARYAPPS = 0x8011080FL,

    //
    // MessageId: COMADMIN_E_CANTRECYCLESERVICEAPPS
    //
    // MessageText:
    //
    // Applications running as NT services may not be recycled.
    //
    COMADMIN_E_CANTRECYCLESERVICEAPPS = 0x80110811L,

    //
    // MessageId: COMADMIN_E_PROCESSALREADYRECYCLED
    //
    // MessageText:
    //
    // The process has already been recycled.
    //
    COMADMIN_E_PROCESSALREADYRECYCLED = 0x80110812L,

    //
    // MessageId: COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED
    //
    // MessageText:
    //
    // A paused process may not be recycled.
    //
    COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED = 0x80110813L,

    //
    // MessageId: COMADMIN_E_CANTMAKEINPROCSERVICE
    //
    // MessageText:
    //
    // Library applications may not be NT services.
    //
    COMADMIN_E_CANTMAKEINPROCSERVICE = 0x80110814L,

    //
    // MessageId: COMADMIN_E_PROGIDINUSEBYCLSID
    //
    // MessageText:
    //
    // The ProgID provided to the copy operation is invalid. The ProgID is in use by another registered CLSID.
    //
    COMADMIN_E_PROGIDINUSEBYCLSID = 0x80110815L,

    //
    // MessageId: COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET
    //
    // MessageText:
    //
    // The partition specified as default is not a member of the partition set.
    //
    COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET = 0x80110816L,

    //
    // MessageId: COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED
    //
    // MessageText:
    //
    // A recycled process may not be paused.
    //
    COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED = 0x80110817L,

    //
    // MessageId: COMADMIN_E_PARTITION_ACCESSDENIED
    //
    // MessageText:
    //
    // Access to the specified partition is denied.
    //
    COMADMIN_E_PARTITION_ACCESSDENIED = 0x80110818L,

    //
    // MessageId: COMADMIN_E_PARTITION_MSI_ONLY
    //
    // MessageText:
    //
    // Only Application Files (*.MSI files) can be installed into partitions.
    //
    COMADMIN_E_PARTITION_MSI_ONLY = 0x80110819L,

    //
    // MessageId: COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT
    //
    // MessageText:
    //
    // Applications containing one or more legacy components may not be exported to 1.0 format.
    //
    COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT = 0x8011081AL,

    //
    // MessageId: COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS
    //
    // MessageText:
    //
    // Legacy components may not exist in non-base partitions.
    //
    COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS = 0x8011081BL,

    //
    // MessageId: COMADMIN_E_COMP_MOVE_SOURCE
    //
    // MessageText:
    //
    // A component cannot be moved (or copied) from the System Application, an application proxy or a non-changeable application
    //
    COMADMIN_E_COMP_MOVE_SOURCE = 0x8011081CL,

    //
    // MessageId: COMADMIN_E_COMP_MOVE_DEST
    //
    // MessageText:
    //
    // A component cannot be moved (or copied) to the System Application, an application proxy or a non-changeable application
    //
    COMADMIN_E_COMP_MOVE_DEST = 0x8011081DL,

    //
    // MessageId: COMADMIN_E_COMP_MOVE_PRIVATE
    //
    // MessageText:
    //
    // A private component cannot be moved (or copied) to a library application or to the base partition
    //
    COMADMIN_E_COMP_MOVE_PRIVATE = 0x8011081EL,

    //
    // MessageId: COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET
    //
    // MessageText:
    //
    // The Base Application Partition exists in all partition sets and cannot be removed.
    //
    COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET = 0x8011081FL,

    //
    // MessageId: COMADMIN_E_CANNOT_ALIAS_EVENTCLASS
    //
    // MessageText:
    //
    // Alas, Event Class components cannot be aliased.
    //
    COMADMIN_E_CANNOT_ALIAS_EVENTCLASS = 0x80110820L,

    //
    // MessageId: COMADMIN_E_PRIVATE_ACCESSDENIED
    //
    // MessageText:
    //
    // Access is denied because the component is private.
    //
    COMADMIN_E_PRIVATE_ACCESSDENIED = 0x80110821L,

    //
    // MessageId: COMADMIN_E_SAFERINVALID
    //
    // MessageText:
    //
    // The specified SAFER level is invalid.
    //
    COMADMIN_E_SAFERINVALID = 0x80110822L,

    //
    // MessageId: COMADMIN_E_REGISTRY_ACCESSDENIED
    //
    // MessageText:
    //
    // The specified user cannot write to the system registry
    //
    COMADMIN_E_REGISTRY_ACCESSDENIED = 0x80110823L,

    //
    // MessageId: COMADMIN_E_PARTITIONS_DISABLED
    //
    // MessageText:
    //
    // COM+ partitions are currently disabled.
    //
    COMADMIN_E_PARTITIONS_DISABLED = 0x80110824L,

    //
    // FACILITY_WER
    //
    //
    // MessageId: WER_S_REPORT_DEBUG
    //
    // MessageText:
    //
    // Debugger was attached.
    //
    WER_S_REPORT_DEBUG = 0x001B0000L,

    //
    // MessageId: WER_S_REPORT_UPLOADED
    //
    // MessageText:
    //
    // Report was uploaded.
    //
    WER_S_REPORT_UPLOADED = 0x001B0001L,

    //
    // MessageId: WER_S_REPORT_QUEUED
    //
    // MessageText:
    //
    // Report was queued.
    //
    WER_S_REPORT_QUEUED = 0x001B0002L,

    //
    // MessageId: WER_S_DISABLED
    //
    // MessageText:
    //
    // Reporting was disabled.
    //
    WER_S_DISABLED = 0x001B0003L,

    //
    // MessageId: WER_S_SUSPENDED_UPLOAD
    //
    // MessageText:
    //
    // Reporting was temporarily suspended.
    //
    WER_S_SUSPENDED_UPLOAD = 0x001B0004L,

    //
    // MessageId: WER_S_DISABLED_QUEUE
    //
    // MessageText:
    //
    // Report was not queued to queueing being disabled.
    //
    WER_S_DISABLED_QUEUE = 0x001B0005L,

    //
    // MessageId: WER_S_DISABLED_ARCHIVE
    //
    // MessageText:
    //
    // Report was uploaded, but not archived due to archiving being disabled.
    //
    WER_S_DISABLED_ARCHIVE = 0x001B0006L,

    //
    // MessageId: WER_S_REPORT_ASYNC
    //
    // MessageText:
    //
    // Reporting was successfully spun off as an asynchronous operation.
    //
    WER_S_REPORT_ASYNC = 0x001B0007L,

    //
    // MessageId: WER_S_IGNORE_ASSERT_INSTANCE
    //
    // MessageText:
    //
    // The assertion was handled.
    //
    WER_S_IGNORE_ASSERT_INSTANCE = 0x001B0008L,

    //
    // MessageId: WER_S_IGNORE_ALL_ASSERTS
    //
    // MessageText:
    //
    // The assertion was handled and added to a permanent ignore list.
    //
    WER_S_IGNORE_ALL_ASSERTS = 0x001B0009L,

    //
    // MessageId: WER_S_ASSERT_CONTINUE
    //
    // MessageText:
    //
    // The assertion was resumed as unhandled.
    //
    WER_S_ASSERT_CONTINUE = 0x001B000AL,

    //
    // MessageId: WER_S_THROTTLED
    //
    // MessageText:
    //
    // Report was throttled.
    //
    WER_S_THROTTLED = 0x001B000BL,

    //
    // MessageId: WER_E_CRASH_FAILURE
    //
    // MessageText:
    //
    // Crash reporting failed.
    //
    WER_E_CRASH_FAILURE = 0x801B8000L,

    //
    // MessageId: WER_E_CANCELED
    //
    // MessageText:
    //
    // Report aborted due to user cancelation.
    //
    WER_E_CANCELED = 0x801B8001L,

    //
    // MessageId: WER_E_NETWORK_FAILURE
    //
    // MessageText:
    //
    // Report aborted due to network failure.
    //
    WER_E_NETWORK_FAILURE = 0x801B8002L,

    //
    // MessageId: WER_E_NOT_INITIALIZED
    //
    // MessageText:
    //
    // Report not initialized.
    //
    WER_E_NOT_INITIALIZED = 0x801B8003L,

    //
    // MessageId: WER_E_ALREADY_REPORTING
    //
    // MessageText:
    //
    // Reporting is already in progress for the specified process.
    //
    WER_E_ALREADY_REPORTING = 0x801B8004L,

    //
    // MessageId: WER_E_DUMP_THROTTLED
    //
    // MessageText:
    //
    // Dump not generated due to a throttle.
    //
    WER_E_DUMP_THROTTLED = 0x801B8005L,

    //
    // MessageId: ERROR_FLT_IO_COMPLETE
    //
    // MessageText:
    //
    // The IO was completed by a filter.
    //
    ERROR_FLT_IO_COMPLETE = 0x001F0001L,

    //
    // MessageId: ERROR_FLT_NO_HANDLER_DEFINED
    //
    // MessageText:
    //
    // A handler was not defined by the filter for this operation.
    //
    ERROR_FLT_NO_HANDLER_DEFINED = 0x801F0001L,

    //
    // MessageId: ERROR_FLT_CONTEXT_ALREADY_DEFINED
    //
    // MessageText:
    //
    // A context is already defined for this object.
    //
    ERROR_FLT_CONTEXT_ALREADY_DEFINED = 0x801F0002L,

    //
    // MessageId: ERROR_FLT_INVALID_ASYNCHRONOUS_REQUEST
    //
    // MessageText:
    //
    // Asynchronous requests are not valid for this operation.
    //
    ERROR_FLT_INVALID_ASYNCHRONOUS_REQUEST = 0x801F0003L,

    //
    // MessageId: ERROR_FLT_DISALLOW_FAST_IO
    //
    // MessageText:
    //
    // Disallow the Fast IO path for this operation.
    //
    ERROR_FLT_DISALLOW_FAST_IO = 0x801F0004L,

    //
    // MessageId: ERROR_FLT_INVALID_NAME_REQUEST
    //
    // MessageText:
    //
    // An invalid name request was made. The name requested cannot be retrieved at this time.
    //
    ERROR_FLT_INVALID_NAME_REQUEST = 0x801F0005L,

    //
    // MessageId: ERROR_FLT_NOT_SAFE_TO_POST_OPERATION
    //
    // MessageText:
    //
    // Posting this operation to a worker thread for further processing is not safe at this time because it could lead to a system deadlock.
    //
    ERROR_FLT_NOT_SAFE_TO_POST_OPERATION = 0x801F0006L,

    //
    // MessageId: ERROR_FLT_NOT_INITIALIZED
    //
    // MessageText:
    //
    // The Filter Manager was not initialized when a filter tried to register. Make sure that the Filter Manager is getting loaded as a driver.
    //
    ERROR_FLT_NOT_INITIALIZED = 0x801F0007L,

    //
    // MessageId: ERROR_FLT_FILTER_NOT_READY
    //
    // MessageText:
    //
    // The filter is not ready for attachment to volumes because it has not finished initializing (FltStartFiltering has not been called).
    //
    ERROR_FLT_FILTER_NOT_READY = 0x801F0008L,

    //
    // MessageId: ERROR_FLT_POST_OPERATION_CLEANUP
    //
    // MessageText:
    //
    // The filter must cleanup any operation specific context at this time because it is being removed from the system before the operation is completed by the lower drivers.
    //
    ERROR_FLT_POST_OPERATION_CLEANUP = 0x801F0009L,

    //
    // MessageId: ERROR_FLT_INTERNAL_ERROR
    //
    // MessageText:
    //
    // The Filter Manager had an internal error from which it cannot recover, therefore the operation has been failed. This is usually the result of a filter returning an invalid value from a pre-operation callback.
    //
    ERROR_FLT_INTERNAL_ERROR = 0x801F000AL,

    //
    // MessageId: ERROR_FLT_DELETING_OBJECT
    //
    // MessageText:
    //
    // The object specified for this action is in the process of being deleted, therefore the action requested cannot be completed at this time.
    //
    ERROR_FLT_DELETING_OBJECT = 0x801F000BL,

    //
    // MessageId: ERROR_FLT_MUST_BE_NONPAGED_POOL
    //
    // MessageText:
    //
    // Non-paged pool must be used for this type of context.
    //
    ERROR_FLT_MUST_BE_NONPAGED_POOL = 0x801F000CL,

    //
    // MessageId: ERROR_FLT_DUPLICATE_ENTRY
    //
    // MessageText:
    //
    // A duplicate handler definition has been provided for an operation.
    //
    ERROR_FLT_DUPLICATE_ENTRY = 0x801F000DL,

    //
    // MessageId: ERROR_FLT_CBDQ_DISABLED
    //
    // MessageText:
    //
    // The callback data queue has been disabled.
    //
    ERROR_FLT_CBDQ_DISABLED = 0x801F000EL,

    //
    // MessageId: ERROR_FLT_DO_NOT_ATTACH
    //
    // MessageText:
    //
    // Do not attach the filter to the volume at this time.
    //
    ERROR_FLT_DO_NOT_ATTACH = 0x801F000FL,

    //
    // MessageId: ERROR_FLT_DO_NOT_DETACH
    //
    // MessageText:
    //
    // Do not detach the filter from the volume at this time.
    //
    ERROR_FLT_DO_NOT_DETACH = 0x801F0010L,

    //
    // MessageId: ERROR_FLT_INSTANCE_ALTITUDE_COLLISION
    //
    // MessageText:
    //
    // An instance already exists at this altitude on the volume specified.
    //
    ERROR_FLT_INSTANCE_ALTITUDE_COLLISION = 0x801F0011L,

    //
    // MessageId: ERROR_FLT_INSTANCE_NAME_COLLISION
    //
    // MessageText:
    //
    // An instance already exists with this name on the volume specified.
    //
    ERROR_FLT_INSTANCE_NAME_COLLISION = 0x801F0012L,

    //
    // MessageId: ERROR_FLT_FILTER_NOT_FOUND
    //
    // MessageText:
    //
    // The system could not find the filter specified.
    //
    ERROR_FLT_FILTER_NOT_FOUND = 0x801F0013L,

    //
    // MessageId: ERROR_FLT_VOLUME_NOT_FOUND
    //
    // MessageText:
    //
    // The system could not find the volume specified.
    //
    ERROR_FLT_VOLUME_NOT_FOUND = 0x801F0014L,

    //
    // MessageId: ERROR_FLT_INSTANCE_NOT_FOUND
    //
    // MessageText:
    //
    // The system could not find the instance specified.
    //
    ERROR_FLT_INSTANCE_NOT_FOUND = 0x801F0015L,

    //
    // MessageId: ERROR_FLT_CONTEXT_ALLOCATION_NOT_FOUND
    //
    // MessageText:
    //
    // No registered context allocation definition was found for the given request.
    //
    ERROR_FLT_CONTEXT_ALLOCATION_NOT_FOUND = 0x801F0016L,

    //
    // MessageId: ERROR_FLT_INVALID_CONTEXT_REGISTRATION
    //
    // MessageText:
    //
    // An invalid parameter was specified during context registration.
    //
    ERROR_FLT_INVALID_CONTEXT_REGISTRATION = 0x801F0017L,

    //
    // MessageId: ERROR_FLT_NAME_CACHE_MISS
    //
    // MessageText:
    //
    // The name requested was not found in Filter Manager's name cache and could not be retrieved from the file system.
    //
    ERROR_FLT_NAME_CACHE_MISS = 0x801F0018L,

    //
    // MessageId: ERROR_FLT_NO_DEVICE_OBJECT
    //
    // MessageText:
    //
    // The requested device object does not exist for the given volume.
    //
    ERROR_FLT_NO_DEVICE_OBJECT = 0x801F0019L,

    //
    // MessageId: ERROR_FLT_VOLUME_ALREADY_MOUNTED
    //
    // MessageText:
    //
    // The specified volume is already mounted.
    //
    ERROR_FLT_VOLUME_ALREADY_MOUNTED = 0x801F001AL,

    //
    // MessageId: ERROR_FLT_ALREADY_ENLISTED
    //
    // MessageText:
    //
    // The specified Transaction Context is already enlisted in a transaction
    //
    ERROR_FLT_ALREADY_ENLISTED = 0x801F001BL,

    //
    // MessageId: ERROR_FLT_CONTEXT_ALREADY_LINKED
    //
    // MessageText:
    //
    // The specifiec context is already attached to another object
    //
    ERROR_FLT_CONTEXT_ALREADY_LINKED = 0x801F001CL,

    //
    // MessageId: ERROR_FLT_NO_WAITER_FOR_REPLY
    //
    // MessageText:
    //
    // No waiter is present for the filter's reply to this message.
    //
    ERROR_FLT_NO_WAITER_FOR_REPLY = 0x801F0020L,

    //
    // MessageId: ERROR_FLT_REGISTRATION_BUSY
    //
    // MessageText:
    //
    // The filesystem database resource is in use. Registration cannot complete at this time.
    //
    ERROR_FLT_REGISTRATION_BUSY = 0x801F0023L,

    //
    // ===============================
    // Facility Graphics Error Messages
    // ===============================
    //
    //
    // The following are the subranges within the Graphics facility
    //
    // 0x0000 - 0x0fff     Display Driver Loader driver & Video Port errors (displdr.sys, videoprt.sys)
    // 0x1000 - 0x1fff     Monitor Class Function driver errors             (monitor.sys)
    // 0x2000 - 0x2fff     Windows Graphics Kernel Subsystem errors         (dxgkrnl.sys)
    // 0x3000 - 0x3fff               Desktop Window Manager errors
    //   0x2000 - 0x20ff      Common errors
    //   0x2100 - 0x21ff      Video Memory Manager (VidMM) subsystem errors
    //   0x2200 - 0x22ff      Video GPU Scheduler (VidSch) subsystem errors
    //   0x2300 - 0x23ff      Video Display Mode Management (VidDMM) subsystem errors
    //
    // Display Driver Loader driver & Video Port errors {0x0000..0x0fff}
    //
    //
    // MessageId: ERROR_HUNG_DISPLAY_DRIVER_THREAD
    //
    // MessageText:
    //
    // {Display Driver Stopped Responding}
    // The %hs display driver has stopped working normally. Save your work and reboot the system to restore full display functionality.
    // The next time you reboot the machine a dialog will be displayed giving you a chance to report this failure to Microsoft.
    //
    ERROR_HUNG_DISPLAY_DRIVER_THREAD = 0x80260001L,

    //
    // Desktop Window Manager errors {0x3000..0x3fff}
    //
    //
    // MessageId: DWM_E_COMPOSITIONDISABLED
    //
    // MessageText:
    //
    // {Desktop composition is disabled}
    // The operation could not be completed because desktop composition is disabled.
    //
    DWM_E_COMPOSITIONDISABLED = 0x80263001L,

    //
    // MessageId: DWM_E_REMOTING_NOT_SUPPORTED
    //
    // MessageText:
    //
    // {Some desktop composition APIs are not supported while remoting}
    // The operation is not supported while running in a remote session.
    //
    DWM_E_REMOTING_NOT_SUPPORTED = 0x80263002L,

    //
    // MessageId: DWM_E_NO_REDIRECTION_SURFACE_AVAILABLE
    //
    // MessageText:
    //
    // {No DWM redirection surface is available}
    // The DWM was unable to provide a redireciton surface to complete the DirectX present.
    //
    DWM_E_NO_REDIRECTION_SURFACE_AVAILABLE = 0x80263003L,

    //
    // MessageId: DWM_E_NOT_QUEUING_PRESENTS
    //
    // MessageText:
    //
    // {DWM is not queuing presents for the specified window}
    // The window specified is not currently using queued presents.
    //
    DWM_E_NOT_QUEUING_PRESENTS = 0x80263004L,

    //
    // MessageId: DWM_E_ADAPTER_NOT_FOUND
    //
    // MessageText:
    //
    // {The adapter specified by the LUID is not found}
    // DWM can not find the adapter specified by the LUID.
    //
    DWM_E_ADAPTER_NOT_FOUND = 0x80263005L,

    //
    // MessageId: DWM_S_GDI_REDIRECTION_SURFACE
    //
    // MessageText:
    //
    // {GDI redirection surface was returned}
    // GDI redirection surface of the top level window was returned.
    //
    DWM_S_GDI_REDIRECTION_SURFACE = 0x00263005L,

    //
    // MessageId: DWM_E_TEXTURE_TOO_LARGE
    //
    // MessageText:
    //
    // {Redirection surface can not be created.  The size of the surface is larger than what is supported on this machine}
    // Redirection surface can not be created.  The size of the surface is larger than what is supported on this machine.
    //
    DWM_E_TEXTURE_TOO_LARGE = 0x80263007L,

    //
    // Monitor class function driver errors {0x1000..0x1fff}
    //
    //
    // MessageId: ERROR_MONITOR_NO_DESCRIPTOR
    //
    // MessageText:
    //
    // Monitor descriptor could not be obtained.
    //
    ERROR_MONITOR_NO_DESCRIPTOR = 0x80261001L,

    //
    // MessageId: ERROR_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT
    //
    // MessageText:
    //
    // Format of the obtained monitor descriptor is not supported by this release.
    //
    ERROR_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT = 0x80261002L,

    //
    // MessageId: ERROR_MONITOR_INVALID_DESCRIPTOR_CHECKSUM
    //
    // MessageText:
    //
    // Checksum of the obtained monitor descriptor is invalid.
    //
    ERROR_MONITOR_INVALID_DESCRIPTOR_CHECKSUM = 0xC0261003L,

    //
    // MessageId: ERROR_MONITOR_INVALID_STANDARD_TIMING_BLOCK
    //
    // MessageText:
    //
    // Monitor descriptor contains an invalid standard timing block.
    //
    ERROR_MONITOR_INVALID_STANDARD_TIMING_BLOCK = 0xC0261004L,

    //
    // MessageId: ERROR_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED
    //
    // MessageText:
    //
    // WMI data block registration failed for one of the MSMonitorClass WMI subclasses.
    //
    ERROR_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED = 0xC0261005L,

    //
    // MessageId: ERROR_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK
    //
    // MessageText:
    //
    // Provided monitor descriptor block is either corrupted or does not contain monitor's detailed serial number.
    //
    ERROR_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK = 0xC0261006L,

    //
    // MessageId: ERROR_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK
    //
    // MessageText:
    //
    // Provided monitor descriptor block is either corrupted or does not contain monitor's user friendly name.
    //
    ERROR_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK = 0xC0261007L,

    //
    // MessageId: ERROR_MONITOR_NO_MORE_DESCRIPTOR_DATA
    //
    // MessageText:
    //
    // There is no monitor descriptor data at the specified (offset, size) region.
    //
    ERROR_MONITOR_NO_MORE_DESCRIPTOR_DATA = 0xC0261008L,

    //
    // MessageId: ERROR_MONITOR_INVALID_DETAILED_TIMING_BLOCK
    //
    // MessageText:
    //
    // Monitor descriptor contains an invalid detailed timing block.
    //
    ERROR_MONITOR_INVALID_DETAILED_TIMING_BLOCK = 0xC0261009L,

    //
    // MessageId: ERROR_MONITOR_INVALID_MANUFACTURE_DATE
    //
    // MessageText:
    //
    // Monitor descriptor contains invalid manufacture date.
    //
    ERROR_MONITOR_INVALID_MANUFACTURE_DATE = 0xC026100AL,

    //
    // Windows Graphics Kernel Subsystem errors {0x2000..0x2fff}
    //
    // TODO: Add DXG Win32 errors here
    //
    // Common errors {0x2000..0x20ff}
    //
    //
    // MessageId: ERROR_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER
    //
    // MessageText:
    //
    // Exclusive mode ownership is needed to create unmanaged primary allocation.
    //
    ERROR_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER = 0xC0262000L,

    //
    // MessageId: ERROR_GRAPHICS_INSUFFICIENT_DMA_BUFFER
    //
    // MessageText:
    //
    // The driver needs more DMA buffer space in order to complete the requested operation.
    //
    ERROR_GRAPHICS_INSUFFICIENT_DMA_BUFFER = 0xC0262001L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER
    //
    // MessageText:
    //
    // Specified display adapter handle is invalid.
    //
    ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER = 0xC0262002L,

    //
    // MessageId: ERROR_GRAPHICS_ADAPTER_WAS_RESET
    //
    // MessageText:
    //
    // Specified display adapter and all of its state has been reset.
    //
    ERROR_GRAPHICS_ADAPTER_WAS_RESET = 0xC0262003L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_DRIVER_MODEL
    //
    // MessageText:
    //
    // The driver stack doesn't match the expected driver model.
    //
    ERROR_GRAPHICS_INVALID_DRIVER_MODEL = 0xC0262004L,

    //
    // MessageId: ERROR_GRAPHICS_PRESENT_MODE_CHANGED
    //
    // MessageText:
    //
    // Present happened but ended up into the changed desktop mode
    //
    ERROR_GRAPHICS_PRESENT_MODE_CHANGED = 0xC0262005L,

    //
    // MessageId: ERROR_GRAPHICS_PRESENT_OCCLUDED
    //
    // MessageText:
    //
    // Nothing to present due to desktop occlusion
    //
    ERROR_GRAPHICS_PRESENT_OCCLUDED = 0xC0262006L,

    //
    // MessageId: ERROR_GRAPHICS_PRESENT_DENIED
    //
    // MessageText:
    //
    // Not able to present due to denial of desktop access
    //
    ERROR_GRAPHICS_PRESENT_DENIED = 0xC0262007L,

    //
    // MessageId: ERROR_GRAPHICS_CANNOTCOLORCONVERT
    //
    // MessageText:
    //
    // Not able to present with color convertion
    //
    ERROR_GRAPHICS_CANNOTCOLORCONVERT = 0xC0262008L,

    //
    // MessageId: ERROR_GRAPHICS_DRIVER_MISMATCH
    //
    // MessageText:
    //
    // The kernel driver detected a version mismatch between it and the user mode driver.
    //
    ERROR_GRAPHICS_DRIVER_MISMATCH = 0xC0262009L,

    //
    // MessageId: ERROR_GRAPHICS_PARTIAL_DATA_POPULATED
    //
    // MessageText:
    //
    // Specified buffer is not big enough to contain entire requested dataset. Partial data populated up to the size of the buffer. Caller needs to provide buffer of size as specified in the partially populated buffer's content (interface specific).
    //
    ERROR_GRAPHICS_PARTIAL_DATA_POPULATED = 0x4026200AL,

    //
    // MessageId: ERROR_GRAPHICS_PRESENT_REDIRECTION_DISABLED
    //
    // MessageText:
    //
    // Present redirection is disabled (desktop windowing management subsystem is off).
    //
    ERROR_GRAPHICS_PRESENT_REDIRECTION_DISABLED = 0xC026200BL,

    //
    // MessageId: ERROR_GRAPHICS_PRESENT_UNOCCLUDED
    //
    // MessageText:
    //
    // Previous exclusive VidPn source owner has released its ownership
    //
    ERROR_GRAPHICS_PRESENT_UNOCCLUDED = 0xC026200CL,

    //
    // MessageId: ERROR_GRAPHICS_WINDOWDC_NOT_AVAILABLE
    //
    // MessageText:
    //
    // Window DC is not available for presentation
    //
    ERROR_GRAPHICS_WINDOWDC_NOT_AVAILABLE = 0xC026200DL,

    //
    // MessageId: ERROR_GRAPHICS_WINDOWLESS_PRESENT_DISABLED
    //
    // MessageText:
    //
    // Windowless present is disabled (desktop windowing management subsystem is off).
    //
    ERROR_GRAPHICS_WINDOWLESS_PRESENT_DISABLED = 0xC026200EL,

    //
    // Video Memory Manager (VidMM) subsystem errors {0x2100..0x21ff}
    //
    //
    // MessageId: ERROR_GRAPHICS_NO_VIDEO_MEMORY
    //
    // MessageText:
    //
    // Not enough video memory available to complete the operation.
    //
    ERROR_GRAPHICS_NO_VIDEO_MEMORY = 0xC0262100L,

    //
    // MessageId: ERROR_GRAPHICS_CANT_LOCK_MEMORY
    //
    // MessageText:
    //
    // Couldn't probe and lock the underlying memory of an allocation.
    //
    ERROR_GRAPHICS_CANT_LOCK_MEMORY = 0xC0262101L,

    //
    // MessageId: ERROR_GRAPHICS_ALLOCATION_BUSY
    //
    // MessageText:
    //
    // The allocation is currently busy.
    //
    ERROR_GRAPHICS_ALLOCATION_BUSY = 0xC0262102L,

    //
    // MessageId: ERROR_GRAPHICS_TOO_MANY_REFERENCES
    //
    // MessageText:
    //
    // An object being referenced has reach the maximum reference count already and can't be reference further.
    //
    ERROR_GRAPHICS_TOO_MANY_REFERENCES = 0xC0262103L,

    //
    // MessageId: ERROR_GRAPHICS_TRY_AGAIN_LATER
    //
    // MessageText:
    //
    // A problem couldn't be solved due to some currently existing condition. The problem should be tried again later.
    //
    ERROR_GRAPHICS_TRY_AGAIN_LATER = 0xC0262104L,

    //
    // MessageId: ERROR_GRAPHICS_TRY_AGAIN_NOW
    //
    // MessageText:
    //
    // A problem couldn't be solved due to some currently existing condition. The problem should be tried again immediately.
    //
    ERROR_GRAPHICS_TRY_AGAIN_NOW = 0xC0262105L,

    //
    // MessageId: ERROR_GRAPHICS_ALLOCATION_INVALID
    //
    // MessageText:
    //
    // The allocation is invalid.
    //
    ERROR_GRAPHICS_ALLOCATION_INVALID = 0xC0262106L,

    //
    // MessageId: ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE
    //
    // MessageText:
    //
    // No more unswizzling aperture are currently available.
    //
    ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE = 0xC0262107L,

    //
    // MessageId: ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED
    //
    // MessageText:
    //
    // The current allocation can't be unswizzled by an aperture.
    //
    ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED = 0xC0262108L,

    //
    // MessageId: ERROR_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION
    //
    // MessageText:
    //
    // The request failed because a pinned allocation can't be evicted.
    //
    ERROR_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION = 0xC0262109L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_ALLOCATION_USAGE
    //
    // MessageText:
    //
    // The allocation can't be used from its current segment location for the specified operation.
    //
    ERROR_GRAPHICS_INVALID_ALLOCATION_USAGE = 0xC0262110L,

    //
    // MessageId: ERROR_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION
    //
    // MessageText:
    //
    // A locked allocation can't be used in the current command buffer.
    //
    ERROR_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION = 0xC0262111L,

    //
    // MessageId: ERROR_GRAPHICS_ALLOCATION_CLOSED
    //
    // MessageText:
    //
    // The allocation being referenced has been closed permanently.
    //
    ERROR_GRAPHICS_ALLOCATION_CLOSED = 0xC0262112L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_ALLOCATION_INSTANCE
    //
    // MessageText:
    //
    // An invalid allocation instance is being referenced.
    //
    ERROR_GRAPHICS_INVALID_ALLOCATION_INSTANCE = 0xC0262113L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_ALLOCATION_HANDLE
    //
    // MessageText:
    //
    // An invalid allocation handle is being referenced.
    //
    ERROR_GRAPHICS_INVALID_ALLOCATION_HANDLE = 0xC0262114L,

    //
    // MessageId: ERROR_GRAPHICS_WRONG_ALLOCATION_DEVICE
    //
    // MessageText:
    //
    // The allocation being referenced doesn't belong to the current device.
    //
    ERROR_GRAPHICS_WRONG_ALLOCATION_DEVICE = 0xC0262115L,

    //
    // MessageId: ERROR_GRAPHICS_ALLOCATION_CONTENT_LOST
    //
    // MessageText:
    //
    // The specified allocation lost its content.
    //
    ERROR_GRAPHICS_ALLOCATION_CONTENT_LOST = 0xC0262116L,

    //
    // Video GPU Scheduler (VidSch) subsystem errors {0x2200..0x22ff}
    //
    //
    // MessageId: ERROR_GRAPHICS_GPU_EXCEPTION_ON_DEVICE
    //
    // MessageText:
    //
    // GPU exception is detected on the given device. The device is not able to be scheduled.
    //
    ERROR_GRAPHICS_GPU_EXCEPTION_ON_DEVICE = 0xC0262200L,

    //
    // MessageId: ERROR_GRAPHICS_SKIP_ALLOCATION_PREPARATION
    //
    // MessageText:
    //
    // Skip preparation of allocations referenced by the DMA buffer.
    //
    ERROR_GRAPHICS_SKIP_ALLOCATION_PREPARATION = 0x40262201L,

    //
    // Video Present Network Management (VidPNMgr) subsystem errors {0x2300..0x23ff}
    //
    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY
    //
    // MessageText:
    //
    // Specified VidPN topology is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY = 0xC0262300L,

    //
    // MessageId: ERROR_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Specified VidPN topology is valid but is not supported by this model of the display adapter.
    //
    ERROR_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED = 0xC0262301L,

    //
    // MessageId: ERROR_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Specified VidPN topology is valid but is not supported by the display adapter at this time, due to current allocation of its resources.
    //
    ERROR_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED = 0xC0262302L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDPN
    //
    // MessageText:
    //
    // Specified VidPN handle is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDPN = 0xC0262303L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE
    //
    // MessageText:
    //
    // Specified video present source is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE = 0xC0262304L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET
    //
    // MessageText:
    //
    // Specified video present target is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET = 0xC0262305L,

    //
    // MessageId: ERROR_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Specified VidPN modality is not supported (e.g. at least two of the pinned modes are not cofunctional).
    //
    ERROR_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED = 0xC0262306L,

    //
    // MessageId: ERROR_GRAPHICS_MODE_NOT_PINNED
    //
    // MessageText:
    //
    // No mode is pinned on the specified VidPN source/target.
    //
    ERROR_GRAPHICS_MODE_NOT_PINNED = 0x00262307L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDPN_SOURCEMODESET
    //
    // MessageText:
    //
    // Specified VidPN source mode set is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDPN_SOURCEMODESET = 0xC0262308L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDPN_TARGETMODESET
    //
    // MessageText:
    //
    // Specified VidPN target mode set is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDPN_TARGETMODESET = 0xC0262309L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_FREQUENCY
    //
    // MessageText:
    //
    // Specified video signal frequency is invalid.
    //
    ERROR_GRAPHICS_INVALID_FREQUENCY = 0xC026230AL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_ACTIVE_REGION
    //
    // MessageText:
    //
    // Specified video signal active region is invalid.
    //
    ERROR_GRAPHICS_INVALID_ACTIVE_REGION = 0xC026230BL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_TOTAL_REGION
    //
    // MessageText:
    //
    // Specified video signal total region is invalid.
    //
    ERROR_GRAPHICS_INVALID_TOTAL_REGION = 0xC026230CL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE
    //
    // MessageText:
    //
    // Specified video present source mode is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE = 0xC0262310L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE
    //
    // MessageText:
    //
    // Specified video present target mode is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE = 0xC0262311L,

    //
    // MessageId: ERROR_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET
    //
    // MessageText:
    //
    // Pinned mode must remain in the set on VidPN's cofunctional modality enumeration.
    //
    ERROR_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET = 0xC0262312L,

    //
    // MessageId: ERROR_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY
    //
    // MessageText:
    //
    // Specified video present path is already in VidPN's topology.
    //
    ERROR_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY = 0xC0262313L,

    //
    // MessageId: ERROR_GRAPHICS_MODE_ALREADY_IN_MODESET
    //
    // MessageText:
    //
    // Specified mode is already in the mode set.
    //
    ERROR_GRAPHICS_MODE_ALREADY_IN_MODESET = 0xC0262314L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET
    //
    // MessageText:
    //
    // Specified video present source set is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET = 0xC0262315L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET
    //
    // MessageText:
    //
    // Specified video present target set is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET = 0xC0262316L,

    //
    // MessageId: ERROR_GRAPHICS_SOURCE_ALREADY_IN_SET
    //
    // MessageText:
    //
    // Specified video present source is already in the video present source set.
    //
    ERROR_GRAPHICS_SOURCE_ALREADY_IN_SET = 0xC0262317L,

    //
    // MessageId: ERROR_GRAPHICS_TARGET_ALREADY_IN_SET
    //
    // MessageText:
    //
    // Specified video present target is already in the video present target set.
    //
    ERROR_GRAPHICS_TARGET_ALREADY_IN_SET = 0xC0262318L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDPN_PRESENT_PATH
    //
    // MessageText:
    //
    // Specified VidPN present path is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDPN_PRESENT_PATH = 0xC0262319L,

    //
    // MessageId: ERROR_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY
    //
    // MessageText:
    //
    // Miniport has no recommendation for augmentation of the specified VidPN's topology.
    //
    ERROR_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY = 0xC026231AL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET
    //
    // MessageText:
    //
    // Specified monitor frequency range set is invalid.
    //
    ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET = 0xC026231BL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE
    //
    // MessageText:
    //
    // Specified monitor frequency range is invalid.
    //
    ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE = 0xC026231CL,

    //
    // MessageId: ERROR_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET
    //
    // MessageText:
    //
    // Specified frequency range is not in the specified monitor frequency range set.
    //
    ERROR_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET = 0xC026231DL,

    //
    // MessageId: ERROR_GRAPHICS_NO_PREFERRED_MODE
    //
    // MessageText:
    //
    // Specified mode set does not specify preference for one of its modes.
    //
    ERROR_GRAPHICS_NO_PREFERRED_MODE = 0x0026231EL,

    //
    // MessageId: ERROR_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET
    //
    // MessageText:
    //
    // Specified frequency range is already in the specified monitor frequency range set.
    //
    ERROR_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET = 0xC026231FL,

    //
    // MessageId: ERROR_GRAPHICS_STALE_MODESET
    //
    // MessageText:
    //
    // Specified mode set is stale. Please reacquire the new mode set.
    //
    ERROR_GRAPHICS_STALE_MODESET = 0xC0262320L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_MONITOR_SOURCEMODESET
    //
    // MessageText:
    //
    // Specified monitor source mode set is invalid.
    //
    ERROR_GRAPHICS_INVALID_MONITOR_SOURCEMODESET = 0xC0262321L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_MONITOR_SOURCE_MODE
    //
    // MessageText:
    //
    // Specified monitor source mode is invalid.
    //
    ERROR_GRAPHICS_INVALID_MONITOR_SOURCE_MODE = 0xC0262322L,

    //
    // MessageId: ERROR_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN
    //
    // MessageText:
    //
    // Miniport does not have any recommendation regarding the request to provide a functional VidPN given the current display adapter configuration.
    //
    ERROR_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN = 0xC0262323L,

    //
    // MessageId: ERROR_GRAPHICS_MODE_ID_MUST_BE_UNIQUE
    //
    // MessageText:
    //
    // ID of the specified mode is already used by another mode in the set.
    //
    ERROR_GRAPHICS_MODE_ID_MUST_BE_UNIQUE = 0xC0262324L,

    //
    // MessageId: ERROR_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION
    //
    // MessageText:
    //
    // System failed to determine a mode that is supported by both the display adapter and the monitor connected to it.
    //
    ERROR_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION = 0xC0262325L,

    //
    // MessageId: ERROR_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES
    //
    // MessageText:
    //
    // Number of video present targets must be greater than or equal to the number of video present sources.
    //
    ERROR_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES = 0xC0262326L,

    //
    // MessageId: ERROR_GRAPHICS_PATH_NOT_IN_TOPOLOGY
    //
    // MessageText:
    //
    // Specified present path is not in VidPN's topology.
    //
    ERROR_GRAPHICS_PATH_NOT_IN_TOPOLOGY = 0xC0262327L,

    //
    // MessageId: ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE
    //
    // MessageText:
    //
    // Display adapter must have at least one video present source.
    //
    ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE = 0xC0262328L,

    //
    // MessageId: ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET
    //
    // MessageText:
    //
    // Display adapter must have at least one video present target.
    //
    ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET = 0xC0262329L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_MONITORDESCRIPTORSET
    //
    // MessageText:
    //
    // Specified monitor descriptor set is invalid.
    //
    ERROR_GRAPHICS_INVALID_MONITORDESCRIPTORSET = 0xC026232AL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_MONITORDESCRIPTOR
    //
    // MessageText:
    //
    // Specified monitor descriptor is invalid.
    //
    ERROR_GRAPHICS_INVALID_MONITORDESCRIPTOR = 0xC026232BL,

    //
    // MessageId: ERROR_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET
    //
    // MessageText:
    //
    // Specified descriptor is not in the specified monitor descriptor set.
    //
    ERROR_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET = 0xC026232CL,

    //
    // MessageId: ERROR_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET
    //
    // MessageText:
    //
    // Specified descriptor is already in the specified monitor descriptor set.
    //
    ERROR_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET = 0xC026232DL,

    //
    // MessageId: ERROR_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE
    //
    // MessageText:
    //
    // ID of the specified monitor descriptor is already used by another descriptor in the set.
    //
    ERROR_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE = 0xC026232EL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE
    //
    // MessageText:
    //
    // Specified video present target subset type is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE = 0xC026232FL,

    //
    // MessageId: ERROR_GRAPHICS_RESOURCES_NOT_RELATED
    //
    // MessageText:
    //
    // Two or more of the specified resources are not related to each other, as defined by the interface semantics.
    //
    ERROR_GRAPHICS_RESOURCES_NOT_RELATED = 0xC0262330L,

    //
    // MessageId: ERROR_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE
    //
    // MessageText:
    //
    // ID of the specified video present source is already used by another source in the set.
    //
    ERROR_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE = 0xC0262331L,

    //
    // MessageId: ERROR_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE
    //
    // MessageText:
    //
    // ID of the specified video present target is already used by another target in the set.
    //
    ERROR_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE = 0xC0262332L,

    //
    // MessageId: ERROR_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET
    //
    // MessageText:
    //
    // Specified VidPN source cannot be used because there is no available VidPN target to connect it to.
    //
    ERROR_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET = 0xC0262333L,

    //
    // MessageId: ERROR_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER
    //
    // MessageText:
    //
    // Newly arrived monitor could not be associated with a display adapter.
    //
    ERROR_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER = 0xC0262334L,

    //
    // MessageId: ERROR_GRAPHICS_NO_VIDPNMGR
    //
    // MessageText:
    //
    // Display adapter in question does not have an associated VidPN manager.
    //
    ERROR_GRAPHICS_NO_VIDPNMGR = 0xC0262335L,

    //
    // MessageId: ERROR_GRAPHICS_NO_ACTIVE_VIDPN
    //
    // MessageText:
    //
    // VidPN manager of the display adapter in question does not have an active VidPN.
    //
    ERROR_GRAPHICS_NO_ACTIVE_VIDPN = 0xC0262336L,

    //
    // MessageId: ERROR_GRAPHICS_STALE_VIDPN_TOPOLOGY
    //
    // MessageText:
    //
    // Specified VidPN topology is stale. Please reacquire the new topology.
    //
    ERROR_GRAPHICS_STALE_VIDPN_TOPOLOGY = 0xC0262337L,

    //
    // MessageId: ERROR_GRAPHICS_MONITOR_NOT_CONNECTED
    //
    // MessageText:
    //
    // There is no monitor connected on the specified video present target.
    //
    ERROR_GRAPHICS_MONITOR_NOT_CONNECTED = 0xC0262338L,

    //
    // MessageId: ERROR_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY
    //
    // MessageText:
    //
    // Specified source is not part of the specified VidPN's topology.
    //
    ERROR_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY = 0xC0262339L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE
    //
    // MessageText:
    //
    // Specified primary surface size is invalid.
    //
    ERROR_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE = 0xC026233AL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VISIBLEREGION_SIZE
    //
    // MessageText:
    //
    // Specified visible region size is invalid.
    //
    ERROR_GRAPHICS_INVALID_VISIBLEREGION_SIZE = 0xC026233BL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_STRIDE
    //
    // MessageText:
    //
    // Specified stride is invalid.
    //
    ERROR_GRAPHICS_INVALID_STRIDE = 0xC026233CL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_PIXELFORMAT
    //
    // MessageText:
    //
    // Specified pixel format is invalid.
    //
    ERROR_GRAPHICS_INVALID_PIXELFORMAT = 0xC026233DL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_COLORBASIS
    //
    // MessageText:
    //
    // Specified color basis is invalid.
    //
    ERROR_GRAPHICS_INVALID_COLORBASIS = 0xC026233EL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_PIXELVALUEACCESSMODE
    //
    // MessageText:
    //
    // Specified pixel value access mode is invalid.
    //
    ERROR_GRAPHICS_INVALID_PIXELVALUEACCESSMODE = 0xC026233FL,

    //
    // MessageId: ERROR_GRAPHICS_TARGET_NOT_IN_TOPOLOGY
    //
    // MessageText:
    //
    // Specified target is not part of the specified VidPN's topology.
    //
    ERROR_GRAPHICS_TARGET_NOT_IN_TOPOLOGY = 0xC0262340L,

    //
    // MessageId: ERROR_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT
    //
    // MessageText:
    //
    // Failed to acquire display mode management interface.
    //
    ERROR_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT = 0xC0262341L,

    //
    // MessageId: ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE
    //
    // MessageText:
    //
    // Specified VidPN source is already owned by a DMM client and cannot be used until that client releases it.
    //
    ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE = 0xC0262342L,

    //
    // MessageId: ERROR_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN
    //
    // MessageText:
    //
    // Specified VidPN is active and cannot be accessed.
    //
    ERROR_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN = 0xC0262343L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL
    //
    // MessageText:
    //
    // Specified VidPN present path importance ordinal is invalid.
    //
    ERROR_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL = 0xC0262344L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION
    //
    // MessageText:
    //
    // Specified VidPN present path content geometry transformation is invalid.
    //
    ERROR_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION = 0xC0262345L,

    //
    // MessageId: ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Specified content geometry transformation is not supported on the respective VidPN present path.
    //
    ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED = 0xC0262346L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_GAMMA_RAMP
    //
    // MessageText:
    //
    // Specified gamma ramp is invalid.
    //
    ERROR_GRAPHICS_INVALID_GAMMA_RAMP = 0xC0262347L,

    //
    // MessageId: ERROR_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Specified gamma ramp is not supported on the respective VidPN present path.
    //
    ERROR_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED = 0xC0262348L,

    //
    // MessageId: ERROR_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Multi-sampling is not supported on the respective VidPN present path.
    //
    ERROR_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED = 0xC0262349L,

    //
    // MessageId: ERROR_GRAPHICS_MODE_NOT_IN_MODESET
    //
    // MessageText:
    //
    // Specified mode is not in the specified mode set.
    //
    ERROR_GRAPHICS_MODE_NOT_IN_MODESET = 0xC026234AL,

    //
    // MessageId: ERROR_GRAPHICS_DATASET_IS_EMPTY
    //
    // MessageText:
    //
    // Specified data set (e.g. mode set, frequency range set, descriptor set, topology, etc.) is empty.
    //
    ERROR_GRAPHICS_DATASET_IS_EMPTY = 0x0026234BL,

    //
    // MessageId: ERROR_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET
    //
    // MessageText:
    //
    // Specified data set (e.g. mode set, frequency range set, descriptor set, topology, etc.) does not contain any more elements.
    //
    ERROR_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET = 0x0026234CL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON
    //
    // MessageText:
    //
    // Specified VidPN topology recommendation reason is invalid.
    //
    ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON = 0xC026234DL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_PATH_CONTENT_TYPE
    //
    // MessageText:
    //
    // Specified VidPN present path content type is invalid.
    //
    ERROR_GRAPHICS_INVALID_PATH_CONTENT_TYPE = 0xC026234EL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_COPYPROTECTION_TYPE
    //
    // MessageText:
    //
    // Specified VidPN present path copy protection type is invalid.
    //
    ERROR_GRAPHICS_INVALID_COPYPROTECTION_TYPE = 0xC026234FL,

    //
    // MessageId: ERROR_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS
    //
    // MessageText:
    //
    // No more than one unassigned mode set can exist at any given time for a given VidPN source/target.
    //
    ERROR_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS = 0xC0262350L,

    //
    // MessageId: ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED
    //
    // MessageText:
    //
    // Specified content transformation is not pinned on the specified VidPN present path.
    //
    ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED = 0x00262351L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_SCANLINE_ORDERING
    //
    // MessageText:
    //
    // Specified scanline ordering type is invalid.
    //
    ERROR_GRAPHICS_INVALID_SCANLINE_ORDERING = 0xC0262352L,

    //
    // MessageId: ERROR_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED
    //
    // MessageText:
    //
    // Topology changes are not allowed for the specified VidPN.
    //
    ERROR_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED = 0xC0262353L,

    //
    // MessageId: ERROR_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS
    //
    // MessageText:
    //
    // All available importance ordinals are already used in specified topology.
    //
    ERROR_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS = 0xC0262354L,

    //
    // MessageId: ERROR_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT
    //
    // MessageText:
    //
    // Specified primary surface has a different private format attribute than the current primary surface
    //
    ERROR_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT = 0xC0262355L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM
    //
    // MessageText:
    //
    // Specified mode pruning algorithm is invalid
    //
    ERROR_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM = 0xC0262356L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN
    //
    // MessageText:
    //
    // Specified monitor capability origin is invalid.
    //
    ERROR_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN = 0xC0262357L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT
    //
    // MessageText:
    //
    // Specified monitor frequency range constraint is invalid.
    //
    ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT = 0xC0262358L,

    //
    // MessageId: ERROR_GRAPHICS_MAX_NUM_PATHS_REACHED
    //
    // MessageText:
    //
    // Maximum supported number of present paths has been reached.
    //
    ERROR_GRAPHICS_MAX_NUM_PATHS_REACHED = 0xC0262359L,

    //
    // MessageId: ERROR_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION
    //
    // MessageText:
    //
    // Miniport requested that augmentation be cancelled for the specified source of the specified VidPN's topology.
    //
    ERROR_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION = 0xC026235AL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_CLIENT_TYPE
    //
    // MessageText:
    //
    // Specified client type was not recognized.
    //
    ERROR_GRAPHICS_INVALID_CLIENT_TYPE = 0xC026235BL,

    //
    // MessageId: ERROR_GRAPHICS_CLIENTVIDPN_NOT_SET
    //
    // MessageText:
    //
    // Client VidPN is not set on this adapter (e.g. no user mode initiated mode changes took place on this adapter yet).
    //
    ERROR_GRAPHICS_CLIENTVIDPN_NOT_SET = 0xC026235CL,

    //
    // Port specific status codes {0x2400..0x24ff}
    //
    //
    // MessageId: ERROR_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED
    //
    // MessageText:
    //
    // Specified display adapter child device already has an external device connected to it.
    //
    ERROR_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED = 0xC0262400L,

    //
    // MessageId: ERROR_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Specified display adapter child device does not support descriptor exposure.
    //
    ERROR_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED = 0xC0262401L,

    //
    // MessageId: ERROR_GRAPHICS_UNKNOWN_CHILD_STATUS
    //
    // MessageText:
    //
    // Child device presence was not reliably detected.
    //
    ERROR_GRAPHICS_UNKNOWN_CHILD_STATUS = 0x4026242FL,

    //
    // MessageId: ERROR_GRAPHICS_NOT_A_LINKED_ADAPTER
    //
    // MessageText:
    //
    // The display adapter is not linked to any other adapters.
    //
    ERROR_GRAPHICS_NOT_A_LINKED_ADAPTER = 0xC0262430L,

    //
    // MessageId: ERROR_GRAPHICS_LEADLINK_NOT_ENUMERATED
    //
    // MessageText:
    //
    // Lead adapter in a linked configuration was not enumerated yet.
    //
    ERROR_GRAPHICS_LEADLINK_NOT_ENUMERATED = 0xC0262431L,

    //
    // MessageId: ERROR_GRAPHICS_CHAINLINKS_NOT_ENUMERATED
    //
    // MessageText:
    //
    // Some chain adapters in a linked configuration were not enumerated yet.
    //
    ERROR_GRAPHICS_CHAINLINKS_NOT_ENUMERATED = 0xC0262432L,

    //
    // MessageId: ERROR_GRAPHICS_ADAPTER_CHAIN_NOT_READY
    //
    // MessageText:
    //
    // The chain of linked adapters is not ready to start because of an unknown failure.
    //
    ERROR_GRAPHICS_ADAPTER_CHAIN_NOT_READY = 0xC0262433L,

    //
    // MessageId: ERROR_GRAPHICS_CHAINLINKS_NOT_STARTED
    //
    // MessageText:
    //
    // An attempt was made to start a lead link display adapter when the chain links were not started yet.
    //
    ERROR_GRAPHICS_CHAINLINKS_NOT_STARTED = 0xC0262434L,

    //
    // MessageId: ERROR_GRAPHICS_CHAINLINKS_NOT_POWERED_ON
    //
    // MessageText:
    //
    // An attempt was made to power up a lead link display adapter when the chain links were powered down.
    //
    ERROR_GRAPHICS_CHAINLINKS_NOT_POWERED_ON = 0xC0262435L,

    //
    // MessageId: ERROR_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE
    //
    // MessageText:
    //
    // The adapter link was found to be in an inconsistent state. Not all adapters are in an expected PNP/Power state.
    //
    ERROR_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE = 0xC0262436L,

    //
    // MessageId: ERROR_GRAPHICS_LEADLINK_START_DEFERRED
    //
    // MessageText:
    //
    // Starting the leadlink adapter has been deferred temporarily.
    //
    ERROR_GRAPHICS_LEADLINK_START_DEFERRED = 0x40262437L,

    //
    // MessageId: ERROR_GRAPHICS_NOT_POST_DEVICE_DRIVER
    //
    // MessageText:
    //
    // The driver trying to start is not the same as the driver for the POSTed display adapter.
    //
    ERROR_GRAPHICS_NOT_POST_DEVICE_DRIVER = 0xC0262438L,

    //
    // MessageId: ERROR_GRAPHICS_POLLING_TOO_FREQUENTLY
    //
    // MessageText:
    //
    // The display adapter is being polled for children too frequently at the same polling level.
    //
    ERROR_GRAPHICS_POLLING_TOO_FREQUENTLY = 0x40262439L,

    //
    // MessageId: ERROR_GRAPHICS_START_DEFERRED
    //
    // MessageText:
    //
    // Starting the adapter has been deferred temporarily.
    //
    ERROR_GRAPHICS_START_DEFERRED = 0x4026243AL,

    //
    // MessageId: ERROR_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED
    //
    // MessageText:
    //
    // An operation is being attempted that requires the display adapter to be in a quiescent state.
    //
    ERROR_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED = 0xC026243BL,

    //
    // OPM, UAB and PVP specific error codes {0x2500..0x257f}
    //
    //
    // MessageId: ERROR_GRAPHICS_OPM_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The driver does not support OPM.
    //
    ERROR_GRAPHICS_OPM_NOT_SUPPORTED = 0xC0262500L,

    //
    // MessageId: ERROR_GRAPHICS_COPP_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The driver does not support COPP.
    //
    ERROR_GRAPHICS_COPP_NOT_SUPPORTED = 0xC0262501L,

    //
    // MessageId: ERROR_GRAPHICS_UAB_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The driver does not support UAB.
    //
    ERROR_GRAPHICS_UAB_NOT_SUPPORTED = 0xC0262502L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS
    //
    // MessageText:
    //
    // The specified encrypted parameters are invalid.
    //
    ERROR_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS = 0xC0262503L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_NO_VIDEO_OUTPUTS_EXIST
    //
    // MessageText:
    //
    // The GDI display device passed to this function does not have any active video outputs.
    //
    ERROR_GRAPHICS_OPM_NO_VIDEO_OUTPUTS_EXIST = 0xC0262505L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal error caused this operation to fail.
    //
    ERROR_GRAPHICS_OPM_INTERNAL_ERROR = 0xC026250BL,

    //
    // MessageId: ERROR_GRAPHICS_OPM_INVALID_HANDLE
    //
    // MessageText:
    //
    // The function failed because the caller passed in an invalid OPM user mode handle.
    //
    ERROR_GRAPHICS_OPM_INVALID_HANDLE = 0xC026250CL,

    //
    // MessageId: ERROR_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH
    //
    // MessageText:
    //
    // A certificate could not be returned because the certificate buffer passed to the function was too small.
    //
    ERROR_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH = 0xC026250EL,

    //
    // MessageId: ERROR_GRAPHICS_OPM_SPANNING_MODE_ENABLED
    //
    // MessageText:
    //
    // A video output could not be created because the frame buffer is in spanning mode.
    //
    ERROR_GRAPHICS_OPM_SPANNING_MODE_ENABLED = 0xC026250FL,

    //
    // MessageId: ERROR_GRAPHICS_OPM_THEATER_MODE_ENABLED
    //
    // MessageText:
    //
    // A video output could not be created because the frame buffer is in theater mode.
    //
    ERROR_GRAPHICS_OPM_THEATER_MODE_ENABLED = 0xC0262510L,

    //
    // MessageId: ERROR_GRAPHICS_PVP_HFS_FAILED
    //
    // MessageText:
    //
    // The function failed because the display adapter's Hardware Functionality Scan failed to validate the graphics hardware.
    //
    ERROR_GRAPHICS_PVP_HFS_FAILED = 0xC0262511L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_INVALID_SRM
    //
    // MessageText:
    //
    // The HDCP System Renewability Message passed to this function did not comply with section 5 of the HDCP 1.1 specification.
    //
    ERROR_GRAPHICS_OPM_INVALID_SRM = 0xC0262512L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP
    //
    // MessageText:
    //
    // The video output cannot enable the High-bandwidth Digital Content Protection (HDCP) System because it does not support HDCP.
    //
    ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP = 0xC0262513L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP
    //
    // MessageText:
    //
    // The video output cannot enable Analogue Copy Protection (ACP) because it does not support ACP.
    //
    ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP = 0xC0262514L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA
    //
    // MessageText:
    //
    // The video output cannot enable the Content Generation Management System Analogue (CGMS-A) protection technology because it does not support CGMS-A.
    //
    ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA = 0xC0262515L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_HDCP_SRM_NEVER_SET
    //
    // MessageText:
    //
    // The IOPMVideoOutput::GetInformation method cannot return the version of the SRM being used because the application never successfully passed an SRM to the video output.
    //
    ERROR_GRAPHICS_OPM_HDCP_SRM_NEVER_SET = 0xC0262516L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_RESOLUTION_TOO_HIGH
    //
    // MessageText:
    //
    // The IOPMVideoOutput::Configure method cannot enable the specified output protection technology because the output's screen resolution is too high.
    //
    ERROR_GRAPHICS_OPM_RESOLUTION_TOO_HIGH = 0xC0262517L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE
    //
    // MessageText:
    //
    // The IOPMVideoOutput::Configure method cannot enable HDCP because the display adapter's HDCP hardware is already being used by other physical outputs.
    //
    ERROR_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE = 0xC0262518L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_NO_LONGER_EXISTS
    //
    // MessageText:
    //
    // The operating system asynchronously destroyed this OPM video output because the operating system's state changed. This error typically occurs because the monitor PDO associated with this video output was removed, the monitor PDO associated with this video output was stopped, the video output's session became a non-console session or the video output's desktop became an inactive desktop.
    //
    ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_NO_LONGER_EXISTS = 0xC026251AL,

    //
    // MessageId: ERROR_GRAPHICS_OPM_SESSION_TYPE_CHANGE_IN_PROGRESS
    //
    // MessageText:
    //
    // The method failed because the session is changing its type. No IOPMVideoOutput methods can be called when a session is changing its type. There are currently three types of sessions: console, disconnected and remote.
    //
    ERROR_GRAPHICS_OPM_SESSION_TYPE_CHANGE_IN_PROGRESS = 0xC026251BL,

    //
    // MessageId: ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS
    //
    // MessageText:
    //
    // Either the IOPMVideoOutput::COPPCompatibleGetInformation, IOPMVideoOutput::GetInformation, or IOPMVideoOutput::Configure method failed. This error is returned when the caller tries to use a COPP specific command while the video output has OPM semantics only.
    //
    ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS = 0xC026251CL,

    //
    // MessageId: ERROR_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST
    //
    // MessageText:
    //
    // The IOPMVideoOutput::GetInformation and IOPMVideoOutput::COPPCompatibleGetInformation methods return this error if the passed in sequence number is not the expected sequence number or the passed in OMAC value is invalid.
    //
    ERROR_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST = 0xC026251DL,

    //
    // MessageId: ERROR_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR
    //
    // MessageText:
    //
    // The method failed because an unexpected error occurred inside of a display driver.
    //
    ERROR_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR = 0xC026251EL,

    //
    // MessageId: ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS
    //
    // MessageText:
    //
    // Either the IOPMVideoOutput::COPPCompatibleGetInformation, IOPMVideoOutput::GetInformation, or IOPMVideoOutput::Configure method failed. This error is returned when the caller tries to use an OPM specific command while the video output has COPP semantics only.
    //
    ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS = 0xC026251FL,

    //
    // MessageId: ERROR_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The IOPMVideoOutput::COPPCompatibleGetInformation or IOPMVideoOutput::Configure method failed because the display driver does not support the OPM_GET_ACP_AND_CGMSA_SIGNALING and OPM_SET_ACP_AND_CGMSA_SIGNALING GUIDs.
    //
    ERROR_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED = 0xC0262520L,

    //
    // MessageId: ERROR_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST
    //
    // MessageText:
    //
    // The IOPMVideoOutput::Configure function returns this error code if the passed in sequence number is not the expected sequence number or the passed in OMAC value is invalid.
    //
    ERROR_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST = 0xC0262521L,

    //
    // Monitor Configuration API error codes {0x2580..0x25DF}
    //
    //
    // MessageId: ERROR_GRAPHICS_I2C_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The monitor connected to the specified video output does not have an I2C bus.
    //
    ERROR_GRAPHICS_I2C_NOT_SUPPORTED = 0xC0262580L,

    //
    // MessageId: ERROR_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST
    //
    // MessageText:
    //
    // No device on the I2C bus has the specified address.
    //
    ERROR_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST = 0xC0262581L,

    //
    // MessageId: ERROR_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA
    //
    // MessageText:
    //
    // An error occurred while transmitting data to the device on the I2C bus.
    //
    ERROR_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA = 0xC0262582L,

    //
    // MessageId: ERROR_GRAPHICS_I2C_ERROR_RECEIVING_DATA
    //
    // MessageText:
    //
    // An error occurred while receiving data from the device on the I2C bus.
    //
    ERROR_GRAPHICS_I2C_ERROR_RECEIVING_DATA = 0xC0262583L,

    //
    // MessageId: ERROR_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The monitor does not support the specified VCP code.
    //
    ERROR_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED = 0xC0262584L,

    //
    // MessageId: ERROR_GRAPHICS_DDCCI_INVALID_DATA
    //
    // MessageText:
    //
    // The data received from the monitor is invalid.
    //
    ERROR_GRAPHICS_DDCCI_INVALID_DATA = 0xC0262585L,

    //
    // MessageId: ERROR_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE
    //
    // MessageText:
    //
    // The function failed because a monitor returned an invalid Timing Status byte when the operating system used the DDC/CI Get Timing Report & Timing Message command to get a timing report from a monitor.
    //
    ERROR_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE = 0xC0262586L,

    //
    // MessageId: ERROR_GRAPHICS_MCA_INVALID_CAPABILITIES_STRING
    //
    // MessageText:
    //
    // The monitor returned a DDC/CI capabilities string which did not comply with the ACCESS.bus 3.0, DDC/CI 1.1, or MCCS 2 Revision 1 specification.
    //
    ERROR_GRAPHICS_MCA_INVALID_CAPABILITIES_STRING = 0xC0262587L,

    //
    // MessageId: ERROR_GRAPHICS_MCA_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal Monitor Configuration API error occurred.
    //
    ERROR_GRAPHICS_MCA_INTERNAL_ERROR = 0xC0262588L,

    //
    // MessageId: ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND
    //
    // MessageText:
    //
    // An operation failed because a DDC/CI message had an invalid value in its command field.
    //
    ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND = 0xC0262589L,

    //
    // MessageId: ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH
    //
    // MessageText:
    //
    // An error occurred because the field length of a DDC/CI message contained an invalid value.
    //
    ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH = 0xC026258AL,

    //
    // MessageId: ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM
    //
    // MessageText:
    //
    // An error occurred because the checksum field in a DDC/CI message did not match the message's computed checksum value. This error implies that the data was corrupted while it was being transmitted from a monitor to a computer.
    //
    ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM = 0xC026258BL,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE
    //
    // MessageText:
    //
    // This function failed because an invalid monitor handle was passed to it.
    //
    ERROR_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE = 0xC026258CL,

    //
    // MessageId: ERROR_GRAPHICS_MONITOR_NO_LONGER_EXISTS
    //
    // MessageText:
    //
    // The operating system asynchronously destroyed the monitor which corresponds to this handle because the operating system's state changed. This error typically occurs because the monitor PDO associated with this handle was removed, the monitor PDO associated with this handle was stopped, or a display mode change occurred. A display mode change occurs when windows sends a WM_DISPLAYCHANGE windows message to applications.
    //
    ERROR_GRAPHICS_MONITOR_NO_LONGER_EXISTS = 0xC026258DL,

    //
    // MessageId: ERROR_GRAPHICS_DDCCI_CURRENT_CURRENT_VALUE_GREATER_THAN_MAXIMUM_VALUE
    //
    // MessageText:
    //
    // A continuous VCP code's current value is greater than its maximum value. This error code indicates that a monitor returned an invalid value.
    //
    ERROR_GRAPHICS_DDCCI_CURRENT_CURRENT_VALUE_GREATER_THAN_MAXIMUM_VALUE = 0xC02625D8L,

    //
    // MessageId: ERROR_GRAPHICS_MCA_INVALID_VCP_VERSION
    //
    // MessageText:
    //
    // The monitor's VCP Version (0xDF) VCP code returned an invalid version value.
    //
    ERROR_GRAPHICS_MCA_INVALID_VCP_VERSION = 0xC02625D9L,

    //
    // MessageId: ERROR_GRAPHICS_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION
    //
    // MessageText:
    //
    // The monitor does not comply with the MCCS specification it claims to support.
    //
    ERROR_GRAPHICS_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION = 0xC02625DAL,

    //
    // MessageId: ERROR_GRAPHICS_MCA_MCCS_VERSION_MISMATCH
    //
    // MessageText:
    //
    // The MCCS version in a monitor's mccs_ver capability does not match the MCCS version the monitor reports when the VCP Version (0xDF) VCP code is used.
    //
    ERROR_GRAPHICS_MCA_MCCS_VERSION_MISMATCH = 0xC02625DBL,

    //
    // MessageId: ERROR_GRAPHICS_MCA_UNSUPPORTED_MCCS_VERSION
    //
    // MessageText:
    //
    // The Monitor Configuration API only works with monitors which support the MCCS 1.0 specification, MCCS 2.0 specification or the MCCS 2.0 Revision 1 specification.
    //
    ERROR_GRAPHICS_MCA_UNSUPPORTED_MCCS_VERSION = 0xC02625DCL,

    //
    // MessageId: ERROR_GRAPHICS_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED
    //
    // MessageText:
    //
    // The monitor returned an invalid monitor technology type. CRT, Plasma and LCD (TFT) are examples of monitor technology types. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.
    //
    ERROR_GRAPHICS_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED = 0xC02625DEL,

    //
    // MessageId: ERROR_GRAPHICS_MCA_UNSUPPORTED_COLOR_TEMPERATURE
    //
    // MessageText:
    //
    // SetMonitorColorTemperature()'s caller passed a color temperature to it which the current monitor did not support. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.
    //
    ERROR_GRAPHICS_MCA_UNSUPPORTED_COLOR_TEMPERATURE = 0xC02625DFL,

    //
    // OPM, UAB, PVP and DDC/CI shared error codes {0x25E0..0x25ff}
    //
    //
    // MessageId: ERROR_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED
    //
    // MessageText:
    //
    // This function can only be used if a program is running in the local console session. It cannot be used if the program is running on a remote desktop session or on a terminal server session.
    //
    ERROR_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED = 0xC02625E0L,

    //
    // MessageId: ERROR_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME
    //
    // MessageText:
    //
    // This function cannot find an actual GDI display device which corresponds to the specified GDI display device name.
    //
    ERROR_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME = 0xC02625E1L,

    //
    // MessageId: ERROR_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP
    //
    // MessageText:
    //
    // The function failed because the specified GDI display device was not attached to the Windows desktop.
    //
    ERROR_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP = 0xC02625E2L,

    //
    // MessageId: ERROR_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED
    //
    // MessageText:
    //
    // This function does not support GDI mirroring display devices because GDI mirroring display devices do not have any physical monitors associated with them.
    //
    ERROR_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED = 0xC02625E3L,

    //
    // MessageId: ERROR_GRAPHICS_INVALID_POINTER
    //
    // MessageText:
    //
    // The function failed because an invalid pointer parameter was passed to it. A pointer parameter is invalid if it is NULL, points to an invalid address, points to a kernel mode address, or is not correctly aligned.
    //
    ERROR_GRAPHICS_INVALID_POINTER = 0xC02625E4L,

    //
    // MessageId: ERROR_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE
    //
    // MessageText:
    //
    // The function failed because the specified GDI device did not have any monitors associated with it.
    //
    ERROR_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE = 0xC02625E5L,

    //
    // MessageId: ERROR_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL
    //
    // MessageText:
    //
    // An array passed to the function cannot hold all of the data that the function must copy into the array.
    //
    ERROR_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL = 0xC02625E6L,

    //
    // MessageId: ERROR_GRAPHICS_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal error caused an operation to fail.
    //
    ERROR_GRAPHICS_INTERNAL_ERROR = 0xC02625E7L,

    //
    // MessageId: ERROR_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS
    //
    // MessageText:
    //
    // The function failed because the current session is changing its type. This function cannot be called when the current session is changing its type. There are currently three types of sessions: console, disconnected and remote.
    //
    ERROR_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS = 0xC02605E8L,

    // FACILITY_NAP

    //
    // MessageId: NAP_E_INVALID_PACKET
    //
    // MessageText:
    //
    // The NAP SoH packet is invalid.
    //
    NAP_E_INVALID_PACKET = 0x80270001L,

    //
    // MessageId: NAP_E_MISSING_SOH
    //
    // MessageText:
    //
    // An SoH was missing from the NAP packet.
    //
    NAP_E_MISSING_SOH = 0x80270002L,

    //
    // MessageId: NAP_E_CONFLICTING_ID
    //
    // MessageText:
    //
    // The entity ID conflicts with an already registered id.
    //
    NAP_E_CONFLICTING_ID = 0x80270003L,

    //
    // MessageId: NAP_E_NO_CACHED_SOH
    //
    // MessageText:
    //
    // No cached SoH is present.
    //
    NAP_E_NO_CACHED_SOH = 0x80270004L,

    //
    // MessageId: NAP_E_STILL_BOUND
    //
    // MessageText:
    //
    // The entity is still bound to the NAP system.
    //
    NAP_E_STILL_BOUND = 0x80270005L,

    //
    // MessageId: NAP_E_NOT_REGISTERED
    //
    // MessageText:
    //
    // The entity is not registered with the NAP system.
    //
    NAP_E_NOT_REGISTERED = 0x80270006L,

    //
    // MessageId: NAP_E_NOT_INITIALIZED
    //
    // MessageText:
    //
    // The entity is not initialized with the NAP system.
    //
    NAP_E_NOT_INITIALIZED = 0x80270007L,

    //
    // MessageId: NAP_E_MISMATCHED_ID
    //
    // MessageText:
    //
    // The correlation id in the SoH-Request and SoH-Response do not match up.
    //
    NAP_E_MISMATCHED_ID = 0x80270008L,

    //
    // MessageId: NAP_E_NOT_PENDING
    //
    // MessageText:
    //
    // Completion was indicated on a request that is not currently pending.
    //
    NAP_E_NOT_PENDING = 0x80270009L,

    //
    // MessageId: NAP_E_ID_NOT_FOUND
    //
    // MessageText:
    //
    // The NAP component's id was not found.
    //
    NAP_E_ID_NOT_FOUND = 0x8027000AL,

    //
    // MessageId: NAP_E_MAXSIZE_TOO_SMALL
    //
    // MessageText:
    //
    // The maximum size of the connection is too small for an SoH packet.
    //
    NAP_E_MAXSIZE_TOO_SMALL = 0x8027000BL,

    //
    // MessageId: NAP_E_SERVICE_NOT_RUNNING
    //
    // MessageText:
    //
    // The NapAgent service is not running.
    //
    NAP_E_SERVICE_NOT_RUNNING = 0x8027000CL,

    //
    // MessageId: NAP_S_CERT_ALREADY_PRESENT
    //
    // MessageText:
    //
    // A certificate is already present in the cert store.
    //
    NAP_S_CERT_ALREADY_PRESENT = 0x0027000DL,

    //
    // MessageId: NAP_E_ENTITY_DISABLED
    //
    // MessageText:
    //
    // The entity is disabled with the NapAgent service.
    //
    NAP_E_ENTITY_DISABLED = 0x8027000EL,

    //
    // MessageId: NAP_E_NETSH_GROUPPOLICY_ERROR
    //
    // MessageText:
    //
    // Group Policy is not configured.
    //
    NAP_E_NETSH_GROUPPOLICY_ERROR = 0x8027000FL,

    //
    // MessageId: NAP_E_TOO_MANY_CALLS
    //
    // MessageText:
    //
    // Too many simultaneous calls.
    //
    NAP_E_TOO_MANY_CALLS = 0x80270010L,

    //
    // MessageId: NAP_E_SHV_CONFIG_EXISTED
    //
    // MessageText:
    //
    // SHV configuration already existed.
    //
    NAP_E_SHV_CONFIG_EXISTED = 0x80270011L,

    //
    // MessageId: NAP_E_SHV_CONFIG_NOT_FOUND
    //
    // MessageText:
    //
    // SHV configuration is not found.
    //
    NAP_E_SHV_CONFIG_NOT_FOUND = 0x80270012L,

    //
    // MessageId: NAP_E_SHV_TIMEOUT
    //
    // MessageText:
    //
    // SHV timed out on the request.
    //
    NAP_E_SHV_TIMEOUT = 0x80270013L,

    //
    // ===============================
    // TPM Services and TPM Software Error Messages
    // ===============================
    //
    // The TPM services and TPM software facilities are used by the various
    // TPM software components. There are two facilities because the services
    // errors are within the TCG-defined error space and the software errors
    // are not.
    //
    // The following are the subranges within the TPM Services facility.
    // The TPM hardware errors are defined in the document
    // TPM Main Specification 1.2 Part 2 TPM Structures.
    // The TBS errors are slotted into the TCG error namespace at the TBS layer.
    //
    // 0x0000 - 0x08ff     TPM hardware errors
    // 0x4000 - 0x40ff     TPM Base Services errors (tbssvc.dll)
    //
    // The following are the subranges within the TPM Software facility. The TBS
    // has two classes of errors - those that can be returned (the public errors,
    // defined in the TBS spec), which are in the TPM services facility,  and
    // those that are internal or implementation specific, which are here in the
    // TPM software facility.
    //
    // 0x0000 - 0x00ff     TPM device driver errors (tpm.sys)
    // 0x0100 - 0x01ff     TPM API errors (tpmapi.lib)
    // 0x0200 - 0x02ff     TBS internal errors (tbssvc.dll)
    // 0x0300 - 0x03ff     TPM Physical Presence errors
    //
    //
    // TPM hardware error codes {0x0000..0x08ff}
    // This space is further subdivided into hardware errors, vendor-specific
    // errors, and non-fatal errors.
    //
    //
    // TPM hardware errors {0x0000..0x003ff}
    //
    //
    // MessageId: TPM_E_ERROR_MASK
    //
    // MessageText:
    //
    // This is an error mask to convert TPM hardware errors to win errors.
    //
    TPM_E_ERROR_MASK = 0x80280000L,

    //
    // MessageId: TPM_E_AUTHFAIL
    //
    // MessageText:
    //
    // Authentication failed.
    //
    TPM_E_AUTHFAIL = 0x80280001L,

    //
    // MessageId: TPM_E_BADINDEX
    //
    // MessageText:
    //
    // The index to a PCR, DIR or other register is incorrect.
    //
    TPM_E_BADINDEX = 0x80280002L,

    //
    // MessageId: TPM_E_BAD_PARAMETER
    //
    // MessageText:
    //
    // One or more parameter is bad.
    //
    TPM_E_BAD_PARAMETER = 0x80280003L,

    //
    // MessageId: TPM_E_AUDITFAILURE
    //
    // MessageText:
    //
    // An operation completed successfully but the auditing of that operation failed.
    //
    TPM_E_AUDITFAILURE = 0x80280004L,

    //
    // MessageId: TPM_E_CLEAR_DISABLED
    //
    // MessageText:
    //
    // The clear disable flag is set and all clear operations now require physical access.
    //
    TPM_E_CLEAR_DISABLED = 0x80280005L,

    //
    // MessageId: TPM_E_DEACTIVATED
    //
    // MessageText:
    //
    // Activate the Trusted Platform Module (TPM).
    //
    TPM_E_DEACTIVATED = 0x80280006L,

    //
    // MessageId: TPM_E_DISABLED
    //
    // MessageText:
    //
    // Enable the Trusted Platform Module (TPM).
    //
    TPM_E_DISABLED = 0x80280007L,

    //
    // MessageId: TPM_E_DISABLED_CMD
    //
    // MessageText:
    //
    // The target command has been disabled.
    //
    TPM_E_DISABLED_CMD = 0x80280008L,

    //
    // MessageId: TPM_E_FAIL
    //
    // MessageText:
    //
    // The operation failed.
    //
    TPM_E_FAIL = 0x80280009L,

    //
    // MessageId: TPM_E_BAD_ORDINAL
    //
    // MessageText:
    //
    // The ordinal was unknown or inconsistent.
    //
    TPM_E_BAD_ORDINAL = 0x8028000AL,

    //
    // MessageId: TPM_E_INSTALL_DISABLED
    //
    // MessageText:
    //
    // The ability to install an owner is disabled.
    //
    TPM_E_INSTALL_DISABLED = 0x8028000BL,

    //
    // MessageId: TPM_E_INVALID_KEYHANDLE
    //
    // MessageText:
    //
    // The key handle cannot be interpreted.
    //
    TPM_E_INVALID_KEYHANDLE = 0x8028000CL,

    //
    // MessageId: TPM_E_KEYNOTFOUND
    //
    // MessageText:
    //
    // The key handle points to an invalid key.
    //
    TPM_E_KEYNOTFOUND = 0x8028000DL,

    //
    // MessageId: TPM_E_INAPPROPRIATE_ENC
    //
    // MessageText:
    //
    // Unacceptable encryption scheme.
    //
    TPM_E_INAPPROPRIATE_ENC = 0x8028000EL,

    //
    // MessageId: TPM_E_MIGRATEFAIL
    //
    // MessageText:
    //
    // Migration authorization failed.
    //
    TPM_E_MIGRATEFAIL = 0x8028000FL,

    //
    // MessageId: TPM_E_INVALID_PCR_INFO
    //
    // MessageText:
    //
    // PCR information could not be interpreted.
    //
    TPM_E_INVALID_PCR_INFO = 0x80280010L,

    //
    // MessageId: TPM_E_NOSPACE
    //
    // MessageText:
    //
    // No room to load key.
    //
    TPM_E_NOSPACE = 0x80280011L,

    //
    // MessageId: TPM_E_NOSRK
    //
    // MessageText:
    //
    // There is no Storage Root Key (SRK) set.
    //
    TPM_E_NOSRK = 0x80280012L,

    //
    // MessageId: TPM_E_NOTSEALED_BLOB
    //
    // MessageText:
    //
    // An encrypted blob is invalid or was not created by this TPM.
    //
    TPM_E_NOTSEALED_BLOB = 0x80280013L,

    //
    // MessageId: TPM_E_OWNER_SET
    //
    // MessageText:
    //
    // The Trusted Platform Module (TPM) already has an owner.
    //
    TPM_E_OWNER_SET = 0x80280014L,

    //
    // MessageId: TPM_E_RESOURCES
    //
    // MessageText:
    //
    // The TPM has insufficient internal resources to perform the requested action.
    //
    TPM_E_RESOURCES = 0x80280015L,

    //
    // MessageId: TPM_E_SHORTRANDOM
    //
    // MessageText:
    //
    // A random string was too short.
    //
    TPM_E_SHORTRANDOM = 0x80280016L,

    //
    // MessageId: TPM_E_SIZE
    //
    // MessageText:
    //
    // The TPM does not have the space to perform the operation.
    //
    TPM_E_SIZE = 0x80280017L,

    //
    // MessageId: TPM_E_WRONGPCRVAL
    //
    // MessageText:
    //
    // The named PCR value does not match the current PCR value.
    //
    TPM_E_WRONGPCRVAL = 0x80280018L,

    //
    // MessageId: TPM_E_BAD_PARAM_SIZE
    //
    // MessageText:
    //
    // The paramSize argument to the command has the incorrect value .
    //
    TPM_E_BAD_PARAM_SIZE = 0x80280019L,

    //
    // MessageId: TPM_E_SHA_THREAD
    //
    // MessageText:
    //
    // There is no existing SHA-1 thread.
    //
    TPM_E_SHA_THREAD = 0x8028001AL,

    //
    // MessageId: TPM_E_SHA_ERROR
    //
    // MessageText:
    //
    // The calculation is unable to proceed because the existing SHA-1 thread has already encountered an error.
    //
    TPM_E_SHA_ERROR = 0x8028001BL,

    //
    // MessageId: TPM_E_FAILEDSELFTEST
    //
    // MessageText:
    //
    // The TPM hardware device reported a failure during its internal self test. Try restarting the computer to resolve the problem. If the problem continues, check for the latest BIOS or firmware update for your TPM hardware. Consult the computer manufacturer's documentation for instructions.
    //
    TPM_E_FAILEDSELFTEST = 0x8028001CL,

    //
    // MessageId: TPM_E_AUTH2FAIL
    //
    // MessageText:
    //
    // The authorization for the second key in a 2 key function failed authorization.
    //
    TPM_E_AUTH2FAIL = 0x8028001DL,

    //
    // MessageId: TPM_E_BADTAG
    //
    // MessageText:
    //
    // The tag value sent to for a command is invalid.
    //
    TPM_E_BADTAG = 0x8028001EL,

    //
    // MessageId: TPM_E_IOERROR
    //
    // MessageText:
    //
    // An IO error occurred transmitting information to the TPM.
    //
    TPM_E_IOERROR = 0x8028001FL,

    //
    // MessageId: TPM_E_ENCRYPT_ERROR
    //
    // MessageText:
    //
    // The encryption process had a problem.
    //
    TPM_E_ENCRYPT_ERROR = 0x80280020L,

    //
    // MessageId: TPM_E_DECRYPT_ERROR
    //
    // MessageText:
    //
    // The decryption process did not complete.
    //
    TPM_E_DECRYPT_ERROR = 0x80280021L,

    //
    // MessageId: TPM_E_INVALID_AUTHHANDLE
    //
    // MessageText:
    //
    // An invalid handle was used.
    //
    TPM_E_INVALID_AUTHHANDLE = 0x80280022L,

    //
    // MessageId: TPM_E_NO_ENDORSEMENT
    //
    // MessageText:
    //
    // The TPM does not have an Endorsement Key (EK) installed.
    //
    TPM_E_NO_ENDORSEMENT = 0x80280023L,

    //
    // MessageId: TPM_E_INVALID_KEYUSAGE
    //
    // MessageText:
    //
    // The usage of a key is not allowed.
    //
    TPM_E_INVALID_KEYUSAGE = 0x80280024L,

    //
    // MessageId: TPM_E_WRONG_ENTITYTYPE
    //
    // MessageText:
    //
    // The submitted entity type is not allowed.
    //
    TPM_E_WRONG_ENTITYTYPE = 0x80280025L,

    //
    // MessageId: TPM_E_INVALID_POSTINIT
    //
    // MessageText:
    //
    // The command was received in the wrong sequence relative to TPM_Init and a subsequent TPM_Startup.
    //
    TPM_E_INVALID_POSTINIT = 0x80280026L,

    //
    // MessageId: TPM_E_INAPPROPRIATE_SIG
    //
    // MessageText:
    //
    // Signed data cannot include additional DER information.
    //
    TPM_E_INAPPROPRIATE_SIG = 0x80280027L,

    //
    // MessageId: TPM_E_BAD_KEY_PROPERTY
    //
    // MessageText:
    //
    // The key properties in TPM_KEY_PARMs are not supported by this TPM.
    //
    TPM_E_BAD_KEY_PROPERTY = 0x80280028L,

    //
    // MessageId: TPM_E_BAD_MIGRATION
    //
    // MessageText:
    //
    // The migration properties of this key are incorrect.
    //
    TPM_E_BAD_MIGRATION = 0x80280029L,

    //
    // MessageId: TPM_E_BAD_SCHEME
    //
    // MessageText:
    //
    // The signature or encryption scheme for this key is incorrect or not permitted in this situation.
    //
    TPM_E_BAD_SCHEME = 0x8028002AL,

    //
    // MessageId: TPM_E_BAD_DATASIZE
    //
    // MessageText:
    //
    // The size of the data (or blob) parameter is bad or inconsistent with the referenced key.
    //
    TPM_E_BAD_DATASIZE = 0x8028002BL,

    //
    // MessageId: TPM_E_BAD_MODE
    //
    // MessageText:
    //
    // A mode parameter is bad, such as capArea or subCapArea for TPM_GetCapability, phsicalPresence parameter for TPM_PhysicalPresence, or migrationType for TPM_CreateMigrationBlob.
    //
    TPM_E_BAD_MODE = 0x8028002CL,

    //
    // MessageId: TPM_E_BAD_PRESENCE
    //
    // MessageText:
    //
    // Either the physicalPresence or physicalPresenceLock bits have the wrong value.
    //
    TPM_E_BAD_PRESENCE = 0x8028002DL,

    //
    // MessageId: TPM_E_BAD_VERSION
    //
    // MessageText:
    //
    // The TPM cannot perform this version of the capability.
    //
    TPM_E_BAD_VERSION = 0x8028002EL,

    //
    // MessageId: TPM_E_NO_WRAP_TRANSPORT
    //
    // MessageText:
    //
    // The TPM does not allow for wrapped transport sessions.
    //
    TPM_E_NO_WRAP_TRANSPORT = 0x8028002FL,

    //
    // MessageId: TPM_E_AUDITFAIL_UNSUCCESSFUL
    //
    // MessageText:
    //
    // TPM audit construction failed and the underlying command was returning a failure code also.
    //
    TPM_E_AUDITFAIL_UNSUCCESSFUL = 0x80280030L,

    //
    // MessageId: TPM_E_AUDITFAIL_SUCCESSFUL
    //
    // MessageText:
    //
    // TPM audit construction failed and the underlying command was returning success.
    //
    TPM_E_AUDITFAIL_SUCCESSFUL = 0x80280031L,

    //
    // MessageId: TPM_E_NOTRESETABLE
    //
    // MessageText:
    //
    // Attempt to reset a PCR register that does not have the resettable attribute.
    //
    TPM_E_NOTRESETABLE = 0x80280032L,

    //
    // MessageId: TPM_E_NOTLOCAL
    //
    // MessageText:
    //
    // Attempt to reset a PCR register that requires locality and locality modifier not part of command transport.
    //
    TPM_E_NOTLOCAL = 0x80280033L,

    //
    // MessageId: TPM_E_BAD_TYPE
    //
    // MessageText:
    //
    // Make identity blob not properly typed.
    //
    TPM_E_BAD_TYPE = 0x80280034L,

    //
    // MessageId: TPM_E_INVALID_RESOURCE
    //
    // MessageText:
    //
    // When saving context identified resource type does not match actual resource.
    //
    TPM_E_INVALID_RESOURCE = 0x80280035L,

    //
    // MessageId: TPM_E_NOTFIPS
    //
    // MessageText:
    //
    // The TPM is attempting to execute a command only available when in FIPS mode.
    //
    TPM_E_NOTFIPS = 0x80280036L,

    //
    // MessageId: TPM_E_INVALID_FAMILY
    //
    // MessageText:
    //
    // The command is attempting to use an invalid family ID.
    //
    TPM_E_INVALID_FAMILY = 0x80280037L,

    //
    // MessageId: TPM_E_NO_NV_PERMISSION
    //
    // MessageText:
    //
    // The permission to manipulate the NV storage is not available.
    //
    TPM_E_NO_NV_PERMISSION = 0x80280038L,

    //
    // MessageId: TPM_E_REQUIRES_SIGN
    //
    // MessageText:
    //
    // The operation requires a signed command.
    //
    TPM_E_REQUIRES_SIGN = 0x80280039L,

    //
    // MessageId: TPM_E_KEY_NOTSUPPORTED
    //
    // MessageText:
    //
    // Wrong operation to load an NV key.
    //
    TPM_E_KEY_NOTSUPPORTED = 0x8028003AL,

    //
    // MessageId: TPM_E_AUTH_CONFLICT
    //
    // MessageText:
    //
    // NV_LoadKey blob requires both owner and blob authorization.
    //
    TPM_E_AUTH_CONFLICT = 0x8028003BL,

    //
    // MessageId: TPM_E_AREA_LOCKED
    //
    // MessageText:
    //
    // The NV area is locked and not writtable.
    //
    TPM_E_AREA_LOCKED = 0x8028003CL,

    //
    // MessageId: TPM_E_BAD_LOCALITY
    //
    // MessageText:
    //
    // The locality is incorrect for the attempted operation.
    //
    TPM_E_BAD_LOCALITY = 0x8028003DL,

    //
    // MessageId: TPM_E_READ_ONLY
    //
    // MessageText:
    //
    // The NV area is read only and can't be written to.
    //
    TPM_E_READ_ONLY = 0x8028003EL,

    //
    // MessageId: TPM_E_PER_NOWRITE
    //
    // MessageText:
    //
    // There is no protection on the write to the NV area.
    //
    TPM_E_PER_NOWRITE = 0x8028003FL,

    //
    // MessageId: TPM_E_FAMILYCOUNT
    //
    // MessageText:
    //
    // The family count value does not match.
    //
    TPM_E_FAMILYCOUNT = 0x80280040L,

    //
    // MessageId: TPM_E_WRITE_LOCKED
    //
    // MessageText:
    //
    // The NV area has already been written to.
    //
    TPM_E_WRITE_LOCKED = 0x80280041L,

    //
    // MessageId: TPM_E_BAD_ATTRIBUTES
    //
    // MessageText:
    //
    // The NV area attributes conflict.
    //
    TPM_E_BAD_ATTRIBUTES = 0x80280042L,

    //
    // MessageId: TPM_E_INVALID_STRUCTURE
    //
    // MessageText:
    //
    // The structure tag and version are invalid or inconsistent.
    //
    TPM_E_INVALID_STRUCTURE = 0x80280043L,

    //
    // MessageId: TPM_E_KEY_OWNER_CONTROL
    //
    // MessageText:
    //
    // The key is under control of the TPM Owner and can only be evicted by the TPM Owner.
    //
    TPM_E_KEY_OWNER_CONTROL = 0x80280044L,

    //
    // MessageId: TPM_E_BAD_COUNTER
    //
    // MessageText:
    //
    // The counter handle is incorrect.
    //
    TPM_E_BAD_COUNTER = 0x80280045L,

    //
    // MessageId: TPM_E_NOT_FULLWRITE
    //
    // MessageText:
    //
    // The write is not a complete write of the area.
    //
    TPM_E_NOT_FULLWRITE = 0x80280046L,

    //
    // MessageId: TPM_E_CONTEXT_GAP
    //
    // MessageText:
    //
    // The gap between saved context counts is too large.
    //
    TPM_E_CONTEXT_GAP = 0x80280047L,

    //
    // MessageId: TPM_E_MAXNVWRITES
    //
    // MessageText:
    //
    // The maximum number of NV writes without an owner has been exceeded.
    //
    TPM_E_MAXNVWRITES = 0x80280048L,

    //
    // MessageId: TPM_E_NOOPERATOR
    //
    // MessageText:
    //
    // No operator AuthData value is set.
    //
    TPM_E_NOOPERATOR = 0x80280049L,

    //
    // MessageId: TPM_E_RESOURCEMISSING
    //
    // MessageText:
    //
    // The resource pointed to by context is not loaded.
    //
    TPM_E_RESOURCEMISSING = 0x8028004AL,

    //
    // MessageId: TPM_E_DELEGATE_LOCK
    //
    // MessageText:
    //
    // The delegate administration is locked.
    //
    TPM_E_DELEGATE_LOCK = 0x8028004BL,

    //
    // MessageId: TPM_E_DELEGATE_FAMILY
    //
    // MessageText:
    //
    // Attempt to manage a family other then the delegated family.
    //
    TPM_E_DELEGATE_FAMILY = 0x8028004CL,

    //
    // MessageId: TPM_E_DELEGATE_ADMIN
    //
    // MessageText:
    //
    // Delegation table management not enabled.
    //
    TPM_E_DELEGATE_ADMIN = 0x8028004DL,

    //
    // MessageId: TPM_E_TRANSPORT_NOTEXCLUSIVE
    //
    // MessageText:
    //
    // There was a command executed outside of an exclusive transport session.
    //
    TPM_E_TRANSPORT_NOTEXCLUSIVE = 0x8028004EL,

    //
    // MessageId: TPM_E_OWNER_CONTROL
    //
    // MessageText:
    //
    // Attempt to context save a owner evict controlled key.
    //
    TPM_E_OWNER_CONTROL = 0x8028004FL,

    //
    // MessageId: TPM_E_DAA_RESOURCES
    //
    // MessageText:
    //
    // The DAA command has no resources availble to execute the command.
    //
    TPM_E_DAA_RESOURCES = 0x80280050L,

    //
    // MessageId: TPM_E_DAA_INPUT_DATA0
    //
    // MessageText:
    //
    // The consistency check on DAA parameter inputData0 has failed.
    //
    TPM_E_DAA_INPUT_DATA0 = 0x80280051L,

    //
    // MessageId: TPM_E_DAA_INPUT_DATA1
    //
    // MessageText:
    //
    // The consistency check on DAA parameter inputData1 has failed.
    //
    TPM_E_DAA_INPUT_DATA1 = 0x80280052L,

    //
    // MessageId: TPM_E_DAA_ISSUER_SETTINGS
    //
    // MessageText:
    //
    // The consistency check on DAA_issuerSettings has failed.
    //
    TPM_E_DAA_ISSUER_SETTINGS = 0x80280053L,

    //
    // MessageId: TPM_E_DAA_TPM_SETTINGS
    //
    // MessageText:
    //
    // The consistency check on DAA_tpmSpecific has failed.
    //
    TPM_E_DAA_TPM_SETTINGS = 0x80280054L,

    //
    // MessageId: TPM_E_DAA_STAGE
    //
    // MessageText:
    //
    // The atomic process indicated by the submitted DAA command is not the expected process.
    //
    TPM_E_DAA_STAGE = 0x80280055L,

    //
    // MessageId: TPM_E_DAA_ISSUER_VALIDITY
    //
    // MessageText:
    //
    // The issuer's validity check has detected an inconsistency.
    //
    TPM_E_DAA_ISSUER_VALIDITY = 0x80280056L,

    //
    // MessageId: TPM_E_DAA_WRONG_W
    //
    // MessageText:
    //
    // The consistency check on w has failed.
    //
    TPM_E_DAA_WRONG_W = 0x80280057L,

    //
    // MessageId: TPM_E_BAD_HANDLE
    //
    // MessageText:
    //
    // The handle is incorrect.
    //
    TPM_E_BAD_HANDLE = 0x80280058L,

    //
    // MessageId: TPM_E_BAD_DELEGATE
    //
    // MessageText:
    //
    // Delegation is not correct.
    //
    TPM_E_BAD_DELEGATE = 0x80280059L,

    //
    // MessageId: TPM_E_BADCONTEXT
    //
    // MessageText:
    //
    // The context blob is invalid.
    //
    TPM_E_BADCONTEXT = 0x8028005AL,

    //
    // MessageId: TPM_E_TOOMANYCONTEXTS
    //
    // MessageText:
    //
    // Too many contexts held by the TPM.
    //
    TPM_E_TOOMANYCONTEXTS = 0x8028005BL,

    //
    // MessageId: TPM_E_MA_TICKET_SIGNATURE
    //
    // MessageText:
    //
    // Migration authority signature validation failure.
    //
    TPM_E_MA_TICKET_SIGNATURE = 0x8028005CL,

    //
    // MessageId: TPM_E_MA_DESTINATION
    //
    // MessageText:
    //
    // Migration destination not authenticated.
    //
    TPM_E_MA_DESTINATION = 0x8028005DL,

    //
    // MessageId: TPM_E_MA_SOURCE
    //
    // MessageText:
    //
    // Migration source incorrect.
    //
    TPM_E_MA_SOURCE = 0x8028005EL,

    //
    // MessageId: TPM_E_MA_AUTHORITY
    //
    // MessageText:
    //
    // Incorrect migration authority.
    //
    TPM_E_MA_AUTHORITY = 0x8028005FL,

    //
    // MessageId: TPM_E_PERMANENTEK
    //
    // MessageText:
    //
    // Attempt to revoke the EK and the EK is not revocable.
    //
    TPM_E_PERMANENTEK = 0x80280061L,

    //
    // MessageId: TPM_E_BAD_SIGNATURE
    //
    // MessageText:
    //
    // Bad signature of CMK ticket.
    //
    TPM_E_BAD_SIGNATURE = 0x80280062L,

    //
    // MessageId: TPM_E_NOCONTEXTSPACE
    //
    // MessageText:
    //
    // There is no room in the context list for additional contexts.
    //
    TPM_E_NOCONTEXTSPACE = 0x80280063L,

    //
    // TPM vendor specific hardware errors {0x0400..0x04ff}
    //
    //
    // MessageId: TPM_E_COMMAND_BLOCKED
    //
    // MessageText:
    //
    // The command was blocked.
    //
    TPM_E_COMMAND_BLOCKED = 0x80280400L,

    //
    // MessageId: TPM_E_INVALID_HANDLE
    //
    // MessageText:
    //
    // The specified handle was not found.
    //
    TPM_E_INVALID_HANDLE = 0x80280401L,

    //
    // MessageId: TPM_E_DUPLICATE_VHANDLE
    //
    // MessageText:
    //
    // The TPM returned a duplicate handle and the command needs to be resubmitted.
    //
    TPM_E_DUPLICATE_VHANDLE = 0x80280402L,

    //
    // MessageId: TPM_E_EMBEDDED_COMMAND_BLOCKED
    //
    // MessageText:
    //
    // The command within the transport was blocked.
    //
    TPM_E_EMBEDDED_COMMAND_BLOCKED = 0x80280403L,

    //
    // MessageId: TPM_E_EMBEDDED_COMMAND_UNSUPPORTED
    //
    // MessageText:
    //
    // The command within the transport is not supported.
    //
    TPM_E_EMBEDDED_COMMAND_UNSUPPORTED = 0x80280404L,

    //
    // TPM non-fatal hardware errors {0x0800..0x08ff}
    //
    //
    // MessageId: TPM_E_RETRY
    //
    // MessageText:
    //
    // The TPM is too busy to respond to the command immediately, but the command could be resubmitted at a later time.
    //
    TPM_E_RETRY = 0x80280800L,

    //
    // MessageId: TPM_E_NEEDS_SELFTEST
    //
    // MessageText:
    //
    // SelfTestFull has not been run.
    //
    TPM_E_NEEDS_SELFTEST = 0x80280801L,

    //
    // MessageId: TPM_E_DOING_SELFTEST
    //
    // MessageText:
    //
    // The TPM is currently executing a full selftest.
    //
    TPM_E_DOING_SELFTEST = 0x80280802L,

    //
    // MessageId: TPM_E_DEFEND_LOCK_RUNNING
    //
    // MessageText:
    //
    // The TPM is defending against dictionary attacks and is in a time-out period.
    //
    TPM_E_DEFEND_LOCK_RUNNING = 0x80280803L,

    //
    // TPM Base Services error codes {0x4000..0x40ff}
    //
    //
    // MessageId: TBS_E_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal error has occurred within the Trusted Platform Module support program.
    //
    TBS_E_INTERNAL_ERROR = 0x80284001L,

    //
    // MessageId: TBS_E_BAD_PARAMETER
    //
    // MessageText:
    //
    // One or more input parameters is bad.
    //
    TBS_E_BAD_PARAMETER = 0x80284002L,

    //
    // MessageId: TBS_E_INVALID_OUTPUT_POINTER
    //
    // MessageText:
    //
    // A specified output pointer is bad.
    //
    TBS_E_INVALID_OUTPUT_POINTER = 0x80284003L,

    //
    // MessageId: TBS_E_INVALID_CONTEXT
    //
    // MessageText:
    //
    // The specified context handle does not refer to a valid context.
    //
    TBS_E_INVALID_CONTEXT = 0x80284004L,

    //
    // MessageId: TBS_E_INSUFFICIENT_BUFFER
    //
    // MessageText:
    //
    // A specified output buffer is too small.
    //
    TBS_E_INSUFFICIENT_BUFFER = 0x80284005L,

    //
    // MessageId: TBS_E_IOERROR
    //
    // MessageText:
    //
    // An error occurred while communicating with the TPM.
    //
    TBS_E_IOERROR = 0x80284006L,

    //
    // MessageId: TBS_E_INVALID_CONTEXT_PARAM
    //
    // MessageText:
    //
    // One or more context parameters is invalid.
    //
    TBS_E_INVALID_CONTEXT_PARAM = 0x80284007L,

    //
    // MessageId: TBS_E_SERVICE_NOT_RUNNING
    //
    // MessageText:
    //
    // The TBS service is not running and could not be started.
    //
    TBS_E_SERVICE_NOT_RUNNING = 0x80284008L,

    //
    // MessageId: TBS_E_TOO_MANY_TBS_CONTEXTS
    //
    // MessageText:
    //
    // A new context could not be created because there are too many open contexts.
    //
    TBS_E_TOO_MANY_TBS_CONTEXTS = 0x80284009L,

    //
    // MessageId: TBS_E_TOO_MANY_RESOURCES
    //
    // MessageText:
    //
    // A new virtual resource could not be created because there are too many open virtual resources.
    //
    TBS_E_TOO_MANY_RESOURCES = 0x8028400AL,

    //
    // MessageId: TBS_E_SERVICE_START_PENDING
    //
    // MessageText:
    //
    // The TBS service has been started but is not yet running.
    //
    TBS_E_SERVICE_START_PENDING = 0x8028400BL,

    //
    // MessageId: TBS_E_PPI_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The physical presence interface is not supported.
    //
    TBS_E_PPI_NOT_SUPPORTED = 0x8028400CL,

    //
    // MessageId: TBS_E_COMMAND_CANCELED
    //
    // MessageText:
    //
    // The command was canceled.
    //
    TBS_E_COMMAND_CANCELED = 0x8028400DL,

    //
    // MessageId: TBS_E_BUFFER_TOO_LARGE
    //
    // MessageText:
    //
    // The input or output buffer is too large.
    //
    TBS_E_BUFFER_TOO_LARGE = 0x8028400EL,

    //
    // MessageId: TBS_E_TPM_NOT_FOUND
    //
    // MessageText:
    //
    // A compatible Trusted Platform Module (TPM) Security Device cannot be found on this computer.
    //
    TBS_E_TPM_NOT_FOUND = 0x8028400FL,

    //
    // MessageId: TBS_E_SERVICE_DISABLED
    //
    // MessageText:
    //
    // The TBS service has been disabled.
    //
    TBS_E_SERVICE_DISABLED = 0x80284010L,

    //
    // MessageId: TBS_E_NO_EVENT_LOG
    //
    // MessageText:
    //
    // No TCG event log is available.
    //
    TBS_E_NO_EVENT_LOG = 0x80284011L,

    //
    // MessageId: TBS_E_ACCESS_DENIED
    //
    // MessageText:
    //
    // The caller does not have the appropriate rights to perform the requested operation.
    //
    TBS_E_ACCESS_DENIED = 0x80284012L,

    //
    // MessageId: TBS_E_PROVISIONING_NOT_ALLOWED
    //
    // MessageText:
    //
    // The TPM provisioning action is not allowed by the specified flags.  For provisioning to be successful, one of several actions may be required.  The TPM management console (tpm.msc) action to make the TPM Ready may help.  For further information, see the documentation for the Win32_Tpm WMI method 'Provision'.  (The actions that may be required include importing the TPM Owner Authorization value into the system, calling the Win32_Tpm WMI method for provisioning the TPM and specifying TRUE for either 'ForceClear_Allowed' or 'PhysicalPresencePrompts_Allowed' (as indicated by the value returned in the Additional Information), or enabling the TPM in the system BIOS.)
    //
    TBS_E_PROVISIONING_NOT_ALLOWED = 0x80284013L,

    //
    // MessageId: TBS_E_PPI_FUNCTION_UNSUPPORTED
    //
    // MessageText:
    //
    // The Physical Presence Interface of this firmware does not support the requested method.
    //
    TBS_E_PPI_FUNCTION_UNSUPPORTED = 0x80284014L,

    //
    // MessageId: TBS_E_OWNERAUTH_NOT_FOUND
    //
    // MessageText:
    //
    // The requested TPM OwnerAuth value was not found.
    //
    TBS_E_OWNERAUTH_NOT_FOUND = 0x80284015L,

    //
    // MessageId: TBS_E_PROVISIONING_INCOMPLETE
    //
    // MessageText:
    //
    // The TPM provisioning did not complete.  For more information on completing the provisioning, call the Win32_Tpm WMI method for provisioning the TPM ('Provision') and check the returned Information.
    //
    TBS_E_PROVISIONING_INCOMPLETE = 0x80284016L,

    //
    // TPM API error codes {0x0100..0x01ff}
    //
    //
    // MessageId: TPMAPI_E_INVALID_STATE
    //
    // MessageText:
    //
    // The command buffer is not in the correct state.
    //
    TPMAPI_E_INVALID_STATE = 0x80290100L,

    //
    // MessageId: TPMAPI_E_NOT_ENOUGH_DATA
    //
    // MessageText:
    //
    // The command buffer does not contain enough data to satisfy the request.
    //
    TPMAPI_E_NOT_ENOUGH_DATA = 0x80290101L,

    //
    // MessageId: TPMAPI_E_TOO_MUCH_DATA
    //
    // MessageText:
    //
    // The command buffer cannot contain any more data.
    //
    TPMAPI_E_TOO_MUCH_DATA = 0x80290102L,

    //
    // MessageId: TPMAPI_E_INVALID_OUTPUT_POINTER
    //
    // MessageText:
    //
    // One or more output parameters was NULL or invalid.
    //
    TPMAPI_E_INVALID_OUTPUT_POINTER = 0x80290103L,

    //
    // MessageId: TPMAPI_E_INVALID_PARAMETER
    //
    // MessageText:
    //
    // One or more input parameters is invalid.
    //
    TPMAPI_E_INVALID_PARAMETER = 0x80290104L,

    //
    // MessageId: TPMAPI_E_OUT_OF_MEMORY
    //
    // MessageText:
    //
    // Not enough memory was available to satisfy the request.
    //
    TPMAPI_E_OUT_OF_MEMORY = 0x80290105L,

    //
    // MessageId: TPMAPI_E_BUFFER_TOO_SMALL
    //
    // MessageText:
    //
    // The specified buffer was too small.
    //
    TPMAPI_E_BUFFER_TOO_SMALL = 0x80290106L,

    //
    // MessageId: TPMAPI_E_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal error was detected.
    //
    TPMAPI_E_INTERNAL_ERROR = 0x80290107L,

    //
    // MessageId: TPMAPI_E_ACCESS_DENIED
    //
    // MessageText:
    //
    // The caller does not have the appropriate rights to perform the requested operation.
    //
    TPMAPI_E_ACCESS_DENIED = 0x80290108L,

    //
    // MessageId: TPMAPI_E_AUTHORIZATION_FAILED
    //
    // MessageText:
    //
    // The specified authorization information was invalid.
    //
    TPMAPI_E_AUTHORIZATION_FAILED = 0x80290109L,

    //
    // MessageId: TPMAPI_E_INVALID_CONTEXT_HANDLE
    //
    // MessageText:
    //
    // The specified context handle was not valid.
    //
    TPMAPI_E_INVALID_CONTEXT_HANDLE = 0x8029010AL,

    //
    // MessageId: TPMAPI_E_TBS_COMMUNICATION_ERROR
    //
    // MessageText:
    //
    // An error occurred while communicating with the TBS.
    //
    TPMAPI_E_TBS_COMMUNICATION_ERROR = 0x8029010BL,

    //
    // MessageId: TPMAPI_E_TPM_COMMAND_ERROR
    //
    // MessageText:
    //
    // The TPM returned an unexpected result.
    //
    TPMAPI_E_TPM_COMMAND_ERROR = 0x8029010CL,

    //
    // MessageId: TPMAPI_E_MESSAGE_TOO_LARGE
    //
    // MessageText:
    //
    // The message was too large for the encoding scheme.
    //
    TPMAPI_E_MESSAGE_TOO_LARGE = 0x8029010DL,

    //
    // MessageId: TPMAPI_E_INVALID_ENCODING
    //
    // MessageText:
    //
    // The encoding in the blob was not recognized.
    //
    TPMAPI_E_INVALID_ENCODING = 0x8029010EL,

    //
    // MessageId: TPMAPI_E_INVALID_KEY_SIZE
    //
    // MessageText:
    //
    // The key size is not valid.
    //
    TPMAPI_E_INVALID_KEY_SIZE = 0x8029010FL,

    //
    // MessageId: TPMAPI_E_ENCRYPTION_FAILED
    //
    // MessageText:
    //
    // The encryption operation failed.
    //
    TPMAPI_E_ENCRYPTION_FAILED = 0x80290110L,

    //
    // MessageId: TPMAPI_E_INVALID_KEY_PARAMS
    //
    // MessageText:
    //
    // The key parameters structure was not valid
    //
    TPMAPI_E_INVALID_KEY_PARAMS = 0x80290111L,

    //
    // MessageId: TPMAPI_E_INVALID_MIGRATION_AUTHORIZATION_BLOB
    //
    // MessageText:
    //
    // The requested supplied data does not appear to be a valid migration authorization blob.
    //
    TPMAPI_E_INVALID_MIGRATION_AUTHORIZATION_BLOB = 0x80290112L,

    //
    // MessageId: TPMAPI_E_INVALID_PCR_INDEX
    //
    // MessageText:
    //
    // The specified PCR index was invalid
    //
    TPMAPI_E_INVALID_PCR_INDEX = 0x80290113L,

    //
    // MessageId: TPMAPI_E_INVALID_DELEGATE_BLOB
    //
    // MessageText:
    //
    // The data given does not appear to be a valid delegate blob.
    //
    TPMAPI_E_INVALID_DELEGATE_BLOB = 0x80290114L,

    //
    // MessageId: TPMAPI_E_INVALID_CONTEXT_PARAMS
    //
    // MessageText:
    //
    // One or more of the specified context parameters was not valid.
    //
    TPMAPI_E_INVALID_CONTEXT_PARAMS = 0x80290115L,

    //
    // MessageId: TPMAPI_E_INVALID_KEY_BLOB
    //
    // MessageText:
    //
    // The data given does not appear to be a valid key blob
    //
    TPMAPI_E_INVALID_KEY_BLOB = 0x80290116L,

    //
    // MessageId: TPMAPI_E_INVALID_PCR_DATA
    //
    // MessageText:
    //
    // The specified PCR data was invalid.
    //
    TPMAPI_E_INVALID_PCR_DATA = 0x80290117L,

    //
    // MessageId: TPMAPI_E_INVALID_OWNER_AUTH
    //
    // MessageText:
    //
    // The format of the owner auth data was invalid.
    //
    TPMAPI_E_INVALID_OWNER_AUTH = 0x80290118L,

    //
    // MessageId: TPMAPI_E_FIPS_RNG_CHECK_FAILED
    //
    // MessageText:
    //
    // The random number generated did not pass FIPS RNG check.
    //
    TPMAPI_E_FIPS_RNG_CHECK_FAILED = 0x80290119L,

    //
    // MessageId: TPMAPI_E_EMPTY_TCG_LOG
    //
    // MessageText:
    //
    // The TCG Event Log does not contain any data.
    //
    TPMAPI_E_EMPTY_TCG_LOG = 0x8029011AL,

    //
    // MessageId: TPMAPI_E_INVALID_TCG_LOG_ENTRY
    //
    // MessageText:
    //
    // An entry in the TCG Event Log was invalid.
    //
    TPMAPI_E_INVALID_TCG_LOG_ENTRY = 0x8029011BL,

    //
    // MessageId: TPMAPI_E_TCG_SEPARATOR_ABSENT
    //
    // MessageText:
    //
    // A TCG Separator was not found.
    //
    TPMAPI_E_TCG_SEPARATOR_ABSENT = 0x8029011CL,

    //
    // MessageId: TPMAPI_E_TCG_INVALID_DIGEST_ENTRY
    //
    // MessageText:
    //
    // A digest value in a TCG Log entry did not match hashed data.
    //
    TPMAPI_E_TCG_INVALID_DIGEST_ENTRY = 0x8029011DL,

    //
    // MessageId: TPMAPI_E_POLICY_DENIES_OPERATION
    //
    // MessageText:
    //
    // The requested operation was blocked by current TPM policy. Please contact your system administrator for assistance.
    //
    TPMAPI_E_POLICY_DENIES_OPERATION = 0x8029011EL,

    //
    // TBS implementation error codes {0x0200..0x02ff}
    //
    //
    // MessageId: TBSIMP_E_BUFFER_TOO_SMALL
    //
    // MessageText:
    //
    // The specified buffer was too small.
    //
    TBSIMP_E_BUFFER_TOO_SMALL = 0x80290200L,

    //
    // MessageId: TBSIMP_E_CLEANUP_FAILED
    //
    // MessageText:
    //
    // The context could not be cleaned up.
    //
    TBSIMP_E_CLEANUP_FAILED = 0x80290201L,

    //
    // MessageId: TBSIMP_E_INVALID_CONTEXT_HANDLE
    //
    // MessageText:
    //
    // The specified context handle is invalid.
    //
    TBSIMP_E_INVALID_CONTEXT_HANDLE = 0x80290202L,

    //
    // MessageId: TBSIMP_E_INVALID_CONTEXT_PARAM
    //
    // MessageText:
    //
    // An invalid context parameter was specified.
    //
    TBSIMP_E_INVALID_CONTEXT_PARAM = 0x80290203L,

    //
    // MessageId: TBSIMP_E_TPM_ERROR
    //
    // MessageText:
    //
    // An error occurred while communicating with the TPM
    //
    TBSIMP_E_TPM_ERROR = 0x80290204L,

    //
    // MessageId: TBSIMP_E_HASH_BAD_KEY
    //
    // MessageText:
    //
    // No entry with the specified key was found.
    //
    TBSIMP_E_HASH_BAD_KEY = 0x80290205L,

    //
    // MessageId: TBSIMP_E_DUPLICATE_VHANDLE
    //
    // MessageText:
    //
    // The specified virtual handle matches a virtual handle already in use.
    //
    TBSIMP_E_DUPLICATE_VHANDLE = 0x80290206L,

    //
    // MessageId: TBSIMP_E_INVALID_OUTPUT_POINTER
    //
    // MessageText:
    //
    // The pointer to the returned handle location was NULL or invalid
    //
    TBSIMP_E_INVALID_OUTPUT_POINTER = 0x80290207L,

    //
    // MessageId: TBSIMP_E_INVALID_PARAMETER
    //
    // MessageText:
    //
    // One or more parameters is invalid
    //
    TBSIMP_E_INVALID_PARAMETER = 0x80290208L,

    //
    // MessageId: TBSIMP_E_RPC_INIT_FAILED
    //
    // MessageText:
    //
    // The RPC subsystem could not be initialized.
    //
    TBSIMP_E_RPC_INIT_FAILED = 0x80290209L,

    //
    // MessageId: TBSIMP_E_SCHEDULER_NOT_RUNNING
    //
    // MessageText:
    //
    // The TBS scheduler is not running.
    //
    TBSIMP_E_SCHEDULER_NOT_RUNNING = 0x8029020AL,

    //
    // MessageId: TBSIMP_E_COMMAND_CANCELED
    //
    // MessageText:
    //
    // The command was canceled.
    //
    TBSIMP_E_COMMAND_CANCELED = 0x8029020BL,

    //
    // MessageId: TBSIMP_E_OUT_OF_MEMORY
    //
    // MessageText:
    //
    // There was not enough memory to fulfill the request
    //
    TBSIMP_E_OUT_OF_MEMORY = 0x8029020CL,

    //
    // MessageId: TBSIMP_E_LIST_NO_MORE_ITEMS
    //
    // MessageText:
    //
    // The specified list is empty, or the iteration has reached the end of the list.
    //
    TBSIMP_E_LIST_NO_MORE_ITEMS = 0x8029020DL,

    //
    // MessageId: TBSIMP_E_LIST_NOT_FOUND
    //
    // MessageText:
    //
    // The specified item was not found in the list.
    //
    TBSIMP_E_LIST_NOT_FOUND = 0x8029020EL,

    //
    // MessageId: TBSIMP_E_NOT_ENOUGH_SPACE
    //
    // MessageText:
    //
    // The TPM does not have enough space to load the requested resource.
    //
    TBSIMP_E_NOT_ENOUGH_SPACE = 0x8029020FL,

    //
    // MessageId: TBSIMP_E_NOT_ENOUGH_TPM_CONTEXTS
    //
    // MessageText:
    //
    // There are too many TPM contexts in use.
    //
    TBSIMP_E_NOT_ENOUGH_TPM_CONTEXTS = 0x80290210L,

    //
    // MessageId: TBSIMP_E_COMMAND_FAILED
    //
    // MessageText:
    //
    // The TPM command failed.
    //
    TBSIMP_E_COMMAND_FAILED = 0x80290211L,

    //
    // MessageId: TBSIMP_E_UNKNOWN_ORDINAL
    //
    // MessageText:
    //
    // The TBS does not recognize the specified ordinal.
    //
    TBSIMP_E_UNKNOWN_ORDINAL = 0x80290212L,

    //
    // MessageId: TBSIMP_E_RESOURCE_EXPIRED
    //
    // MessageText:
    //
    // The requested resource is no longer available.
    //
    TBSIMP_E_RESOURCE_EXPIRED = 0x80290213L,

    //
    // MessageId: TBSIMP_E_INVALID_RESOURCE
    //
    // MessageText:
    //
    // The resource type did not match.
    //
    TBSIMP_E_INVALID_RESOURCE = 0x80290214L,

    //
    // MessageId: TBSIMP_E_NOTHING_TO_UNLOAD
    //
    // MessageText:
    //
    // No resources can be unloaded.
    //
    TBSIMP_E_NOTHING_TO_UNLOAD = 0x80290215L,

    //
    // MessageId: TBSIMP_E_HASH_TABLE_FULL
    //
    // MessageText:
    //
    // No new entries can be added to the hash table.
    //
    TBSIMP_E_HASH_TABLE_FULL = 0x80290216L,

    //
    // MessageId: TBSIMP_E_TOO_MANY_TBS_CONTEXTS
    //
    // MessageText:
    //
    // A new TBS context could not be created because there are too many open contexts.
    //
    TBSIMP_E_TOO_MANY_TBS_CONTEXTS = 0x80290217L,

    //
    // MessageId: TBSIMP_E_TOO_MANY_RESOURCES
    //
    // MessageText:
    //
    // A new virtual resource could not be created because there are too many open virtual resources.
    //
    TBSIMP_E_TOO_MANY_RESOURCES = 0x80290218L,

    //
    // MessageId: TBSIMP_E_PPI_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The physical presence interface is not supported.
    //
    TBSIMP_E_PPI_NOT_SUPPORTED = 0x80290219L,

    //
    // MessageId: TBSIMP_E_TPM_INCOMPATIBLE
    //
    // MessageText:
    //
    // TBS is not compatible with the version of TPM found on the system.
    //
    TBSIMP_E_TPM_INCOMPATIBLE = 0x8029021AL,

    //
    // MessageId: TBSIMP_E_NO_EVENT_LOG
    //
    // MessageText:
    //
    // No TCG event log is available.
    //
    TBSIMP_E_NO_EVENT_LOG = 0x8029021BL,

    //
    // TPM Physical Presence implementation error codes {0x0300..0x03ff}
    //
    //
    // MessageId: TPM_E_PPI_ACPI_FAILURE
    //
    // MessageText:
    //
    // A general error was detected when attempting to acquire the BIOS's response to a Physical Presence command.
    //
    TPM_E_PPI_ACPI_FAILURE = 0x80290300L,

    //
    // MessageId: TPM_E_PPI_USER_ABORT
    //
    // MessageText:
    //
    // The user failed to confirm the TPM operation request.
    //
    TPM_E_PPI_USER_ABORT = 0x80290301L,

    //
    // MessageId: TPM_E_PPI_BIOS_FAILURE
    //
    // MessageText:
    //
    // The BIOS failure prevented the successful execution of the requested TPM operation (e.g. invalid TPM operation request, BIOS communication error with the TPM).
    //
    TPM_E_PPI_BIOS_FAILURE = 0x80290302L,

    //
    // MessageId: TPM_E_PPI_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The BIOS does not support the physical presence interface.
    //
    TPM_E_PPI_NOT_SUPPORTED = 0x80290303L,

    //
    // MessageId: TPM_E_PPI_BLOCKED_IN_BIOS
    //
    // MessageText:
    //
    // The Physical Presence command was blocked by current BIOS settings. The system owner may be able to reconfigure the BIOS settings to allow the command.
    //
    TPM_E_PPI_BLOCKED_IN_BIOS = 0x80290304L,

    //
    // Platform Crypto Provider (PCPTPM12.dll and future platform crypto providers)  error codes {0x0400..0x04ff}
    //
    //
    // MessageId: TPM_E_PCP_ERROR_MASK
    //
    // MessageText:
    //
    // This is an error mask to convert Platform Crypto Provider errors to win errors.
    //
    TPM_E_PCP_ERROR_MASK = 0x80290400L,

    //
    // MessageId: TPM_E_PCP_DEVICE_NOT_READY
    //
    // MessageText:
    //
    // The Platform Crypto Device is currently not ready. It needs to be fully provisioned to be operational.
    //
    TPM_E_PCP_DEVICE_NOT_READY = 0x80290401L,

    //
    // MessageId: TPM_E_PCP_INVALID_HANDLE
    //
    // MessageText:
    //
    // The handle provided to the Platform Crypto Provider is invalid.
    //
    TPM_E_PCP_INVALID_HANDLE = 0x80290402L,

    //
    // MessageId: TPM_E_PCP_INVALID_PARAMETER
    //
    // MessageText:
    //
    // A parameter provided to the Platform Crypto Provider is invalid.
    //
    TPM_E_PCP_INVALID_PARAMETER = 0x80290403L,

    //
    // MessageId: TPM_E_PCP_FLAG_NOT_SUPPORTED
    //
    // MessageText:
    //
    // A provided flag to the Platform Crypto Provider is not supported.
    //
    TPM_E_PCP_FLAG_NOT_SUPPORTED = 0x80290404L,

    //
    // MessageId: TPM_E_PCP_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The requested operation is not supported by this Platform Crypto Provider.
    //
    TPM_E_PCP_NOT_SUPPORTED = 0x80290405L,

    //
    // MessageId: TPM_E_PCP_BUFFER_TOO_SMALL
    //
    // MessageText:
    //
    // The buffer is too small to contain all data. No information has been written to the buffer.
    //
    TPM_E_PCP_BUFFER_TOO_SMALL = 0x80290406L,

    //
    // MessageId: TPM_E_PCP_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An unexpected internal error has occurred in the Platform Crypto Provider.
    //
    TPM_E_PCP_INTERNAL_ERROR = 0x80290407L,

    //
    // MessageId: TPM_E_PCP_AUTHENTICATION_FAILED
    //
    // MessageText:
    //
    // The authorization to use a provider object has failed.
    //
    TPM_E_PCP_AUTHENTICATION_FAILED = 0x80290408L,

    //
    // MessageId: TPM_E_PCP_AUTHENTICATION_IGNORED
    //
    // MessageText:
    //
    // The Platform Crypto Device has ignored the authorization for the provider object, to mitigate against a dictionary attack.
    //
    TPM_E_PCP_AUTHENTICATION_IGNORED = 0x80290409L,

    //
    // MessageId: TPM_E_PCP_POLICY_NOT_FOUND
    //
    // MessageText:
    //
    // The referenced policy was not found.
    //
    TPM_E_PCP_POLICY_NOT_FOUND = 0x8029040AL,

    //
    // MessageId: TPM_E_PCP_PROFILE_NOT_FOUND
    //
    // MessageText:
    //
    // The referenced profile was not found.
    //
    TPM_E_PCP_PROFILE_NOT_FOUND = 0x8029040BL,

    //
    // MessageId: TPM_E_PCP_VALIDATION_FAILED
    //
    // MessageText:
    //
    // The validation was not succesful.
    //
    TPM_E_PCP_VALIDATION_FAILED = 0x8029040CL,

    //
    // =======================================================
    // Facility Performance Logs & Alerts (PLA) Error Messages
    // =======================================================
    //
    //
    // MessageId: PLA_E_DCS_NOT_FOUND
    //
    // MessageText:
    //
    // Data Collector Set was not found.
    //
    PLA_E_DCS_NOT_FOUND = 0x80300002L,

    //
    // MessageId: PLA_E_DCS_IN_USE
    //
    // MessageText:
    //
    // The Data Collector Set or one of its dependencies is already in use.
    //
    PLA_E_DCS_IN_USE = 0x803000AAL,

    //
    // MessageId: PLA_E_TOO_MANY_FOLDERS
    //
    // MessageText:
    //
    // Unable to start Data Collector Set because there are too many folders.
    //
    PLA_E_TOO_MANY_FOLDERS = 0x80300045L,

    //
    // MessageId: PLA_E_NO_MIN_DISK
    //
    // MessageText:
    //
    // Not enough free disk space to start Data Collector Set.
    //
    PLA_E_NO_MIN_DISK = 0x80300070L,

    //
    // MessageId: PLA_E_DCS_ALREADY_EXISTS
    //
    // MessageText:
    //
    // Data Collector Set already exists.
    //
    PLA_E_DCS_ALREADY_EXISTS = 0x803000B7L,

    //
    // MessageId: PLA_S_PROPERTY_IGNORED
    //
    // MessageText:
    //
    // Property value will be ignored.
    //
    PLA_S_PROPERTY_IGNORED = 0x00300100L,

    //
    // MessageId: PLA_E_PROPERTY_CONFLICT
    //
    // MessageText:
    //
    // Property value conflict.
    //
    PLA_E_PROPERTY_CONFLICT = 0x80300101L,

    //
    // MessageId: PLA_E_DCS_SINGLETON_REQUIRED
    //
    // MessageText:
    //
    // The current configuration for this Data Collector Set requires that it contain exactly one Data Collector.
    //
    PLA_E_DCS_SINGLETON_REQUIRED = 0x80300102L,

    //
    // MessageId: PLA_E_CREDENTIALS_REQUIRED
    //
    // MessageText:
    //
    // A user account is required in order to commit the current Data Collector Set properties.
    //
    PLA_E_CREDENTIALS_REQUIRED = 0x80300103L,

    //
    // MessageId: PLA_E_DCS_NOT_RUNNING
    //
    // MessageText:
    //
    // Data Collector Set is not running.
    //
    PLA_E_DCS_NOT_RUNNING = 0x80300104L,

    //
    // MessageId: PLA_E_CONFLICT_INCL_EXCL_API
    //
    // MessageText:
    //
    // A conflict was detected in the list of include/exclude APIs. Do not specify the same API in both the include list and the exclude list.
    //
    PLA_E_CONFLICT_INCL_EXCL_API = 0x80300105L,

    //
    // MessageId: PLA_E_NETWORK_EXE_NOT_VALID
    //
    // MessageText:
    //
    // The executable path you have specified refers to a network share or UNC path.
    //
    PLA_E_NETWORK_EXE_NOT_VALID = 0x80300106L,

    //
    // MessageId: PLA_E_EXE_ALREADY_CONFIGURED
    //
    // MessageText:
    //
    // The executable path you have specified is already configured for API tracing.
    //
    PLA_E_EXE_ALREADY_CONFIGURED = 0x80300107L,

    //
    // MessageId: PLA_E_EXE_PATH_NOT_VALID
    //
    // MessageText:
    //
    // The executable path you have specified does not exist. Verify that the specified path is correct.
    //
    PLA_E_EXE_PATH_NOT_VALID = 0x80300108L,

    //
    // MessageId: PLA_E_DC_ALREADY_EXISTS
    //
    // MessageText:
    //
    // Data Collector already exists.
    //
    PLA_E_DC_ALREADY_EXISTS = 0x80300109L,

    //
    // MessageId: PLA_E_DCS_START_WAIT_TIMEOUT
    //
    // MessageText:
    //
    // The wait for the Data Collector Set start notification has timed out.
    //
    PLA_E_DCS_START_WAIT_TIMEOUT = 0x8030010AL,

    //
    // MessageId: PLA_E_DC_START_WAIT_TIMEOUT
    //
    // MessageText:
    //
    // The wait for the Data Collector to start has timed out.
    //
    PLA_E_DC_START_WAIT_TIMEOUT = 0x8030010BL,

    //
    // MessageId: PLA_E_REPORT_WAIT_TIMEOUT
    //
    // MessageText:
    //
    // The wait for the report generation tool to finish has timed out.
    //
    PLA_E_REPORT_WAIT_TIMEOUT = 0x8030010CL,

    //
    // MessageId: PLA_E_NO_DUPLICATES
    //
    // MessageText:
    //
    // Duplicate items are not allowed.
    //
    PLA_E_NO_DUPLICATES = 0x8030010DL,

    //
    // MessageId: PLA_E_EXE_FULL_PATH_REQUIRED
    //
    // MessageText:
    //
    // When specifying the executable that you want to trace, you must specify a full path to the executable and not just a filename.
    //
    PLA_E_EXE_FULL_PATH_REQUIRED = 0x8030010EL,

    //
    // MessageId: PLA_E_INVALID_SESSION_NAME
    //
    // MessageText:
    //
    // The session name provided is invalid.
    //
    PLA_E_INVALID_SESSION_NAME = 0x8030010FL,

    //
    // MessageId: PLA_E_PLA_CHANNEL_NOT_ENABLED
    //
    // MessageText:
    //
    // The Event Log channel Microsoft-Windows-Diagnosis-PLA/Operational must be enabled to perform this operation.
    //
    PLA_E_PLA_CHANNEL_NOT_ENABLED = 0x80300110L,

    //
    // MessageId: PLA_E_TASKSCHED_CHANNEL_NOT_ENABLED
    //
    // MessageText:
    //
    // The Event Log channel Microsoft-Windows-TaskScheduler must be enabled to perform this operation.
    //
    PLA_E_TASKSCHED_CHANNEL_NOT_ENABLED = 0x80300111L,

    //
    // MessageId: PLA_E_RULES_MANAGER_FAILED
    //
    // MessageText:
    //
    // The execution of the Rules Manager failed.
    //
    PLA_E_RULES_MANAGER_FAILED = 0x80300112L,

    //
    // MessageId: PLA_E_CABAPI_FAILURE
    //
    // MessageText:
    //
    // An error occurred while attempting to compress or extract the data.
    //
    PLA_E_CABAPI_FAILURE = 0x80300113L,

    //
    // =======================================================
    // Full Volume Encryption Error Messages
    // =======================================================
    //
    //
    // MessageId: FVE_E_LOCKED_VOLUME
    //
    // MessageText:
    //
    // This drive is locked by BitLocker Drive Encryption. You must unlock this drive from Control Panel.
    //
    FVE_E_LOCKED_VOLUME = 0x80310000L,

    //
    // MessageId: FVE_E_NOT_ENCRYPTED
    //
    // MessageText:
    //
    // This drive is not encrypted.
    //
    FVE_E_NOT_ENCRYPTED = 0x80310001L,

    //
    // MessageId: FVE_E_NO_TPM_BIOS
    //
    // MessageText:
    //
    // The BIOS did not correctly communicate with the Trusted Platform Module (TPM). Contact the computer manufacturer for BIOS upgrade instructions.
    //
    FVE_E_NO_TPM_BIOS = 0x80310002L,

    //
    // MessageId: FVE_E_NO_MBR_METRIC
    //
    // MessageText:
    //
    // The BIOS did not correctly communicate with the master boot record (MBR). Contact the computer manufacturer for BIOS upgrade instructions.
    //
    FVE_E_NO_MBR_METRIC = 0x80310003L,

    //
    // MessageId: FVE_E_NO_BOOTSECTOR_METRIC
    //
    // MessageText:
    //
    // A required TPM measurement is missing. If there is a bootable CD or DVD in your computer, remove it, restart the computer, and turn on BitLocker again. If the problem persists, ensure the master boot record is up to date.
    //
    FVE_E_NO_BOOTSECTOR_METRIC = 0x80310004L,

    //
    // MessageId: FVE_E_NO_BOOTMGR_METRIC
    //
    // MessageText:
    //
    // The boot sector of this drive is not compatible with BitLocker Drive Encryption. Use the Bootrec.exe tool in the Windows Recovery Environment to update or repair the boot manager (BOOTMGR).
    //
    FVE_E_NO_BOOTMGR_METRIC = 0x80310005L,

    //
    // MessageId: FVE_E_WRONG_BOOTMGR
    //
    // MessageText:
    //
    // The boot manager of this operating system is not compatible with BitLocker Drive Encryption. Use the Bootrec.exe tool in the Windows Recovery Environment to update or repair the boot manager (BOOTMGR).
    //
    FVE_E_WRONG_BOOTMGR = 0x80310006L,

    //
    // MessageId: FVE_E_SECURE_KEY_REQUIRED
    //
    // MessageText:
    //
    // At least one secure key protector is required for this operation to be performed.
    //
    FVE_E_SECURE_KEY_REQUIRED = 0x80310007L,

    //
    // MessageId: FVE_E_NOT_ACTIVATED
    //
    // MessageText:
    //
    // BitLocker Drive Encryption is not enabled on this drive. Turn on BitLocker.
    //
    FVE_E_NOT_ACTIVATED = 0x80310008L,

    //
    // MessageId: FVE_E_ACTION_NOT_ALLOWED
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot perform the requested action. This condition may occur when two requests are issued at the same time. Wait a few moments and then try the action again.
    //
    FVE_E_ACTION_NOT_ALLOWED = 0x80310009L,

    //
    // MessageId: FVE_E_AD_SCHEMA_NOT_INSTALLED
    //
    // MessageText:
    //
    // The Active Directory Domain Services forest does not contain the required attributes and classes to host BitLocker Drive Encryption or Trusted Platform Module information. Contact your domain administrator to verify that any required BitLocker Active Directory schema extensions have been installed.
    //
    FVE_E_AD_SCHEMA_NOT_INSTALLED = 0x8031000AL,

    //
    // MessageId: FVE_E_AD_INVALID_DATATYPE
    //
    // MessageText:
    //
    // The type of the data obtained from Active Directory was not expected. The BitLocker recovery information may be missing or corrupted.
    //
    FVE_E_AD_INVALID_DATATYPE = 0x8031000BL,

    //
    // MessageId: FVE_E_AD_INVALID_DATASIZE
    //
    // MessageText:
    //
    // The size of the data obtained from Active Directory was not expected. The BitLocker recovery information may be missing or corrupted.
    //
    FVE_E_AD_INVALID_DATASIZE = 0x8031000CL,

    //
    // MessageId: FVE_E_AD_NO_VALUES
    //
    // MessageText:
    //
    // The attribute read from Active Directory does not contain any values. The BitLocker recovery information may be missing or corrupted.
    //
    FVE_E_AD_NO_VALUES = 0x8031000DL,

    //
    // MessageId: FVE_E_AD_ATTR_NOT_SET
    //
    // MessageText:
    //
    // The attribute was not set. Verify that you are logged on with a domain account that has the ability to write information to Active Directory objects.
    //
    FVE_E_AD_ATTR_NOT_SET = 0x8031000EL,

    //
    // MessageId: FVE_E_AD_GUID_NOT_FOUND
    //
    // MessageText:
    //
    // The specified attribute cannot be found in Active Directory Domain Services. Contact your domain administrator to verify that any required BitLocker Active Directory schema extensions have been installed.
    //
    FVE_E_AD_GUID_NOT_FOUND = 0x8031000FL,

    //
    // MessageId: FVE_E_BAD_INFORMATION
    //
    // MessageText:
    //
    // The BitLocker metadata for the encrypted drive is not valid. You can attempt to repair the drive to restore access.
    //
    FVE_E_BAD_INFORMATION = 0x80310010L,

    //
    // MessageId: FVE_E_TOO_SMALL
    //
    // MessageText:
    //
    // The drive cannot be encrypted because it does not have enough free space. Delete any unnecessary data on the drive to create additional free space and then try again.
    //
    FVE_E_TOO_SMALL = 0x80310011L,

    //
    // MessageId: FVE_E_SYSTEM_VOLUME
    //
    // MessageText:
    //
    // The drive cannot be encrypted because it contains system boot information. Create a separate partition for use as the system drive that contains the boot information and a second partition for use as the operating system drive and then encrypt the operating system drive.
    //
    FVE_E_SYSTEM_VOLUME = 0x80310012L,

    //
    // MessageId: FVE_E_FAILED_WRONG_FS
    //
    // MessageText:
    //
    // The drive cannot be encrypted because the file system is not supported.
    //
    FVE_E_FAILED_WRONG_FS = 0x80310013L,

    //
    // MessageId: FVE_E_BAD_PARTITION_SIZE
    //
    // MessageText:
    //
    // The file system size is larger than the partition size in the partition table. This drive may be corrupt or may have been tampered with. To use it with BitLocker, you must reformat the partition.
    //
    FVE_E_BAD_PARTITION_SIZE = 0x80310014L,

    //
    // MessageId: FVE_E_NOT_SUPPORTED
    //
    // MessageText:
    //
    // This drive cannot be encrypted.
    //
    FVE_E_NOT_SUPPORTED = 0x80310015L,

    //
    // MessageId: FVE_E_BAD_DATA
    //
    // MessageText:
    //
    // The data is not valid.
    //
    FVE_E_BAD_DATA = 0x80310016L,

    //
    // MessageId: FVE_E_VOLUME_NOT_BOUND
    //
    // MessageText:
    //
    // The data drive specified is not set to automatically unlock on the current computer and cannot be unlocked automatically.
    //
    FVE_E_VOLUME_NOT_BOUND = 0x80310017L,

    //
    // MessageId: FVE_E_TPM_NOT_OWNED
    //
    // MessageText:
    //
    // You must initialize the Trusted Platform Module (TPM) before you can use BitLocker Drive Encryption.
    //
    FVE_E_TPM_NOT_OWNED = 0x80310018L,

    //
    // MessageId: FVE_E_NOT_DATA_VOLUME
    //
    // MessageText:
    //
    // The operation attempted cannot be performed on an operating system drive.
    //
    FVE_E_NOT_DATA_VOLUME = 0x80310019L,

    //
    // MessageId: FVE_E_AD_INSUFFICIENT_BUFFER
    //
    // MessageText:
    //
    // The buffer supplied to a function was insufficient to contain the returned data. Increase the buffer size before running the function again.
    //
    FVE_E_AD_INSUFFICIENT_BUFFER = 0x8031001AL,

    //
    // MessageId: FVE_E_CONV_READ
    //
    // MessageText:
    //
    // A read operation failed while converting the drive. The drive was not converted. Please re-enable BitLocker.
    //
    FVE_E_CONV_READ = 0x8031001BL,

    //
    // MessageId: FVE_E_CONV_WRITE
    //
    // MessageText:
    //
    // A write operation failed while converting the drive. The drive was not converted. Please re-enable BitLocker.
    //
    FVE_E_CONV_WRITE = 0x8031001CL,

    //
    // MessageId: FVE_E_KEY_REQUIRED
    //
    // MessageText:
    //
    // One or more BitLocker key protectors are required. You cannot delete the last key on this drive.
    //
    FVE_E_KEY_REQUIRED = 0x8031001DL,

    //
    // MessageId: FVE_E_CLUSTERING_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Cluster configurations are not supported by BitLocker Drive Encryption.
    //
    FVE_E_CLUSTERING_NOT_SUPPORTED = 0x8031001EL,

    //
    // MessageId: FVE_E_VOLUME_BOUND_ALREADY
    //
    // MessageText:
    //
    // The drive specified is already configured to be automatically unlocked on the current computer.
    //
    FVE_E_VOLUME_BOUND_ALREADY = 0x8031001FL,

    //
    // MessageId: FVE_E_OS_NOT_PROTECTED
    //
    // MessageText:
    //
    // The operating system drive is not protected by BitLocker Drive Encryption.
    //
    FVE_E_OS_NOT_PROTECTED = 0x80310020L,

    //
    // MessageId: FVE_E_PROTECTION_DISABLED
    //
    // MessageText:
    //
    // BitLocker Drive Encryption has been suspended on this drive. All BitLocker key protectors configured for this drive are effectively disabled, and the drive will be automatically unlocked using an unencrypted (clear) key.
    //
    FVE_E_PROTECTION_DISABLED = 0x80310021L,

    //
    // MessageId: FVE_E_RECOVERY_KEY_REQUIRED
    //
    // MessageText:
    //
    // The drive you are attempting to lock does not have any key protectors available for encryption because BitLocker protection is currently suspended. Re-enable BitLocker to lock this drive.
    //
    FVE_E_RECOVERY_KEY_REQUIRED = 0x80310022L,

    //
    // MessageId: FVE_E_FOREIGN_VOLUME
    //
    // MessageText:
    //
    // BitLocker cannot use the Trusted Platform Module (TPM) to protect a data drive. TPM protection can only be used with the operating system drive.
    //
    FVE_E_FOREIGN_VOLUME = 0x80310023L,

    //
    // MessageId: FVE_E_OVERLAPPED_UPDATE
    //
    // MessageText:
    //
    // The BitLocker metadata for the encrypted drive cannot be updated because it was locked for updating by another process. Please try this process again.
    //
    FVE_E_OVERLAPPED_UPDATE = 0x80310024L,

    //
    // MessageId: FVE_E_TPM_SRK_AUTH_NOT_ZERO
    //
    // MessageText:
    //
    // The authorization data for the storage root key (SRK) of the Trusted Platform Module (TPM) is not zero and is therefore incompatible with BitLocker. Please initialize the TPM before attempting to use it with BitLocker.
    //
    FVE_E_TPM_SRK_AUTH_NOT_ZERO = 0x80310025L,

    //
    // MessageId: FVE_E_FAILED_SECTOR_SIZE
    //
    // MessageText:
    //
    // The drive encryption algorithm cannot be used on this sector size.
    //
    FVE_E_FAILED_SECTOR_SIZE = 0x80310026L,

    //
    // MessageId: FVE_E_FAILED_AUTHENTICATION
    //
    // MessageText:
    //
    // The drive cannot be unlocked with the key provided. Confirm that you have provided the correct key and try again.
    //
    FVE_E_FAILED_AUTHENTICATION = 0x80310027L,

    //
    // MessageId: FVE_E_NOT_OS_VOLUME
    //
    // MessageText:
    //
    // The drive specified is not the operating system drive.
    //
    FVE_E_NOT_OS_VOLUME = 0x80310028L,

    //
    // MessageId: FVE_E_AUTOUNLOCK_ENABLED
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be turned off on the operating system drive until the auto unlock feature has been disabled for the fixed data drives and removable data drives associated with this computer.
    //
    FVE_E_AUTOUNLOCK_ENABLED = 0x80310029L,

    //
    // MessageId: FVE_E_WRONG_BOOTSECTOR
    //
    // MessageText:
    //
    // The system partition boot sector does not perform Trusted Platform Module (TPM) measurements. Use the Bootrec.exe tool in the Windows Recovery Environment to update or repair the boot sector.
    //
    FVE_E_WRONG_BOOTSECTOR = 0x8031002AL,

    //
    // MessageId: FVE_E_WRONG_SYSTEM_FS
    //
    // MessageText:
    //
    // BitLocker Drive Encryption operating system drives must be formatted with the NTFS file system in order to be encrypted. Convert the drive to NTFS, and then turn on BitLocker.
    //
    FVE_E_WRONG_SYSTEM_FS = 0x8031002BL,

    //
    // MessageId: FVE_E_POLICY_PASSWORD_REQUIRED
    //
    // MessageText:
    //
    // Group Policy settings require that a recovery password be specified before encrypting the drive.
    //
    FVE_E_POLICY_PASSWORD_REQUIRED = 0x8031002CL,

    //
    // MessageId: FVE_E_CANNOT_SET_FVEK_ENCRYPTED
    //
    // MessageText:
    //
    // The drive encryption algorithm and key cannot be set on a previously encrypted drive. To encrypt this drive with BitLocker Drive Encryption, remove the previous encryption and then turn on BitLocker.
    //
    FVE_E_CANNOT_SET_FVEK_ENCRYPTED = 0x8031002DL,

    //
    // MessageId: FVE_E_CANNOT_ENCRYPT_NO_KEY
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot encrypt the specified drive because an encryption key is not available. Add a key protector to encrypt this drive.
    //
    FVE_E_CANNOT_ENCRYPT_NO_KEY = 0x8031002EL,

    //
    // MessageId: FVE_E_BOOTABLE_CDDVD
    //
    // MessageText:
    //
    // BitLocker Drive Encryption detected bootable media (CD or DVD) in the computer. Remove the media and restart the computer before configuring BitLocker.
    //
    FVE_E_BOOTABLE_CDDVD = 0x80310030L,

    //
    // MessageId: FVE_E_PROTECTOR_EXISTS
    //
    // MessageText:
    //
    // This key protector cannot be added. Only one key protector of this type is allowed for this drive.
    //
    FVE_E_PROTECTOR_EXISTS = 0x80310031L,

    //
    // MessageId: FVE_E_RELATIVE_PATH
    //
    // MessageText:
    //
    // The recovery password file was not found because a relative path was specified. Recovery passwords must be saved to a fully qualified path. Environment variables configured on the computer can be used in the path.
    //
    FVE_E_RELATIVE_PATH = 0x80310032L,

    //
    // MessageId: FVE_E_PROTECTOR_NOT_FOUND
    //
    // MessageText:
    //
    // The specified key protector was not found on the drive. Try another key protector.
    //
    FVE_E_PROTECTOR_NOT_FOUND = 0x80310033L,

    //
    // MessageId: FVE_E_INVALID_KEY_FORMAT
    //
    // MessageText:
    //
    // The recovery key provided is corrupt and cannot be used to access the drive. An alternative recovery method, such as recovery password, a data recovery agent, or a backup version of the recovery key must be used to recover access to the drive.
    //
    FVE_E_INVALID_KEY_FORMAT = 0x80310034L,

    //
    // MessageId: FVE_E_INVALID_PASSWORD_FORMAT
    //
    // MessageText:
    //
    // The format of the recovery password provided is invalid. BitLocker recovery passwords are 48 digits. Verify that the recovery password is in the correct format and then try again.
    //
    FVE_E_INVALID_PASSWORD_FORMAT = 0x80310035L,

    //
    // MessageId: FVE_E_FIPS_RNG_CHECK_FAILED
    //
    // MessageText:
    //
    // The random number generator check test failed.
    //
    FVE_E_FIPS_RNG_CHECK_FAILED = 0x80310036L,

    //
    // MessageId: FVE_E_FIPS_PREVENTS_RECOVERY_PASSWORD
    //
    // MessageText:
    //
    // The Group Policy setting requiring FIPS compliance prevents a local recovery password from being generated or used by BitLocker Drive Encryption. When operating in FIPS-compliant mode, BitLocker recovery options can be either a recovery key stored on a USB drive or recovery through a data recovery agent.
    //
    FVE_E_FIPS_PREVENTS_RECOVERY_PASSWORD = 0x80310037L,

    //
    // MessageId: FVE_E_FIPS_PREVENTS_EXTERNAL_KEY_EXPORT
    //
    // MessageText:
    //
    // The Group Policy setting requiring FIPS compliance prevents the recovery password from being saved to Active Directory. When operating in FIPS-compliant mode, BitLocker recovery options can be either a recovery key stored on a USB drive or recovery through a data recovery agent. Check your Group Policy settings configuration.
    //
    FVE_E_FIPS_PREVENTS_EXTERNAL_KEY_EXPORT = 0x80310038L,

    //
    // MessageId: FVE_E_NOT_DECRYPTED
    //
    // MessageText:
    //
    // The drive must be fully decrypted to complete this operation.
    //
    FVE_E_NOT_DECRYPTED = 0x80310039L,

    //
    // MessageId: FVE_E_INVALID_PROTECTOR_TYPE
    //
    // MessageText:
    //
    // The key protector specified cannot be used for this operation.
    //
    FVE_E_INVALID_PROTECTOR_TYPE = 0x8031003AL,

    //
    // MessageId: FVE_E_NO_PROTECTORS_TO_TEST
    //
    // MessageText:
    //
    // No key protectors exist on the drive to perform the hardware test.
    //
    FVE_E_NO_PROTECTORS_TO_TEST = 0x8031003BL,

    //
    // MessageId: FVE_E_KEYFILE_NOT_FOUND
    //
    // MessageText:
    //
    // The BitLocker startup key or recovery password cannot be found on the USB device. Verify that you have the correct USB device, that the USB device is plugged into the computer on an active USB port, restart the computer, and then try again. If the problem persists, contact the computer manufacturer for BIOS upgrade instructions.
    //
    FVE_E_KEYFILE_NOT_FOUND = 0x8031003CL,

    //
    // MessageId: FVE_E_KEYFILE_INVALID
    //
    // MessageText:
    //
    // The BitLocker startup key or recovery password file provided is corrupt or invalid. Verify that you have the correct startup key or recovery password file and try again.
    //
    FVE_E_KEYFILE_INVALID = 0x8031003DL,

    //
    // MessageId: FVE_E_KEYFILE_NO_VMK
    //
    // MessageText:
    //
    // The BitLocker encryption key cannot be obtained from the startup key or recovery password. Verify that you have the correct startup key or recovery password and try again.
    //
    FVE_E_KEYFILE_NO_VMK = 0x8031003EL,

    //
    // MessageId: FVE_E_TPM_DISABLED
    //
    // MessageText:
    //
    // The Trusted Platform Module (TPM) is disabled. The TPM must be enabled, initialized, and have valid ownership before it can be used with BitLocker Drive Encryption.
    //
    FVE_E_TPM_DISABLED = 0x8031003FL,

    //
    // MessageId: FVE_E_NOT_ALLOWED_IN_SAFE_MODE
    //
    // MessageText:
    //
    // The BitLocker configuration of the specified drive cannot be managed because this computer is currently operating in Safe Mode. While in Safe Mode, BitLocker Drive Encryption can only be used for recovery purposes.
    //
    FVE_E_NOT_ALLOWED_IN_SAFE_MODE = 0x80310040L,

    //
    // MessageId: FVE_E_TPM_INVALID_PCR
    //
    // MessageText:
    //
    // The Trusted Platform Module (TPM) was unable to unlock the drive. Either the system boot information changed after choosing BitLocker settings or the PIN did not match. If the problem persists after several tries, there may be a hardware or firmware problem.
    //
    FVE_E_TPM_INVALID_PCR = 0x80310041L,

    //
    // MessageId: FVE_E_TPM_NO_VMK
    //
    // MessageText:
    //
    // The BitLocker encryption key cannot be obtained from the Trusted Platform Module (TPM).
    //
    FVE_E_TPM_NO_VMK = 0x80310042L,

    //
    // MessageId: FVE_E_PIN_INVALID
    //
    // MessageText:
    //
    // The BitLocker encryption key cannot be obtained from the Trusted Platform Module (TPM) and PIN.
    //
    FVE_E_PIN_INVALID = 0x80310043L,

    //
    // MessageId: FVE_E_AUTH_INVALID_APPLICATION
    //
    // MessageText:
    //
    // A boot application has changed since BitLocker Drive Encryption was enabled.
    //
    FVE_E_AUTH_INVALID_APPLICATION = 0x80310044L,

    //
    // MessageId: FVE_E_AUTH_INVALID_CONFIG
    //
    // MessageText:
    //
    // The Boot Configuration Data (BCD) settings have changed since BitLocker Drive Encryption was enabled.
    //
    FVE_E_AUTH_INVALID_CONFIG = 0x80310045L,

    //
    // MessageId: FVE_E_FIPS_DISABLE_PROTECTION_NOT_ALLOWED
    //
    // MessageText:
    //
    // The Group Policy setting requiring FIPS compliance prohibits the use of unencrypted keys, which prevents BitLocker from being suspended on this drive. Please contact your domain administrator for more information.
    //
    FVE_E_FIPS_DISABLE_PROTECTION_NOT_ALLOWED = 0x80310046L,

    //
    // MessageId: FVE_E_FS_NOT_EXTENDED
    //
    // MessageText:
    //
    // This drive cannot be encrypted by BitLocker Drive Encryption because the file system does not extend to the end of the drive. Repartition this drive and then try again.
    //
    FVE_E_FS_NOT_EXTENDED = 0x80310047L,

    //
    // MessageId: FVE_E_FIRMWARE_TYPE_NOT_SUPPORTED
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be enabled on the operating system drive. Contact the computer manufacturer for BIOS upgrade instructions.
    //
    FVE_E_FIRMWARE_TYPE_NOT_SUPPORTED = 0x80310048L,

    //
    // MessageId: FVE_E_NO_LICENSE
    //
    // MessageText:
    //
    // This version of Windows does not include BitLocker Drive Encryption. To use BitLocker Drive Encryption, please upgrade the operating system.
    //
    FVE_E_NO_LICENSE = 0x80310049L,

    //
    // MessageId: FVE_E_NOT_ON_STACK
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be used because critical BitLocker system files are missing or corrupted. Use Windows Startup Repair to restore these files to your computer.
    //
    FVE_E_NOT_ON_STACK = 0x8031004AL,

    //
    // MessageId: FVE_E_FS_MOUNTED
    //
    // MessageText:
    //
    // The drive cannot be locked when the drive is in use.
    //
    FVE_E_FS_MOUNTED = 0x8031004BL,

    //
    // MessageId: FVE_E_TOKEN_NOT_IMPERSONATED
    //
    // MessageText:
    //
    // The access token associated with the current thread is not an impersonated token.
    //
    FVE_E_TOKEN_NOT_IMPERSONATED = 0x8031004CL,

    //
    // MessageId: FVE_E_DRY_RUN_FAILED
    //
    // MessageText:
    //
    // The BitLocker encryption key cannot be obtained. Verify that the Trusted Platform Module (TPM) is enabled and ownership has been taken. If this computer does not have a TPM, verify that the USB drive is inserted and available.
    //
    FVE_E_DRY_RUN_FAILED = 0x8031004DL,

    //
    // MessageId: FVE_E_REBOOT_REQUIRED
    //
    // MessageText:
    //
    // You must restart your computer before continuing with BitLocker Drive Encryption.
    //
    FVE_E_REBOOT_REQUIRED = 0x8031004EL,

    //
    // MessageId: FVE_E_DEBUGGER_ENABLED
    //
    // MessageText:
    //
    // Drive encryption cannot occur while boot debugging is enabled. Use the bcdedit command-line tool to turn off boot debugging.
    //
    FVE_E_DEBUGGER_ENABLED = 0x8031004FL,

    //
    // MessageId: FVE_E_RAW_ACCESS
    //
    // MessageText:
    //
    // No action was taken as BitLocker Drive Encryption is in raw access mode.
    //
    FVE_E_RAW_ACCESS = 0x80310050L,

    //
    // MessageId: FVE_E_RAW_BLOCKED
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot enter raw access mode for this drive because the drive is currently in use.
    //
    FVE_E_RAW_BLOCKED = 0x80310051L,

    //
    // MessageId: FVE_E_BCD_APPLICATIONS_PATH_INCORRECT
    //
    // MessageText:
    //
    // The path specified in the Boot Configuration Data (BCD) for a BitLocker Drive Encryption integrity-protected application is incorrect. Please verify and correct your BCD settings and try again.
    //
    FVE_E_BCD_APPLICATIONS_PATH_INCORRECT = 0x80310052L,

    //
    // MessageId: FVE_E_NOT_ALLOWED_IN_VERSION
    //
    // MessageText:
    //
    // BitLocker Drive Encryption can only be used for limited provisioning or recovery purposes when the computer is running in pre-installation or recovery environments.
    //
    FVE_E_NOT_ALLOWED_IN_VERSION = 0x80310053L,

    //
    // MessageId: FVE_E_NO_AUTOUNLOCK_MASTER_KEY
    //
    // MessageText:
    //
    // The auto-unlock master key was not available from the operating system drive.
    //
    FVE_E_NO_AUTOUNLOCK_MASTER_KEY = 0x80310054L,

    //
    // MessageId: FVE_E_MOR_FAILED
    //
    // MessageText:
    //
    // The system firmware failed to enable clearing of system memory when the computer was restarted.
    //
    FVE_E_MOR_FAILED = 0x80310055L,

    //
    // MessageId: FVE_E_HIDDEN_VOLUME
    //
    // MessageText:
    //
    // The hidden drive cannot be encrypted.
    //
    FVE_E_HIDDEN_VOLUME = 0x80310056L,

    //
    // MessageId: FVE_E_TRANSIENT_STATE
    //
    // MessageText:
    //
    // BitLocker encryption keys were ignored because the drive was in a transient state.
    //
    FVE_E_TRANSIENT_STATE = 0x80310057L,

    //
    // MessageId: FVE_E_PUBKEY_NOT_ALLOWED
    //
    // MessageText:
    //
    // Public key based protectors are not allowed on this drive.
    //
    FVE_E_PUBKEY_NOT_ALLOWED = 0x80310058L,

    //
    // MessageId: FVE_E_VOLUME_HANDLE_OPEN
    //
    // MessageText:
    //
    // BitLocker Drive Encryption is already performing an operation on this drive. Please complete all operations before continuing.
    //
    FVE_E_VOLUME_HANDLE_OPEN = 0x80310059L,

    //
    // MessageId: FVE_E_NO_FEATURE_LICENSE
    //
    // MessageText:
    //
    // This version of Windows does not support this feature of BitLocker Drive Encryption. To use this feature, upgrade the operating system.
    //
    FVE_E_NO_FEATURE_LICENSE = 0x8031005AL,

    //
    // MessageId: FVE_E_INVALID_STARTUP_OPTIONS
    //
    // MessageText:
    //
    // The Group Policy settings for BitLocker startup options are in conflict and cannot be applied. Contact your system administrator for more information.
    //
    FVE_E_INVALID_STARTUP_OPTIONS = 0x8031005BL,

    //
    // MessageId: FVE_E_POLICY_RECOVERY_PASSWORD_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit the creation of a recovery password.
    //
    FVE_E_POLICY_RECOVERY_PASSWORD_NOT_ALLOWED = 0x8031005CL,

    //
    // MessageId: FVE_E_POLICY_RECOVERY_PASSWORD_REQUIRED
    //
    // MessageText:
    //
    // Group Policy settings require the creation of a recovery password.
    //
    FVE_E_POLICY_RECOVERY_PASSWORD_REQUIRED = 0x8031005DL,

    //
    // MessageId: FVE_E_POLICY_RECOVERY_KEY_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit the creation of a recovery key.
    //
    FVE_E_POLICY_RECOVERY_KEY_NOT_ALLOWED = 0x8031005EL,

    //
    // MessageId: FVE_E_POLICY_RECOVERY_KEY_REQUIRED
    //
    // MessageText:
    //
    // Group Policy settings require the creation of a recovery key.
    //
    FVE_E_POLICY_RECOVERY_KEY_REQUIRED = 0x8031005FL,

    //
    // MessageId: FVE_E_POLICY_STARTUP_PIN_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit the use of a PIN at startup. Please choose a different BitLocker startup option.
    //
    FVE_E_POLICY_STARTUP_PIN_NOT_ALLOWED = 0x80310060L,

    //
    // MessageId: FVE_E_POLICY_STARTUP_PIN_REQUIRED
    //
    // MessageText:
    //
    // Group Policy settings require the use of a PIN at startup. Please choose this BitLocker startup option.
    //
    FVE_E_POLICY_STARTUP_PIN_REQUIRED = 0x80310061L,

    //
    // MessageId: FVE_E_POLICY_STARTUP_KEY_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit the use of a startup key. Please choose a different BitLocker startup option.
    //
    FVE_E_POLICY_STARTUP_KEY_NOT_ALLOWED = 0x80310062L,

    //
    // MessageId: FVE_E_POLICY_STARTUP_KEY_REQUIRED
    //
    // MessageText:
    //
    // Group Policy settings require the use of a startup key. Please choose this BitLocker startup option.
    //
    FVE_E_POLICY_STARTUP_KEY_REQUIRED = 0x80310063L,

    //
    // MessageId: FVE_E_POLICY_STARTUP_PIN_KEY_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit the use of a startup key and PIN. Please choose a different BitLocker startup option.
    //
    FVE_E_POLICY_STARTUP_PIN_KEY_NOT_ALLOWED = 0x80310064L,

    //
    // MessageId: FVE_E_POLICY_STARTUP_PIN_KEY_REQUIRED
    //
    // MessageText:
    //
    // Group Policy settings require the use of a startup key and PIN. Please choose this BitLocker startup option.
    //
    FVE_E_POLICY_STARTUP_PIN_KEY_REQUIRED = 0x80310065L,

    //
    // MessageId: FVE_E_POLICY_STARTUP_TPM_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group policy does not permit the use of TPM-only at startup. Please choose a different BitLocker startup option.
    //
    FVE_E_POLICY_STARTUP_TPM_NOT_ALLOWED = 0x80310066L,

    //
    // MessageId: FVE_E_POLICY_STARTUP_TPM_REQUIRED
    //
    // MessageText:
    //
    // Group Policy settings require the use of TPM-only at startup. Please choose this BitLocker startup option.
    //
    FVE_E_POLICY_STARTUP_TPM_REQUIRED = 0x80310067L,

    //
    // MessageId: FVE_E_POLICY_INVALID_PIN_LENGTH
    //
    // MessageText:
    //
    // The PIN provided does not meet minimum or maximum length requirements.
    //
    FVE_E_POLICY_INVALID_PIN_LENGTH = 0x80310068L,

    //
    // MessageId: FVE_E_KEY_PROTECTOR_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The key protector is not supported by the version of BitLocker Drive Encryption currently on the drive. Upgrade the drive to add the key protector.
    //
    FVE_E_KEY_PROTECTOR_NOT_SUPPORTED = 0x80310069L,

    //
    // MessageId: FVE_E_POLICY_PASSPHRASE_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit the creation of a password.
    //
    FVE_E_POLICY_PASSPHRASE_NOT_ALLOWED = 0x8031006AL,

    //
    // MessageId: FVE_E_POLICY_PASSPHRASE_REQUIRED
    //
    // MessageText:
    //
    // Group Policy settings require the creation of a password.
    //
    FVE_E_POLICY_PASSPHRASE_REQUIRED = 0x8031006BL,

    //
    // MessageId: FVE_E_FIPS_PREVENTS_PASSPHRASE
    //
    // MessageText:
    //
    // The Group Policy setting requiring FIPS compliance prevents passwords from being generated or used. Please contact your system administrator for more information.
    //
    FVE_E_FIPS_PREVENTS_PASSPHRASE = 0x8031006CL,

    //
    // MessageId: FVE_E_OS_VOLUME_PASSPHRASE_NOT_ALLOWED
    //
    // MessageText:
    //
    // A password cannot be added to the operating system drive.
    //
    FVE_E_OS_VOLUME_PASSPHRASE_NOT_ALLOWED = 0x8031006DL,

    //
    // MessageId: FVE_E_INVALID_BITLOCKER_OID
    //
    // MessageText:
    //
    // The BitLocker object identifier (OID) on the drive appears to be invalid or corrupt. Use manage-BDE to reset the OID on this drive.
    //
    FVE_E_INVALID_BITLOCKER_OID = 0x8031006EL,

    //
    // MessageId: FVE_E_VOLUME_TOO_SMALL
    //
    // MessageText:
    //
    // The drive is too small to be protected using BitLocker Drive Encryption.
    //
    FVE_E_VOLUME_TOO_SMALL = 0x8031006FL,

    //
    // MessageId: FVE_E_DV_NOT_SUPPORTED_ON_FS
    //
    // MessageText:
    //
    // The selected discovery drive type is incompatible with the file system on the drive. BitLocker To Go discovery drives must be created on FAT formatted drives.
    //
    FVE_E_DV_NOT_SUPPORTED_ON_FS = 0x80310070L,

    //
    // MessageId: FVE_E_DV_NOT_ALLOWED_BY_GP
    //
    // MessageText:
    //
    // The selected discovery drive type is not allowed by the computer's Group Policy settings. Verify that Group Policy settings allow the creation of discovery drives for use with BitLocker To Go.
    //
    FVE_E_DV_NOT_ALLOWED_BY_GP = 0x80310071L,

    //
    // MessageId: FVE_E_POLICY_USER_CERTIFICATE_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit user certificates such as smart cards to be used with BitLocker Drive Encryption.
    //
    FVE_E_POLICY_USER_CERTIFICATE_NOT_ALLOWED = 0x80310072L,

    //
    // MessageId: FVE_E_POLICY_USER_CERTIFICATE_REQUIRED
    //
    // MessageText:
    //
    // Group Policy settings require that you have a valid user certificate, such as a smart card, to be used with BitLocker Drive Encryption.
    //
    FVE_E_POLICY_USER_CERTIFICATE_REQUIRED = 0x80310073L,

    //
    // MessageId: FVE_E_POLICY_USER_CERT_MUST_BE_HW
    //
    // MessageText:
    //
    // Group Policy settings requires that you use a smart card-based key protector with BitLocker Drive Encryption.
    //
    FVE_E_POLICY_USER_CERT_MUST_BE_HW = 0x80310074L,

    //
    // MessageId: FVE_E_POLICY_USER_CONFIGURE_FDV_AUTOUNLOCK_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit BitLocker-protected fixed data drives to be automatically unlocked.
    //
    FVE_E_POLICY_USER_CONFIGURE_FDV_AUTOUNLOCK_NOT_ALLOWED = 0x80310075L,

    //
    // MessageId: FVE_E_POLICY_USER_CONFIGURE_RDV_AUTOUNLOCK_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit BitLocker-protected removable data drives to be automatically unlocked.
    //
    FVE_E_POLICY_USER_CONFIGURE_RDV_AUTOUNLOCK_NOT_ALLOWED = 0x80310076L,

    //
    // MessageId: FVE_E_POLICY_USER_CONFIGURE_RDV_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit you to configure BitLocker Drive Encryption on removable data drives.
    //
    FVE_E_POLICY_USER_CONFIGURE_RDV_NOT_ALLOWED = 0x80310077L,

    //
    // MessageId: FVE_E_POLICY_USER_ENABLE_RDV_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit you to turn on BitLocker Drive Encryption on removable data drives. Please contact your system administrator if you need to turn on BitLocker.
    //
    FVE_E_POLICY_USER_ENABLE_RDV_NOT_ALLOWED = 0x80310078L,

    //
    // MessageId: FVE_E_POLICY_USER_DISABLE_RDV_NOT_ALLOWED
    //
    // MessageText:
    //
    // Group Policy settings do not permit turning off BitLocker Drive Encryption on removable data drives. Please contact your system administrator if you need to turn off BitLocker.
    //
    FVE_E_POLICY_USER_DISABLE_RDV_NOT_ALLOWED = 0x80310079L,

    //
    // MessageId: FVE_E_POLICY_INVALID_PASSPHRASE_LENGTH
    //
    // MessageText:
    //
    // Your password does not meet minimum password length requirements. By default, passwords must be at least 8 characters in length. Check with your system administrator for the password length requirement in your organization.
    //
    FVE_E_POLICY_INVALID_PASSPHRASE_LENGTH = 0x80310080L,

    //
    // MessageId: FVE_E_POLICY_PASSPHRASE_TOO_SIMPLE
    //
    // MessageText:
    //
    // Your password does not meet the complexity requirements set by your system administrator. Try adding upper and lowercase characters, numbers, and symbols.
    //
    FVE_E_POLICY_PASSPHRASE_TOO_SIMPLE = 0x80310081L,

    //
    // MessageId: FVE_E_RECOVERY_PARTITION
    //
    // MessageText:
    //
    // This drive cannot be encrypted because it is reserved for Windows System Recovery Options.
    //
    FVE_E_RECOVERY_PARTITION = 0x80310082L,

    //
    // MessageId: FVE_E_POLICY_CONFLICT_FDV_RK_OFF_AUK_ON
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be applied to this drive because of conflicting Group Policy settings. BitLocker cannot be configured to automatically unlock fixed data drives when user recovery options are disabled. If you want BitLocker-protected fixed data drives to be automatically unlocked after key validation has occurred, please ask your system administrator to resolve the settings conflict before enabling BitLocker.
    //
    FVE_E_POLICY_CONFLICT_FDV_RK_OFF_AUK_ON = 0x80310083L,

    //
    // MessageId: FVE_E_POLICY_CONFLICT_RDV_RK_OFF_AUK_ON
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be applied to this drive because of conflicting Group Policy settings. BitLocker cannot be configured to automatically unlock removable data drives when user recovery option are disabled. If you want BitLocker-protected removable data drives to be automatically unlocked after key validation has occurred, please ask your system administrator to resolve the settings conflict before enabling BitLocker.
    //
    FVE_E_POLICY_CONFLICT_RDV_RK_OFF_AUK_ON = 0x80310084L,

    //
    // MessageId: FVE_E_NON_BITLOCKER_OID
    //
    // MessageText:
    //
    // The Enhanced Key Usage (EKU) attribute of the specified certificate does not permit it to be used for BitLocker Drive Encryption. BitLocker does not require that a certificate have an EKU attribute, but if one is configured it must be set to an object identifier (OID) that matches the OID configured for BitLocker.
    //
    FVE_E_NON_BITLOCKER_OID = 0x80310085L,

    //
    // MessageId: FVE_E_POLICY_PROHIBITS_SELFSIGNED
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be applied to this drive as currently configured because of Group Policy settings. The certificate you provided for drive encryption is self-signed. Current Group Policy settings do not permit the use of self-signed certificates. Obtain a new certificate from your certification authority before attempting to enable BitLocker.
    //
    FVE_E_POLICY_PROHIBITS_SELFSIGNED = 0x80310086L,

    //
    // MessageId: FVE_E_POLICY_CONFLICT_RO_AND_STARTUP_KEY_REQUIRED
    //
    // MessageText:
    //
    // BitLocker Encryption cannot be applied to this drive because of conflicting Group Policy settings. When write access to drives not protected by BitLocker is denied, the use of a USB startup key cannot be required. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.
    //
    FVE_E_POLICY_CONFLICT_RO_AND_STARTUP_KEY_REQUIRED = 0x80310087L,

    //
    // MessageId: FVE_E_CONV_RECOVERY_FAILED
    //
    // MessageText:
    //
    // BitLocker Drive Encryption failed to recover from an abruptly terminated conversion. This could be due to either all conversion logs being corrupted or the media being write-protected.
    //
    FVE_E_CONV_RECOVERY_FAILED = 0x80310088L,

    //
    // MessageId: FVE_E_VIRTUALIZED_SPACE_TOO_BIG
    //
    // MessageText:
    //
    // The requested virtualization size is too big.
    //
    FVE_E_VIRTUALIZED_SPACE_TOO_BIG = 0x80310089L,

    //
    // MessageId: FVE_E_POLICY_CONFLICT_OSV_RP_OFF_ADB_ON
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on operating system drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.
    //
    FVE_E_POLICY_CONFLICT_OSV_RP_OFF_ADB_ON = 0x80310090L,

    //
    // MessageId: FVE_E_POLICY_CONFLICT_FDV_RP_OFF_ADB_ON
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on fixed data drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.
    //
    FVE_E_POLICY_CONFLICT_FDV_RP_OFF_ADB_ON = 0x80310091L,

    //
    // MessageId: FVE_E_POLICY_CONFLICT_RDV_RP_OFF_ADB_ON
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on removable data drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.
    //
    FVE_E_POLICY_CONFLICT_RDV_RP_OFF_ADB_ON = 0x80310092L,

    //
    // MessageId: FVE_E_NON_BITLOCKER_KU
    //
    // MessageText:
    //
    // The Key Usage (KU) attribute of the specified certificate does not permit it to be used for BitLocker Drive Encryption. BitLocker does not require that a certificate have a KU attribute, but if one is configured it must be set to either Key Encipherment or Key Agreement.
    //
    FVE_E_NON_BITLOCKER_KU = 0x80310093L,

    //
    // MessageId: FVE_E_PRIVATEKEY_AUTH_FAILED
    //
    // MessageText:
    //
    // The private key associated with the specified certificate cannot be authorized. The private key authorization was either not provided or the provided authorization was invalid.
    //
    FVE_E_PRIVATEKEY_AUTH_FAILED = 0x80310094L,

    //
    // MessageId: FVE_E_REMOVAL_OF_DRA_FAILED
    //
    // MessageText:
    //
    // Removal of the data recovery agent certificate must be done using the Certificates snap-in.
    //
    FVE_E_REMOVAL_OF_DRA_FAILED = 0x80310095L,

    //
    // MessageId: FVE_E_OPERATION_NOT_SUPPORTED_ON_VISTA_VOLUME
    //
    // MessageText:
    //
    // This drive was encrypted using the version of BitLocker Drive Encryption included with Windows Vista and Windows Server 2008 which does not support organizational identifiers. To specify organizational identifiers for this drive upgrade the drive encryption to the latest version using the "manage-bde -upgrade" command.
    //
    FVE_E_OPERATION_NOT_SUPPORTED_ON_VISTA_VOLUME = 0x80310096L,

    //
    // MessageId: FVE_E_CANT_LOCK_AUTOUNLOCK_ENABLED_VOLUME
    //
    // MessageText:
    //
    // The drive cannot be locked because it is automatically unlocked on this computer.  Remove the automatic unlock protector to lock this drive.
    //
    FVE_E_CANT_LOCK_AUTOUNLOCK_ENABLED_VOLUME = 0x80310097L,

    //
    // MessageId: FVE_E_FIPS_HASH_KDF_NOT_ALLOWED
    //
    // MessageText:
    //
    // The default BitLocker Key Derivation Function SP800-56A for ECC smart cards is not supported by your smart card. The Group Policy setting requiring FIPS-compliance prevents BitLocker from using any other key derivation function for encryption. You have to use a FIPS compliant smart card in FIPS restricted environments.
    //
    FVE_E_FIPS_HASH_KDF_NOT_ALLOWED = 0x80310098L,

    //
    // MessageId: FVE_E_ENH_PIN_INVALID
    //
    // MessageText:
    //
    // The BitLocker encryption key could not be obtained from the Trusted Platform Module (TPM) and enhanced PIN. Try using a PIN containing only numerals.
    //
    FVE_E_ENH_PIN_INVALID = 0x80310099L,

    //
    // MessageId: FVE_E_INVALID_PIN_CHARS
    //
    // MessageText:
    //
    // The requested TPM PIN contains invalid characters.
    //
    FVE_E_INVALID_PIN_CHARS = 0x8031009AL,

    //
    // MessageId: FVE_E_INVALID_DATUM_TYPE
    //
    // MessageText:
    //
    // The management information stored on the drive contained an unknown type. If you are using an old version of Windows, try accessing the drive from the latest version.
    //
    FVE_E_INVALID_DATUM_TYPE = 0x8031009BL,

    //
    // MessageId: FVE_E_EFI_ONLY
    //
    // MessageText:
    //
    // The feature is only supported on EFI systems.
    //
    FVE_E_EFI_ONLY = 0x8031009CL,

    //
    // MessageId: FVE_E_MULTIPLE_NKP_CERTS
    //
    // MessageText:
    //
    // More than one Network Key Protector certificate has been found on the system.
    //
    FVE_E_MULTIPLE_NKP_CERTS = 0x8031009DL,

    //
    // MessageId: FVE_E_REMOVAL_OF_NKP_FAILED
    //
    // MessageText:
    //
    // Removal of the Network Key Protector certificate must be done using the Certificates snap-in.
    //
    FVE_E_REMOVAL_OF_NKP_FAILED = 0x8031009EL,

    //
    // MessageId: FVE_E_INVALID_NKP_CERT
    //
    // MessageText:
    //
    // An invalid certificate has been found in the Network Key Protector certificate store.
    //
    FVE_E_INVALID_NKP_CERT = 0x8031009FL,

    //
    // MessageId: FVE_E_NO_EXISTING_PIN
    //
    // MessageText:
    //
    // This drive isn't protected with a PIN.
    //
    FVE_E_NO_EXISTING_PIN = 0x803100A0L,

    //
    // MessageId: FVE_E_PROTECTOR_CHANGE_PIN_MISMATCH
    //
    // MessageText:
    //
    // Please enter the correct current PIN.
    //
    FVE_E_PROTECTOR_CHANGE_PIN_MISMATCH = 0x803100A1L,

    //
    // MessageId: FVE_E_PIN_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED
    //
    // MessageText:
    //
    // You must be logged on with an administrator account to change the PIN. Click the link to reset the PIN as an administrator.
    //
    FVE_E_PIN_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED = 0x803100A2L,

    //
    // MessageId: FVE_E_PROTECTOR_CHANGE_MAX_PIN_CHANGE_ATTEMPTS_REACHED
    //
    // MessageText:
    //
    // BitLocker has disabled PIN changes after too many failed requests. Click the link to reset the PIN as an administrator.
    //
    FVE_E_PROTECTOR_CHANGE_MAX_PIN_CHANGE_ATTEMPTS_REACHED = 0x803100A3L,

    //
    // MessageId: FVE_E_POLICY_PASSPHRASE_REQUIRES_ASCII
    //
    // MessageText:
    //
    // Your system administrator requires that passwords contain only printable ASCII characters. This includes unaccented letters (A-Z, a-z), numbers (0-9), space, arithmetic signs, common punctuation, separators, and the following symbols: # $ & @ ^ _ ~ .
    //
    FVE_E_POLICY_PASSPHRASE_REQUIRES_ASCII = 0x803100A4L,

    //
    // MessageId: FVE_E_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE
    //
    // MessageText:
    //
    // BitLocker Drive Encryption only supports Used Space Only encryption on thin provisioned storage.
    //
    FVE_E_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE = 0x803100A5L,

    //
    // MessageId: FVE_E_WIPE_NOT_ALLOWED_ON_TP_STORAGE
    //
    // MessageText:
    //
    // BitLocker Drive Encryption does not support wiping free space on thin provisioned storage.
    //
    FVE_E_WIPE_NOT_ALLOWED_ON_TP_STORAGE = 0x803100A6L,

    //
    // MessageId: FVE_E_KEY_LENGTH_NOT_SUPPORTED_BY_EDRIVE
    //
    // MessageText:
    //
    // The required authentication key length is not supported by the drive.
    //
    FVE_E_KEY_LENGTH_NOT_SUPPORTED_BY_EDRIVE = 0x803100A7L,

    //
    // MessageId: FVE_E_NO_EXISTING_PASSPHRASE
    //
    // MessageText:
    //
    // This drive isn't protected with a password.
    //
    FVE_E_NO_EXISTING_PASSPHRASE = 0x803100A8L,

    //
    // MessageId: FVE_E_PROTECTOR_CHANGE_PASSPHRASE_MISMATCH
    //
    // MessageText:
    //
    // Please enter the correct current password.
    //
    FVE_E_PROTECTOR_CHANGE_PASSPHRASE_MISMATCH = 0x803100A9L,

    //
    // MessageId: FVE_E_PASSPHRASE_TOO_LONG
    //
    // MessageText:
    //
    // The password cannot exceed 256 characters.
    //
    FVE_E_PASSPHRASE_TOO_LONG = 0x803100AAL,

    //
    // MessageId: FVE_E_NO_PASSPHRASE_WITH_TPM
    //
    // MessageText:
    //
    // A password key protector cannot be added because a TPM protector exists on the drive.
    //
    FVE_E_NO_PASSPHRASE_WITH_TPM = 0x803100ABL,

    //
    // MessageId: FVE_E_NO_TPM_WITH_PASSPHRASE
    //
    // MessageText:
    //
    // A TPM key protector cannot be added because a password protector exists on the drive.
    //
    FVE_E_NO_TPM_WITH_PASSPHRASE = 0x803100ACL,

    //
    // MessageId: FVE_E_NOT_ALLOWED_ON_CSV_STACK
    //
    // MessageText:
    //
    // This command can only be performed from the coordinator node for the specified CSV volume.
    //
    FVE_E_NOT_ALLOWED_ON_CSV_STACK = 0x803100ADL,

    //
    // MessageId: FVE_E_NOT_ALLOWED_ON_CLUSTER
    //
    // MessageText:
    //
    // This command cannot be performed on a volume when it is part of a cluster.
    //
    FVE_E_NOT_ALLOWED_ON_CLUSTER = 0x803100AEL,

    //
    // MessageId: FVE_E_EDRIVE_NO_FAILOVER_TO_SW
    //
    // MessageText:
    //
    // BitLocker did not revert to using BitLocker software encryption due to group policy configuration.
    //
    FVE_E_EDRIVE_NO_FAILOVER_TO_SW = 0x803100AFL,

    //
    // MessageId: FVE_E_EDRIVE_BAND_IN_USE
    //
    // MessageText:
    //
    // The drive cannot be managed by BitLocker because the drive's hardware encryption feature is already in use.
    //
    FVE_E_EDRIVE_BAND_IN_USE = 0x803100B0L,

    //
    // MessageId: FVE_E_EDRIVE_DISALLOWED_BY_GP
    //
    // MessageText:
    //
    // Group Policy settings do not allow the use of hardware-based encryption.
    //
    FVE_E_EDRIVE_DISALLOWED_BY_GP = 0x803100B1L,

    //
    // MessageId: FVE_E_EDRIVE_INCOMPATIBLE_VOLUME
    //
    // MessageText:
    //
    // The drive specified does not support hardware-based encryption.
    //
    FVE_E_EDRIVE_INCOMPATIBLE_VOLUME = 0x803100B2L,

    //
    // MessageId: FVE_E_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING
    //
    // MessageText:
    //
    // BitLocker cannot be upgraded during disk encryption or decryption.
    //
    FVE_E_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING = 0x803100B3L,

    //
    // MessageId: FVE_E_EDRIVE_DV_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Discovery Volumes are not supported for volumes using hardware encryption.
    //
    FVE_E_EDRIVE_DV_NOT_SUPPORTED = 0x803100B4L,

    //
    // MessageId: FVE_E_NO_PREBOOT_KEYBOARD_DETECTED
    //
    // MessageText:
    //
    // No pre-boot keyboard detected. The user may not be able to provide required input to unlock the volume.
    //
    FVE_E_NO_PREBOOT_KEYBOARD_DETECTED = 0x803100B5L,

    //
    // MessageId: FVE_E_NO_PREBOOT_KEYBOARD_OR_WINRE_DETECTED
    //
    // MessageText:
    //
    // No pre-boot keyboard or Windows Recovery Environment detected. The user may not be able to provide required input to unlock the volume.
    //
    FVE_E_NO_PREBOOT_KEYBOARD_OR_WINRE_DETECTED = 0x803100B6L,

    //
    // MessageId: FVE_E_POLICY_REQUIRES_STARTUP_PIN_ON_TOUCH_DEVICE
    //
    // MessageText:
    //
    // Group Policy settings require the creation of a startup PIN, but a pre-boot keyboard is not available on this device. The user may not be able to provide required input to unlock the volume.
    //
    FVE_E_POLICY_REQUIRES_STARTUP_PIN_ON_TOUCH_DEVICE = 0x803100B7L,

    //
    // MessageId: FVE_E_POLICY_REQUIRES_RECOVERY_PASSWORD_ON_TOUCH_DEVICE
    //
    // MessageText:
    //
    // Group Policy settings require the creation of a recovery password, but neither a pre-boot keyboard nor Windows Recovery Environment is available on this device. The user may not be able to provide required input to unlock the volume.
    //
    FVE_E_POLICY_REQUIRES_RECOVERY_PASSWORD_ON_TOUCH_DEVICE = 0x803100B8L,

    //
    // MessageId: FVE_E_WIPE_CANCEL_NOT_APPLICABLE
    //
    // MessageText:
    //
    // Wipe of free space is not currently taking place.
    //
    FVE_E_WIPE_CANCEL_NOT_APPLICABLE = 0x803100B9L,

    //
    // MessageId: FVE_E_SECUREBOOT_DISABLED
    //
    // MessageText:
    //
    // BitLocker cannot use Secure Boot for platform integrity because Secure Boot has been disabled.
    //
    FVE_E_SECUREBOOT_DISABLED = 0x803100BAL,

    //
    // MessageId: FVE_E_SECUREBOOT_CONFIGURATION_INVALID
    //
    // MessageText:
    //
    // BitLocker cannot use Secure Boot for platform integrity because the Secure Boot configuration does not meet the requirements for BitLocker.
    //
    FVE_E_SECUREBOOT_CONFIGURATION_INVALID = 0x803100BBL,

    //
    // MessageId: FVE_E_EDRIVE_DRY_RUN_FAILED
    //
    // MessageText:
    //
    // Your computer doesn't support BitLocker hardware-based encryption. Check with your computer manufacturer for firmware updates.
    //
    FVE_E_EDRIVE_DRY_RUN_FAILED = 0x803100BCL,

    //
    // MessageId: FVE_E_SHADOW_COPY_PRESENT
    //
    // MessageText:
    //
    // BitLocker cannot be enabled on the volume because it contains a Volume Shadow Copy. Remove all Volume Shadow Copies before encrypting the volume.
    //
    FVE_E_SHADOW_COPY_PRESENT = 0x803100BDL,

    //
    // MessageId: FVE_E_POLICY_INVALID_ENHANCED_BCD_SETTINGS
    //
    // MessageText:
    //
    // BitLocker Drive Encryption cannot be applied to this drive because the Group Policy setting for Enhanced Boot Configuration Data contains invalid data. Please have your system administrator resolve this invalid configuration before attempting to enable BitLocker.
    //
    FVE_E_POLICY_INVALID_ENHANCED_BCD_SETTINGS = 0x803100BEL,

    //
    // MessageId: FVE_E_EDRIVE_INCOMPATIBLE_FIRMWARE
    //
    // MessageText:
    //
    // This PC's firmware is not capable of supporting hardware encryption.
    //
    FVE_E_EDRIVE_INCOMPATIBLE_FIRMWARE = 0x803100BFL,

    //
    // MessageId: FVE_E_PROTECTOR_CHANGE_MAX_PASSPHRASE_CHANGE_ATTEMPTS_REACHED
    //
    // MessageText:
    //
    // BitLocker has disabled password changes after too many failed requests. Click the link to reset the password as an administrator.
    //
    FVE_E_PROTECTOR_CHANGE_MAX_PASSPHRASE_CHANGE_ATTEMPTS_REACHED = 0x803100C0L,

    //
    // MessageId: FVE_E_PASSPHRASE_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED
    //
    // MessageText:
    //
    // You must be logged on with an administrator account to change the password. Click the link to reset the password as an administrator.
    //
    FVE_E_PASSPHRASE_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED = 0x803100C1L,

    //
    // MessageId: FVE_E_LIVEID_ACCOUNT_SUSPENDED
    //
    // MessageText:
    //
    // BitLocker cannot save the recovery password because the specified Microsoft account is Suspended.
    //
    FVE_E_LIVEID_ACCOUNT_SUSPENDED = 0x803100C2L,

    //
    // MessageId: FVE_E_LIVEID_ACCOUNT_BLOCKED
    //
    // MessageText:
    //
    // BitLocker cannot save the recovery password because the specified Microsoft account is Blocked.
    //
    FVE_E_LIVEID_ACCOUNT_BLOCKED = 0x803100C3L,

    //
    // MessageId: FVE_E_NOT_PROVISIONED_ON_ALL_VOLUMES
    //
    // MessageText:
    //
    // This PC is not provisioned to support device encryption. Please enable BitLocker on all volumes to comply with device encryption policy.
    //
    FVE_E_NOT_PROVISIONED_ON_ALL_VOLUMES = 0x803100C4L,

    //
    // MessageId: FVE_E_DE_FIXED_DATA_NOT_SUPPORTED
    //
    // MessageText:
    //
    // This PC cannot support device encryption because unencrypted fixed data volumes are present.
    //
    FVE_E_DE_FIXED_DATA_NOT_SUPPORTED = 0x803100C5L,

    //
    // MessageId: FVE_E_DE_HARDWARE_NOT_COMPLIANT
    //
    // MessageText:
    //
    // This PC does not meet the hardware requirements to support device encryption.
    //
    FVE_E_DE_HARDWARE_NOT_COMPLIANT = 0x803100C6L,

    //
    // MessageId: FVE_E_DE_WINRE_NOT_CONFIGURED
    //
    // MessageText:
    //
    // This PC cannot support device encryption because WinRE is not properly configured.
    //
    FVE_E_DE_WINRE_NOT_CONFIGURED = 0x803100C7L,

    //
    // MessageId: FVE_E_DE_PROTECTION_SUSPENDED
    //
    // MessageText:
    //
    // Protection is enabled on the volume but has been suspended. This is likely to have happened due to an update being applied to your system. Please try again after a reboot.
    //
    FVE_E_DE_PROTECTION_SUSPENDED = 0x803100C8L,

    //
    // MessageId: FVE_E_DE_OS_VOLUME_NOT_PROTECTED
    //
    // MessageText:
    //
    // This PC is not provisioned to support device encryption.
    //
    FVE_E_DE_OS_VOLUME_NOT_PROTECTED = 0x803100C9L,

    //
    // MessageId: FVE_E_DE_DEVICE_LOCKEDOUT
    //
    // MessageText:
    //
    // Device Lock has been triggered due to too many incorrect password attempts.
    //
    FVE_E_DE_DEVICE_LOCKEDOUT = 0x803100CAL,

    //
    // MessageId: FVE_E_DE_PROTECTION_NOT_YET_ENABLED
    //
    // MessageText:
    //
    // Protection has not been enabled on the volume. Enabling protection requires a connected account. If you already have a connected account and are seeing this error, please refer to the event log for more information.
    //
    FVE_E_DE_PROTECTION_NOT_YET_ENABLED = 0x803100CBL,

    //
    // MessageId: FVE_E_INVALID_PIN_CHARS_DETAILED
    //
    // MessageText:
    //
    // Your PIN can only contain numbers from 0 to 9.
    //
    FVE_E_INVALID_PIN_CHARS_DETAILED = 0x803100CCL,

    //
    // MessageId: FVE_E_DEVICE_LOCKOUT_COUNTER_UNAVAILABLE
    //
    // MessageText:
    //
    // BitLocker cannot use hardware replay protection because no counter is available on your PC.
    //
    FVE_E_DEVICE_LOCKOUT_COUNTER_UNAVAILABLE = 0x803100CDL,

    //
    // MessageId: FVE_E_DEVICELOCKOUT_COUNTER_MISMATCH
    //
    // MessageText:
    //
    // Device Lockout state validation failed due to counter mismatch.
    //
    FVE_E_DEVICELOCKOUT_COUNTER_MISMATCH = 0x803100CEL,

    //
    // MessageId: FVE_E_BUFFER_TOO_LARGE
    //
    // MessageText:
    //
    // The input buffer is too large.
    //
    FVE_E_BUFFER_TOO_LARGE = 0x803100CFL,

    //
    // MessageId: FVE_E_NO_SUCH_CAPABILITY_ON_TARGET
    //
    // MessageText:
    //
    // The target of an invocation does not support requested capability.
    //
    FVE_E_NO_SUCH_CAPABILITY_ON_TARGET = 0x803100D0L,

    //
    // MessageId: FVE_E_DE_PREVENTED_FOR_OS
    //
    // MessageText:
    //
    // Device encryption is currently blocked by this PC's configuration.
    //
    FVE_E_DE_PREVENTED_FOR_OS = 0x803100D1L,

    //
    // MessageId: FVE_E_DE_VOLUME_OPTED_OUT
    //
    // MessageText:
    //
    // This drive has been opted out of device encryption.
    //
    FVE_E_DE_VOLUME_OPTED_OUT = 0x803100D2L,

    //
    // MessageId: FVE_E_DE_VOLUME_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Device encryption isn't available for this drive.
    //
    FVE_E_DE_VOLUME_NOT_SUPPORTED = 0x803100D3L,

    //
    // MessageId: FVE_E_EOW_NOT_SUPPORTED_IN_VERSION
    //
    // MessageText:
    //
    // The encrypt on write mode for BitLocker is not supported in this version of Windows. You can turn on BitLocker without using the encrypt on write mode.
    //
    FVE_E_EOW_NOT_SUPPORTED_IN_VERSION = 0x803100D4L,

    //
    // MessageId: FVE_E_ADBACKUP_NOT_ENABLED
    //
    // MessageText:
    //
    // Group policy prevents you from backing up your recovery password to Active Directory for this drive type. For more info, contact your system administrator.
    //
    FVE_E_ADBACKUP_NOT_ENABLED = 0x803100D5L,

    //
    // MessageId: FVE_E_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT
    //
    // MessageText:
    //
    // Device encryption can't be turned off while this drive is being encrypted. Please try again later.
    //
    FVE_E_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT = 0x803100D6L,

    //
    // MessageId: FVE_E_NOT_DE_VOLUME
    //
    // MessageText:
    //
    // This action isn't supported because this drive isn't automatically managed with device encryption.
    //
    FVE_E_NOT_DE_VOLUME = 0x803100D7L,

    //
    // MessageId: FVE_E_PROTECTION_CANNOT_BE_DISABLED
    //
    // MessageText:
    //
    // BitLocker can't be suspended on this drive until the next restart.
    //
    FVE_E_PROTECTION_CANNOT_BE_DISABLED = 0x803100D8L,

    //
    // =======================================================
    // Windows Filtering Platform Error Messages
    // =======================================================
    //
    //
    // MessageId: FWP_E_CALLOUT_NOT_FOUND
    //
    // MessageText:
    //
    // The callout does not exist.
    //
    FWP_E_CALLOUT_NOT_FOUND = 0x80320001L,

    //
    // MessageId: FWP_E_CONDITION_NOT_FOUND
    //
    // MessageText:
    //
    // The filter condition does not exist.
    //
    FWP_E_CONDITION_NOT_FOUND = 0x80320002L,

    //
    // MessageId: FWP_E_FILTER_NOT_FOUND
    //
    // MessageText:
    //
    // The filter does not exist.
    //
    FWP_E_FILTER_NOT_FOUND = 0x80320003L,

    //
    // MessageId: FWP_E_LAYER_NOT_FOUND
    //
    // MessageText:
    //
    // The layer does not exist.
    //
    FWP_E_LAYER_NOT_FOUND = 0x80320004L,

    //
    // MessageId: FWP_E_PROVIDER_NOT_FOUND
    //
    // MessageText:
    //
    // The provider does not exist.
    //
    FWP_E_PROVIDER_NOT_FOUND = 0x80320005L,

    //
    // MessageId: FWP_E_PROVIDER_CONTEXT_NOT_FOUND
    //
    // MessageText:
    //
    // The provider context does not exist.
    //
    FWP_E_PROVIDER_CONTEXT_NOT_FOUND = 0x80320006L,

    //
    // MessageId: FWP_E_SUBLAYER_NOT_FOUND
    //
    // MessageText:
    //
    // The sublayer does not exist.
    //
    FWP_E_SUBLAYER_NOT_FOUND = 0x80320007L,

    //
    // MessageId: FWP_E_NOT_FOUND
    //
    // MessageText:
    //
    // The object does not exist.
    //
    FWP_E_NOT_FOUND = 0x80320008L,

    //
    // MessageId: FWP_E_ALREADY_EXISTS
    //
    // MessageText:
    //
    // An object with that GUID or LUID already exists.
    //
    FWP_E_ALREADY_EXISTS = 0x80320009L,

    //
    // MessageId: FWP_E_IN_USE
    //
    // MessageText:
    //
    // The object is referenced by other objects so cannot be deleted.
    //
    FWP_E_IN_USE = 0x8032000AL,

    //
    // MessageId: FWP_E_DYNAMIC_SESSION_IN_PROGRESS
    //
    // MessageText:
    //
    // The call is not allowed from within a dynamic session.
    //
    FWP_E_DYNAMIC_SESSION_IN_PROGRESS = 0x8032000BL,

    //
    // MessageId: FWP_E_WRONG_SESSION
    //
    // MessageText:
    //
    // The call was made from the wrong session so cannot be completed.
    //
    FWP_E_WRONG_SESSION = 0x8032000CL,

    //
    // MessageId: FWP_E_NO_TXN_IN_PROGRESS
    //
    // MessageText:
    //
    // The call must be made from within an explicit transaction.
    //
    FWP_E_NO_TXN_IN_PROGRESS = 0x8032000DL,

    //
    // MessageId: FWP_E_TXN_IN_PROGRESS
    //
    // MessageText:
    //
    // The call is not allowed from within an explicit transaction.
    //
    FWP_E_TXN_IN_PROGRESS = 0x8032000EL,

    //
    // MessageId: FWP_E_TXN_ABORTED
    //
    // MessageText:
    //
    // The explicit transaction has been forcibly cancelled.
    //
    FWP_E_TXN_ABORTED = 0x8032000FL,

    //
    // MessageId: FWP_E_SESSION_ABORTED
    //
    // MessageText:
    //
    // The session has been cancelled.
    //
    FWP_E_SESSION_ABORTED = 0x80320010L,

    //
    // MessageId: FWP_E_INCOMPATIBLE_TXN
    //
    // MessageText:
    //
    // The call is not allowed from within a read-only transaction.
    //
    FWP_E_INCOMPATIBLE_TXN = 0x80320011L,

    //
    // MessageId: FWP_E_TIMEOUT
    //
    // MessageText:
    //
    // The call timed out while waiting to acquire the transaction lock.
    //
    FWP_E_TIMEOUT = 0x80320012L,

    //
    // MessageId: FWP_E_NET_EVENTS_DISABLED
    //
    // MessageText:
    //
    // Collection of network diagnostic events is disabled.
    //
    FWP_E_NET_EVENTS_DISABLED = 0x80320013L,

    //
    // MessageId: FWP_E_INCOMPATIBLE_LAYER
    //
    // MessageText:
    //
    // The operation is not supported by the specified layer.
    //
    FWP_E_INCOMPATIBLE_LAYER = 0x80320014L,

    //
    // MessageId: FWP_E_KM_CLIENTS_ONLY
    //
    // MessageText:
    //
    // The call is allowed for kernel-mode callers only.
    //
    FWP_E_KM_CLIENTS_ONLY = 0x80320015L,

    //
    // MessageId: FWP_E_LIFETIME_MISMATCH
    //
    // MessageText:
    //
    // The call tried to associate two objects with incompatible lifetimes.
    //
    FWP_E_LIFETIME_MISMATCH = 0x80320016L,

    //
    // MessageId: FWP_E_BUILTIN_OBJECT
    //
    // MessageText:
    //
    // The object is built in so cannot be deleted.
    //
    FWP_E_BUILTIN_OBJECT = 0x80320017L,

    //
    // MessageId: FWP_E_TOO_MANY_CALLOUTS
    //
    // MessageText:
    //
    // The maximum number of callouts has been reached.
    //
    FWP_E_TOO_MANY_CALLOUTS = 0x80320018L,

    //
    // MessageId: FWP_E_NOTIFICATION_DROPPED
    //
    // MessageText:
    //
    // A notification could not be delivered because a message queue is at its maximum capacity.
    //
    FWP_E_NOTIFICATION_DROPPED = 0x80320019L,

    //
    // MessageId: FWP_E_TRAFFIC_MISMATCH
    //
    // MessageText:
    //
    // The traffic parameters do not match those for the security association context.
    //
    FWP_E_TRAFFIC_MISMATCH = 0x8032001AL,

    //
    // MessageId: FWP_E_INCOMPATIBLE_SA_STATE
    //
    // MessageText:
    //
    // The call is not allowed for the current security association state.
    //
    FWP_E_INCOMPATIBLE_SA_STATE = 0x8032001BL,

    //
    // MessageId: FWP_E_NULL_POINTER
    //
    // MessageText:
    //
    // A required pointer is null.
    //
    FWP_E_NULL_POINTER = 0x8032001CL,

    //
    // MessageId: FWP_E_INVALID_ENUMERATOR
    //
    // MessageText:
    //
    // An enumerator is not valid.
    //
    FWP_E_INVALID_ENUMERATOR = 0x8032001DL,

    //
    // MessageId: FWP_E_INVALID_FLAGS
    //
    // MessageText:
    //
    // The flags field contains an invalid value.
    //
    FWP_E_INVALID_FLAGS = 0x8032001EL,

    //
    // MessageId: FWP_E_INVALID_NET_MASK
    //
    // MessageText:
    //
    // A network mask is not valid.
    //
    FWP_E_INVALID_NET_MASK = 0x8032001FL,

    //
    // MessageId: FWP_E_INVALID_RANGE
    //
    // MessageText:
    //
    // An FWP_RANGE is not valid.
    //
    FWP_E_INVALID_RANGE = 0x80320020L,

    //
    // MessageId: FWP_E_INVALID_INTERVAL
    //
    // MessageText:
    //
    // The time interval is not valid.
    //
    FWP_E_INVALID_INTERVAL = 0x80320021L,

    //
    // MessageId: FWP_E_ZERO_LENGTH_ARRAY
    //
    // MessageText:
    //
    // An array that must contain at least one element is zero length.
    //
    FWP_E_ZERO_LENGTH_ARRAY = 0x80320022L,

    //
    // MessageId: FWP_E_NULL_DISPLAY_NAME
    //
    // MessageText:
    //
    // The displayData.name field cannot be null.
    //
    FWP_E_NULL_DISPLAY_NAME = 0x80320023L,

    //
    // MessageId: FWP_E_INVALID_ACTION_TYPE
    //
    // MessageText:
    //
    // The action type is not one of the allowed action types for a filter.
    //
    FWP_E_INVALID_ACTION_TYPE = 0x80320024L,

    //
    // MessageId: FWP_E_INVALID_WEIGHT
    //
    // MessageText:
    //
    // The filter weight is not valid.
    //
    FWP_E_INVALID_WEIGHT = 0x80320025L,

    //
    // MessageId: FWP_E_MATCH_TYPE_MISMATCH
    //
    // MessageText:
    //
    // A filter condition contains a match type that is not compatible with the operands.
    //
    FWP_E_MATCH_TYPE_MISMATCH = 0x80320026L,

    //
    // MessageId: FWP_E_TYPE_MISMATCH
    //
    // MessageText:
    //
    // An FWP_VALUE or FWPM_CONDITION_VALUE is of the wrong type.
    //
    FWP_E_TYPE_MISMATCH = 0x80320027L,

    //
    // MessageId: FWP_E_OUT_OF_BOUNDS
    //
    // MessageText:
    //
    // An integer value is outside the allowed range.
    //
    FWP_E_OUT_OF_BOUNDS = 0x80320028L,

    //
    // MessageId: FWP_E_RESERVED
    //
    // MessageText:
    //
    // A reserved field is non-zero.
    //
    FWP_E_RESERVED = 0x80320029L,

    //
    // MessageId: FWP_E_DUPLICATE_CONDITION
    //
    // MessageText:
    //
    // A filter cannot contain multiple conditions operating on a single field.
    //
    FWP_E_DUPLICATE_CONDITION = 0x8032002AL,

    //
    // MessageId: FWP_E_DUPLICATE_KEYMOD
    //
    // MessageText:
    //
    // A policy cannot contain the same keying module more than once.
    //
    FWP_E_DUPLICATE_KEYMOD = 0x8032002BL,

    //
    // MessageId: FWP_E_ACTION_INCOMPATIBLE_WITH_LAYER
    //
    // MessageText:
    //
    // The action type is not compatible with the layer.
    //
    FWP_E_ACTION_INCOMPATIBLE_WITH_LAYER = 0x8032002CL,

    //
    // MessageId: FWP_E_ACTION_INCOMPATIBLE_WITH_SUBLAYER
    //
    // MessageText:
    //
    // The action type is not compatible with the sublayer.
    //
    FWP_E_ACTION_INCOMPATIBLE_WITH_SUBLAYER = 0x8032002DL,

    //
    // MessageId: FWP_E_CONTEXT_INCOMPATIBLE_WITH_LAYER
    //
    // MessageText:
    //
    // The raw context or the provider context is not compatible with the layer.
    //
    FWP_E_CONTEXT_INCOMPATIBLE_WITH_LAYER = 0x8032002EL,

    //
    // MessageId: FWP_E_CONTEXT_INCOMPATIBLE_WITH_CALLOUT
    //
    // MessageText:
    //
    // The raw context or the provider context is not compatible with the callout.
    //
    FWP_E_CONTEXT_INCOMPATIBLE_WITH_CALLOUT = 0x8032002FL,

    //
    // MessageId: FWP_E_INCOMPATIBLE_AUTH_METHOD
    //
    // MessageText:
    //
    // The authentication method is not compatible with the policy type.
    //
    FWP_E_INCOMPATIBLE_AUTH_METHOD = 0x80320030L,

    //
    // MessageId: FWP_E_INCOMPATIBLE_DH_GROUP
    //
    // MessageText:
    //
    // The Diffie-Hellman group is not compatible with the policy type.
    //
    FWP_E_INCOMPATIBLE_DH_GROUP = 0x80320031L,

    //
    // MessageId: FWP_E_EM_NOT_SUPPORTED
    //
    // MessageText:
    //
    // An IKE policy cannot contain an Extended Mode policy.
    //
    FWP_E_EM_NOT_SUPPORTED = 0x80320032L,

    //
    // MessageId: FWP_E_NEVER_MATCH
    //
    // MessageText:
    //
    // The enumeration template or subscription will never match any objects.
    //
    FWP_E_NEVER_MATCH = 0x80320033L,

    //
    // MessageId: FWP_E_PROVIDER_CONTEXT_MISMATCH
    //
    // MessageText:
    //
    // The provider context is of the wrong type.
    //
    FWP_E_PROVIDER_CONTEXT_MISMATCH = 0x80320034L,

    //
    // MessageId: FWP_E_INVALID_PARAMETER
    //
    // MessageText:
    //
    // The parameter is incorrect.
    //
    FWP_E_INVALID_PARAMETER = 0x80320035L,

    //
    // MessageId: FWP_E_TOO_MANY_SUBLAYERS
    //
    // MessageText:
    //
    // The maximum number of sublayers has been reached.
    //
    FWP_E_TOO_MANY_SUBLAYERS = 0x80320036L,

    //
    // MessageId: FWP_E_CALLOUT_NOTIFICATION_FAILED
    //
    // MessageText:
    //
    // The notification function for a callout returned an error.
    //
    FWP_E_CALLOUT_NOTIFICATION_FAILED = 0x80320037L,

    //
    // MessageId: FWP_E_INVALID_AUTH_TRANSFORM
    //
    // MessageText:
    //
    // The IPsec authentication transform is not valid.
    //
    FWP_E_INVALID_AUTH_TRANSFORM = 0x80320038L,

    //
    // MessageId: FWP_E_INVALID_CIPHER_TRANSFORM
    //
    // MessageText:
    //
    // The IPsec cipher transform is not valid.
    //
    FWP_E_INVALID_CIPHER_TRANSFORM = 0x80320039L,

    //
    // MessageId: FWP_E_INCOMPATIBLE_CIPHER_TRANSFORM
    //
    // MessageText:
    //
    // The IPsec cipher transform is not compatible with the policy.
    //
    FWP_E_INCOMPATIBLE_CIPHER_TRANSFORM = 0x8032003AL,

    //
    // MessageId: FWP_E_INVALID_TRANSFORM_COMBINATION
    //
    // MessageText:
    //
    // The combination of IPsec transform types is not valid.
    //
    FWP_E_INVALID_TRANSFORM_COMBINATION = 0x8032003BL,

    //
    // MessageId: FWP_E_DUPLICATE_AUTH_METHOD
    //
    // MessageText:
    //
    // A policy cannot contain the same auth method more than once.
    //
    FWP_E_DUPLICATE_AUTH_METHOD = 0x8032003CL,

    //
    // MessageId: FWP_E_INVALID_TUNNEL_ENDPOINT
    //
    // MessageText:
    //
    // A tunnel endpoint configuration is invalid.
    //
    FWP_E_INVALID_TUNNEL_ENDPOINT = 0x8032003DL,

    //
    // MessageId: FWP_E_L2_DRIVER_NOT_READY
    //
    // MessageText:
    //
    // The WFP MAC Layers are not ready.
    //
    FWP_E_L2_DRIVER_NOT_READY = 0x8032003EL,

    //
    // MessageId: FWP_E_KEY_DICTATOR_ALREADY_REGISTERED
    //
    // MessageText:
    //
    // A key manager capable of key dictation is already registered
    //
    FWP_E_KEY_DICTATOR_ALREADY_REGISTERED = 0x8032003FL,

    //
    // MessageId: FWP_E_KEY_DICTATION_INVALID_KEYING_MATERIAL
    //
    // MessageText:
    //
    // A key manager dictated invalid keys
    //
    FWP_E_KEY_DICTATION_INVALID_KEYING_MATERIAL = 0x80320040L,

    //
    // MessageId: FWP_E_CONNECTIONS_DISABLED
    //
    // MessageText:
    //
    // The BFE IPsec Connection Tracking is disabled.
    //
    FWP_E_CONNECTIONS_DISABLED = 0x80320041L,

    //
    // MessageId: FWP_E_INVALID_DNS_NAME
    //
    // MessageText:
    //
    // The DNS name is invalid.
    //
    FWP_E_INVALID_DNS_NAME = 0x80320042L,

    //
    // MessageId: FWP_E_STILL_ON
    //
    // MessageText:
    //
    // The engine option is still enabled due to other configuration settings.
    //
    FWP_E_STILL_ON = 0x80320043L,

    //
    // MessageId: FWP_E_IKEEXT_NOT_RUNNING
    //
    // MessageText:
    //
    // The IKEEXT service is not running.  This service only runs when there is IPsec policy applied to the machine.
    //
    FWP_E_IKEEXT_NOT_RUNNING = 0x80320044L,

    //
    // MessageId: FWP_E_DROP_NOICMP
    //
    // MessageText:
    //
    // The packet should be dropped, no ICMP should be sent.
    //
    FWP_E_DROP_NOICMP = 0x80320104L,

    ///////////////////////////////////////////////////
    //                                               //
    //       Web Services Platform Error Codes       //
    //                                               //
    ///////////////////////////////////////////////////

    //
    // MessageId: WS_S_ASYNC
    //
    // MessageText:
    //
    // The function call is completing asynchronously.
    //
    WS_S_ASYNC = 0x003D0000L,

    //
    // MessageId: WS_S_END
    //
    // MessageText:
    //
    // There are no more messages available on the channel.
    //
    WS_S_END = 0x003D0001L,

    //
    // MessageId: WS_E_INVALID_FORMAT
    //
    // MessageText:
    //
    // The input data was not in the expected format or did not have the expected value.
    //
    WS_E_INVALID_FORMAT = 0x803D0000L,

    //
    // MessageId: WS_E_OBJECT_FAULTED
    //
    // MessageText:
    //
    // The operation could not be completed because the object is in a faulted state due to a previous error.
    //
    WS_E_OBJECT_FAULTED = 0x803D0001L,

    //
    // MessageId: WS_E_NUMERIC_OVERFLOW
    //
    // MessageText:
    //
    // The operation could not be completed because it would lead to numeric overflow.
    //
    WS_E_NUMERIC_OVERFLOW = 0x803D0002L,

    //
    // MessageId: WS_E_INVALID_OPERATION
    //
    // MessageText:
    //
    // The operation is not allowed due to the current state of the object.
    //
    WS_E_INVALID_OPERATION = 0x803D0003L,

    //
    // MessageId: WS_E_OPERATION_ABORTED
    //
    // MessageText:
    //
    // The operation was aborted.
    //
    WS_E_OPERATION_ABORTED = 0x803D0004L,

    //
    // MessageId: WS_E_ENDPOINT_ACCESS_DENIED
    //
    // MessageText:
    //
    // Access was denied by the remote endpoint.
    //
    WS_E_ENDPOINT_ACCESS_DENIED = 0x803D0005L,

    //
    // MessageId: WS_E_OPERATION_TIMED_OUT
    //
    // MessageText:
    //
    // The operation did not complete within the time allotted.
    //
    WS_E_OPERATION_TIMED_OUT = 0x803D0006L,

    //
    // MessageId: WS_E_OPERATION_ABANDONED
    //
    // MessageText:
    //
    // The operation was abandoned.
    //
    WS_E_OPERATION_ABANDONED = 0x803D0007L,

    //
    // MessageId: WS_E_QUOTA_EXCEEDED
    //
    // MessageText:
    //
    // A quota was exceeded.
    //
    WS_E_QUOTA_EXCEEDED = 0x803D0008L,

    //
    // MessageId: WS_E_NO_TRANSLATION_AVAILABLE
    //
    // MessageText:
    //
    // The information was not available in the specified language.
    //
    WS_E_NO_TRANSLATION_AVAILABLE = 0x803D0009L,

    //
    // MessageId: WS_E_SECURITY_VERIFICATION_FAILURE
    //
    // MessageText:
    //
    // Security verification was not successful for the received data.
    //
    WS_E_SECURITY_VERIFICATION_FAILURE = 0x803D000AL,

    //
    // MessageId: WS_E_ADDRESS_IN_USE
    //
    // MessageText:
    //
    // The address is already being used.
    //
    WS_E_ADDRESS_IN_USE = 0x803D000BL,

    //
    // MessageId: WS_E_ADDRESS_NOT_AVAILABLE
    //
    // MessageText:
    //
    // The address is not valid for this context.
    //
    WS_E_ADDRESS_NOT_AVAILABLE = 0x803D000CL,

    //
    // MessageId: WS_E_ENDPOINT_NOT_FOUND
    //
    // MessageText:
    //
    // The remote endpoint does not exist or could not be located.
    //
    WS_E_ENDPOINT_NOT_FOUND = 0x803D000DL,

    //
    // MessageId: WS_E_ENDPOINT_NOT_AVAILABLE
    //
    // MessageText:
    //
    // The remote endpoint is not currently in service at this location.
    //
    WS_E_ENDPOINT_NOT_AVAILABLE = 0x803D000EL,

    //
    // MessageId: WS_E_ENDPOINT_FAILURE
    //
    // MessageText:
    //
    // The remote endpoint could not process the request.
    //
    WS_E_ENDPOINT_FAILURE = 0x803D000FL,

    //
    // MessageId: WS_E_ENDPOINT_UNREACHABLE
    //
    // MessageText:
    //
    // The remote endpoint was not reachable.
    //
    WS_E_ENDPOINT_UNREACHABLE = 0x803D0010L,

    //
    // MessageId: WS_E_ENDPOINT_ACTION_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The operation was not supported by the remote endpoint.
    //
    WS_E_ENDPOINT_ACTION_NOT_SUPPORTED = 0x803D0011L,

    //
    // MessageId: WS_E_ENDPOINT_TOO_BUSY
    //
    // MessageText:
    //
    // The remote endpoint is unable to process the request due to being overloaded.
    //
    WS_E_ENDPOINT_TOO_BUSY = 0x803D0012L,

    //
    // MessageId: WS_E_ENDPOINT_FAULT_RECEIVED
    //
    // MessageText:
    //
    // A message containing a fault was received from the remote endpoint.
    //
    WS_E_ENDPOINT_FAULT_RECEIVED = 0x803D0013L,

    //
    // MessageId: WS_E_ENDPOINT_DISCONNECTED
    //
    // MessageText:
    //
    // The connection with the remote endpoint was terminated.
    //
    WS_E_ENDPOINT_DISCONNECTED = 0x803D0014L,

    //
    // MessageId: WS_E_PROXY_FAILURE
    //
    // MessageText:
    //
    // The HTTP proxy server could not process the request.
    //
    WS_E_PROXY_FAILURE = 0x803D0015L,

    //
    // MessageId: WS_E_PROXY_ACCESS_DENIED
    //
    // MessageText:
    //
    // Access was denied by the HTTP proxy server.
    //
    WS_E_PROXY_ACCESS_DENIED = 0x803D0016L,

    //
    // MessageId: WS_E_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The requested feature is not available on this platform.
    //
    WS_E_NOT_SUPPORTED = 0x803D0017L,

    //
    // MessageId: WS_E_PROXY_REQUIRES_BASIC_AUTH
    //
    // MessageText:
    //
    // The HTTP proxy server requires HTTP authentication scheme 'basic'.
    //
    WS_E_PROXY_REQUIRES_BASIC_AUTH = 0x803D0018L,

    //
    // MessageId: WS_E_PROXY_REQUIRES_DIGEST_AUTH
    //
    // MessageText:
    //
    // The HTTP proxy server requires HTTP authentication scheme 'digest'.
    //
    WS_E_PROXY_REQUIRES_DIGEST_AUTH = 0x803D0019L,

    //
    // MessageId: WS_E_PROXY_REQUIRES_NTLM_AUTH
    //
    // MessageText:
    //
    // The HTTP proxy server requires HTTP authentication scheme 'NTLM'.
    //
    WS_E_PROXY_REQUIRES_NTLM_AUTH = 0x803D001AL,

    //
    // MessageId: WS_E_PROXY_REQUIRES_NEGOTIATE_AUTH
    //
    // MessageText:
    //
    // The HTTP proxy server requires HTTP authentication scheme 'negotiate'.
    //
    WS_E_PROXY_REQUIRES_NEGOTIATE_AUTH = 0x803D001BL,

    //
    // MessageId: WS_E_SERVER_REQUIRES_BASIC_AUTH
    //
    // MessageText:
    //
    // The remote endpoint requires HTTP authentication scheme 'basic'.
    //
    WS_E_SERVER_REQUIRES_BASIC_AUTH = 0x803D001CL,

    //
    // MessageId: WS_E_SERVER_REQUIRES_DIGEST_AUTH
    //
    // MessageText:
    //
    // The remote endpoint requires HTTP authentication scheme 'digest'.
    //
    WS_E_SERVER_REQUIRES_DIGEST_AUTH = 0x803D001DL,

    //
    // MessageId: WS_E_SERVER_REQUIRES_NTLM_AUTH
    //
    // MessageText:
    //
    // The remote endpoint requires HTTP authentication scheme 'NTLM'.
    //
    WS_E_SERVER_REQUIRES_NTLM_AUTH = 0x803D001EL,

    //
    // MessageId: WS_E_SERVER_REQUIRES_NEGOTIATE_AUTH
    //
    // MessageText:
    //
    // The remote endpoint requires HTTP authentication scheme 'negotiate'.
    //
    WS_E_SERVER_REQUIRES_NEGOTIATE_AUTH = 0x803D001FL,

    //
    // MessageId: WS_E_INVALID_ENDPOINT_URL
    //
    // MessageText:
    //
    // The endpoint address URL is invalid.
    //
    WS_E_INVALID_ENDPOINT_URL = 0x803D0020L,

    //
    // MessageId: WS_E_OTHER
    //
    // MessageText:
    //
    // Unrecognized error occurred in the Windows Web Services framework.
    //
    WS_E_OTHER = 0x803D0021L,

    //
    // MessageId: WS_E_SECURITY_TOKEN_EXPIRED
    //
    // MessageText:
    //
    // A security token was rejected by the server because it has expired.
    //
    WS_E_SECURITY_TOKEN_EXPIRED = 0x803D0022L,

    //
    // MessageId: WS_E_SECURITY_SYSTEM_FAILURE
    //
    // MessageText:
    //
    // A security operation failed in the Windows Web Services framework.
    //
    WS_E_SECURITY_SYSTEM_FAILURE = 0x803D0023L,

    //
    // =======================================================
    // Facility Windows Push Notifications (WPN) Error Messages
    // =======================================================
    //
    //
    // MessageId: WPN_E_CHANNEL_CLOSED
    //
    // MessageText:
    //
    // The notification channel has already been closed.
    //
    WPN_E_CHANNEL_CLOSED = 0x803E0100L,

    //
    // MessageId: WPN_E_CHANNEL_REQUEST_NOT_COMPLETE
    //
    // MessageText:
    //
    // The notification channel request did not complete successfully.
    //
    WPN_E_CHANNEL_REQUEST_NOT_COMPLETE = 0x803E0101L,

    //
    // MessageId: WPN_E_INVALID_APP
    //
    // MessageText:
    //
    // The application identifier provided is invalid.
    //
    WPN_E_INVALID_APP = 0x803E0102L,

    //
    // MessageId: WPN_E_OUTSTANDING_CHANNEL_REQUEST
    //
    // MessageText:
    //
    // A notification channel request for the provided application identifier is in progress.
    //
    WPN_E_OUTSTANDING_CHANNEL_REQUEST = 0x803E0103L,

    //
    // MessageId: WPN_E_DUPLICATE_CHANNEL
    //
    // MessageText:
    //
    // The channel identifier is already tied to another application endpoint.
    //
    WPN_E_DUPLICATE_CHANNEL = 0x803E0104L,

    //
    // MessageId: WPN_E_PLATFORM_UNAVAILABLE
    //
    // MessageText:
    //
    // The notification platform is unavailable.
    //
    WPN_E_PLATFORM_UNAVAILABLE = 0x803E0105L,

    //
    // MessageId: WPN_E_NOTIFICATION_POSTED
    //
    // MessageText:
    //
    // The notification has already been posted.
    //
    WPN_E_NOTIFICATION_POSTED = 0x803E0106L,

    //
    // MessageId: WPN_E_NOTIFICATION_HIDDEN
    //
    // MessageText:
    //
    // The notification has already been hidden.
    //
    WPN_E_NOTIFICATION_HIDDEN = 0x803E0107L,

    //
    // MessageId: WPN_E_NOTIFICATION_NOT_POSTED
    //
    // MessageText:
    //
    // The notification cannot be hidden until it has been shown.
    //
    WPN_E_NOTIFICATION_NOT_POSTED = 0x803E0108L,

    //
    // MessageId: WPN_E_CLOUD_DISABLED
    //
    // MessageText:
    //
    // Cloud notifications have been turned off.
    //
    WPN_E_CLOUD_DISABLED = 0x803E0109L,

    //
    // MessageId: WPN_E_CLOUD_INCAPABLE
    //
    // MessageText:
    //
    // The application does not have the cloud notification capability.
    //
    WPN_E_CLOUD_INCAPABLE = 0x803E0110L,

    //
    // MessageId: WPN_E_CLOUD_AUTH_UNAVAILABLE
    //
    // MessageText:
    //
    // The notification platform is unable to retrieve the authentication credentials required to connect to the cloud notification service.
    //
    WPN_E_CLOUD_AUTH_UNAVAILABLE = 0x803E011AL,

    //
    // MessageId: WPN_E_CLOUD_SERVICE_UNAVAILABLE
    //
    // MessageText:
    //
    // The notification platform is unable to connect to the cloud notification service.
    //
    WPN_E_CLOUD_SERVICE_UNAVAILABLE = 0x803E011BL,

    //
    // MessageId: WPN_E_FAILED_LOCK_SCREEN_UPDATE_INTIALIZATION
    //
    // MessageText:
    //
    // The notification platform is unable to initialize a callback for lock screen updates.
    //
    WPN_E_FAILED_LOCK_SCREEN_UPDATE_INTIALIZATION = 0x803E011CL,

    //
    // MessageId: WPN_E_NOTIFICATION_DISABLED
    //
    // MessageText:
    //
    // Settings prevent the notification from being delivered.
    //
    WPN_E_NOTIFICATION_DISABLED = 0x803E0111L,

    //
    // MessageId: WPN_E_NOTIFICATION_INCAPABLE
    //
    // MessageText:
    //
    // Application capabilities prevent the notification from being delivered.
    //
    WPN_E_NOTIFICATION_INCAPABLE = 0x803E0112L,

    //
    // MessageId: WPN_E_INTERNET_INCAPABLE
    //
    // MessageText:
    //
    // The application does not have the internet access capability.
    //
    WPN_E_INTERNET_INCAPABLE = 0x803E0113L,

    //
    // MessageId: WPN_E_NOTIFICATION_TYPE_DISABLED
    //
    // MessageText:
    //
    // Settings prevent the notification type from being delivered.
    //
    WPN_E_NOTIFICATION_TYPE_DISABLED = 0x803E0114L,

    //
    // MessageId: WPN_E_NOTIFICATION_SIZE
    //
    // MessageText:
    //
    // The size of the notification content is too large.
    //
    WPN_E_NOTIFICATION_SIZE = 0x803E0115L,

    //
    // MessageId: WPN_E_TAG_SIZE
    //
    // MessageText:
    //
    // The size of the notification tag is too large.
    //
    WPN_E_TAG_SIZE = 0x803E0116L,

    //
    // MessageId: WPN_E_ACCESS_DENIED
    //
    // MessageText:
    //
    // The notification platform doesn't have appropriate privilege on resources.
    //
    WPN_E_ACCESS_DENIED = 0x803E0117L,

    //
    // MessageId: WPN_E_DUPLICATE_REGISTRATION
    //
    // MessageText:
    //
    // The notification platform found application is already registered.
    //
    WPN_E_DUPLICATE_REGISTRATION = 0x803E0118L,

    //
    // MessageId: WPN_E_PUSH_NOTIFICATION_INCAPABLE
    //
    // MessageText:
    //
    // The application background task does not have the push notification capability.
    //
    WPN_E_PUSH_NOTIFICATION_INCAPABLE = 0x803E0119L,

    //
    // MessageId: WPN_E_DEV_ID_SIZE
    //
    // MessageText:
    //
    // The size of the developer id for scheduled notification is too large.
    //
    WPN_E_DEV_ID_SIZE = 0x803E0120L,

    //
    // MessageId: WPN_E_TAG_ALPHANUMERIC
    //
    // MessageText:
    //
    // The notification tag is not alphanumeric.
    //
    WPN_E_TAG_ALPHANUMERIC = 0x803E012AL,

    //
    // MessageId: WPN_E_INVALID_HTTP_STATUS_CODE
    //
    // MessageText:
    //
    // The notification platform has received invalid HTTP status code other than 2xx for polling.
    //
    WPN_E_INVALID_HTTP_STATUS_CODE = 0x803E012BL,

    //
    // MessageId: WPN_E_OUT_OF_SESSION
    //
    // MessageText:
    //
    // The notification platform has run out of presentation layer sessions.
    //
    WPN_E_OUT_OF_SESSION = 0x803E0200L,

    //
    // MessageId: WPN_E_POWER_SAVE
    //
    // MessageText:
    //
    // The notification platform rejects image download request due to system in power save mode.
    //
    WPN_E_POWER_SAVE = 0x803E0201L,

    //
    // MessageId: WPN_E_IMAGE_NOT_FOUND_IN_CACHE
    //
    // MessageText:
    //
    // The notification platform doesn't have the requested image in its cache.
    //
    WPN_E_IMAGE_NOT_FOUND_IN_CACHE = 0x803E0202L,

    //
    // MessageId: WPN_E_ALL_URL_NOT_COMPLETED
    //
    // MessageText:
    //
    // The notification platform cannot complete all of requested image.
    //
    WPN_E_ALL_URL_NOT_COMPLETED = 0x803E0203L,

    //
    // MessageId: WPN_E_INVALID_CLOUD_IMAGE
    //
    // MessageText:
    //
    // A cloud image downloaded from the notification platform is invalid.
    //
    WPN_E_INVALID_CLOUD_IMAGE = 0x803E0204L,

    //
    // MessageId: WPN_E_NOTIFICATION_ID_MATCHED
    //
    // MessageText:
    //
    // Notification Id provided as filter is matched with what the notification platform maintains.
    //
    WPN_E_NOTIFICATION_ID_MATCHED = 0x803E0205L,

    //
    // MessageId: WPN_E_CALLBACK_ALREADY_REGISTERED
    //
    // MessageText:
    //
    // Notification callback interface is already registered.
    //
    WPN_E_CALLBACK_ALREADY_REGISTERED = 0x803E0206L,

    //
    // MessageId: WPN_E_TOAST_NOTIFICATION_DROPPED
    //
    // MessageText:
    //
    // Toast Notification was dropped without being displayed to the user.
    //
    WPN_E_TOAST_NOTIFICATION_DROPPED = 0x803E0207L,

    //
    // MessageId: WPN_E_STORAGE_LOCKED
    //
    // MessageText:
    //
    // The notification platform does not have the proper privileges to complete the request.
    //
    WPN_E_STORAGE_LOCKED = 0x803E0208L,

    //
    // MBN error codes
    //

    //
    // MessageId: E_MBN_CONTEXT_NOT_ACTIVATED
    //
    // MessageText:
    //
    // Context is not activated.
    //
    E_MBN_CONTEXT_NOT_ACTIVATED = 0x80548201L,

    //
    // MessageId: E_MBN_BAD_SIM
    //
    // MessageText:
    //
    // Bad SIM is inserted.
    //
    E_MBN_BAD_SIM = 0x80548202L,

    //
    // MessageId: E_MBN_DATA_CLASS_NOT_AVAILABLE
    //
    // MessageText:
    //
    // Requested data class is not avaialable.
    //
    E_MBN_DATA_CLASS_NOT_AVAILABLE = 0x80548203L,

    //
    // MessageId: E_MBN_INVALID_ACCESS_STRING
    //
    // MessageText:
    //
    // Access point name (APN) or Access string is incorrect.
    //
    E_MBN_INVALID_ACCESS_STRING = 0x80548204L,

    //
    // MessageId: E_MBN_MAX_ACTIVATED_CONTEXTS
    //
    // MessageText:
    //
    // Max activated contexts have reached.
    //
    E_MBN_MAX_ACTIVATED_CONTEXTS = 0x80548205L,

    //
    // MessageId: E_MBN_PACKET_SVC_DETACHED
    //
    // MessageText:
    //
    // Device is in packet detach state.
    //
    E_MBN_PACKET_SVC_DETACHED = 0x80548206L,

    //
    // MessageId: E_MBN_PROVIDER_NOT_VISIBLE
    //
    // MessageText:
    //
    // Provider is not visible.
    //
    E_MBN_PROVIDER_NOT_VISIBLE = 0x80548207L,

    //
    // MessageId: E_MBN_RADIO_POWER_OFF
    //
    // MessageText:
    //
    // Radio is powered off.
    //
    E_MBN_RADIO_POWER_OFF = 0x80548208L,

    //
    // MessageId: E_MBN_SERVICE_NOT_ACTIVATED
    //
    // MessageText:
    //
    // MBN subscription is not activated.
    //
    E_MBN_SERVICE_NOT_ACTIVATED = 0x80548209L,

    //
    // MessageId: E_MBN_SIM_NOT_INSERTED
    //
    // MessageText:
    //
    // SIM is not inserted.
    //
    E_MBN_SIM_NOT_INSERTED = 0x8054820AL,

    //
    // MessageId: E_MBN_VOICE_CALL_IN_PROGRESS
    //
    // MessageText:
    //
    // Voice call in progress.
    //
    E_MBN_VOICE_CALL_IN_PROGRESS = 0x8054820BL,

    //
    // MessageId: E_MBN_INVALID_CACHE
    //
    // MessageText:
    //
    // Visible provider cache is invalid.
    //
    E_MBN_INVALID_CACHE = 0x8054820CL,

    //
    // MessageId: E_MBN_NOT_REGISTERED
    //
    // MessageText:
    //
    // Device is not registered.
    //
    E_MBN_NOT_REGISTERED = 0x8054820DL,

    //
    // MessageId: E_MBN_PROVIDERS_NOT_FOUND
    //
    // MessageText:
    //
    // Providers not found.
    //
    E_MBN_PROVIDERS_NOT_FOUND = 0x8054820EL,

    //
    // MessageId: E_MBN_PIN_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Pin is not supported.
    //
    E_MBN_PIN_NOT_SUPPORTED = 0x8054820FL,

    //
    // MessageId: E_MBN_PIN_REQUIRED
    //
    // MessageText:
    //
    // Pin is required.
    //
    E_MBN_PIN_REQUIRED = 0x80548210L,

    //
    // MessageId: E_MBN_PIN_DISABLED
    //
    // MessageText:
    //
    // PIN is disabled.
    //
    E_MBN_PIN_DISABLED = 0x80548211L,

    //
    // MessageId: E_MBN_FAILURE
    //
    // MessageText:
    //
    // Generic Failure.
    //
    E_MBN_FAILURE = 0x80548212L,

    // Profile related error messages
    //
    // MessageId: E_MBN_INVALID_PROFILE
    //
    // MessageText:
    //
    // Profile is invalid.
    //
    E_MBN_INVALID_PROFILE = 0x80548218L,

    //
    // MessageId: E_MBN_DEFAULT_PROFILE_EXIST
    //
    // MessageText:
    //
    // Default profile exist.
    //
    E_MBN_DEFAULT_PROFILE_EXIST = 0x80548219L,

    // SMS related error messages
    //
    // MessageId: E_MBN_SMS_ENCODING_NOT_SUPPORTED
    //
    // MessageText:
    //
    // SMS encoding is not supported.
    //
    E_MBN_SMS_ENCODING_NOT_SUPPORTED = 0x80548220L,

    //
    // MessageId: E_MBN_SMS_FILTER_NOT_SUPPORTED
    //
    // MessageText:
    //
    // SMS filter is not supported.
    //
    E_MBN_SMS_FILTER_NOT_SUPPORTED = 0x80548221L,

    //
    // MessageId: E_MBN_SMS_INVALID_MEMORY_INDEX
    //
    // MessageText:
    //
    // Invalid SMS memory index is used.
    //
    E_MBN_SMS_INVALID_MEMORY_INDEX = 0x80548222L,

    //
    // MessageId: E_MBN_SMS_LANG_NOT_SUPPORTED
    //
    // MessageText:
    //
    // SMS language is not supported.
    //
    E_MBN_SMS_LANG_NOT_SUPPORTED = 0x80548223L,

    //
    // MessageId: E_MBN_SMS_MEMORY_FAILURE
    //
    // MessageText:
    //
    // SMS memory failure occurred.
    //
    E_MBN_SMS_MEMORY_FAILURE = 0x80548224L,

    //
    // MessageId: E_MBN_SMS_NETWORK_TIMEOUT
    //
    // MessageText:
    //
    // SMS network timeout happened.
    //
    E_MBN_SMS_NETWORK_TIMEOUT = 0x80548225L,

    //
    // MessageId: E_MBN_SMS_UNKNOWN_SMSC_ADDRESS
    //
    // MessageText:
    //
    // Unknown SMSC address is used.
    //
    E_MBN_SMS_UNKNOWN_SMSC_ADDRESS = 0x80548226L,

    //
    // MessageId: E_MBN_SMS_FORMAT_NOT_SUPPORTED
    //
    // MessageText:
    //
    // SMS format is not supported.
    //
    E_MBN_SMS_FORMAT_NOT_SUPPORTED = 0x80548227L,

    //
    // MessageId: E_MBN_SMS_OPERATION_NOT_ALLOWED
    //
    // MessageText:
    //
    // SMS operation is not allowed.
    //
    E_MBN_SMS_OPERATION_NOT_ALLOWED = 0x80548228L,

    //
    // MessageId: E_MBN_SMS_MEMORY_FULL
    //
    // MessageText:
    //
    // Device SMS memory is full.
    //
    E_MBN_SMS_MEMORY_FULL = 0x80548229L,

    //
    // P2P error codes
    //

    //
    // MessageId: PEER_E_IPV6_NOT_INSTALLED
    //
    // MessageText:
    //
    // The IPv6 protocol is not installed.
    //
    PEER_E_IPV6_NOT_INSTALLED = 0x80630001L,

    //
    // MessageId: PEER_E_NOT_INITIALIZED
    //
    // MessageText:
    //
    // The compoment has not been initialized.
    //
    PEER_E_NOT_INITIALIZED = 0x80630002L,

    //
    // MessageId: PEER_E_CANNOT_START_SERVICE
    //
    // MessageText:
    //
    // The required service canot be started.
    //
    PEER_E_CANNOT_START_SERVICE = 0x80630003L,

    //
    // MessageId: PEER_E_NOT_LICENSED
    //
    // MessageText:
    //
    // The P2P protocol is not licensed to run on this OS.
    //
    PEER_E_NOT_LICENSED = 0x80630004L,

    //
    // MessageId: PEER_E_INVALID_GRAPH
    //
    // MessageText:
    //
    // The graph handle is invalid.
    //
    PEER_E_INVALID_GRAPH = 0x80630010L,

    //
    // MessageId: PEER_E_DBNAME_CHANGED
    //
    // MessageText:
    //
    // The graph database name has changed.
    //
    PEER_E_DBNAME_CHANGED = 0x80630011L,

    //
    // MessageId: PEER_E_DUPLICATE_GRAPH
    //
    // MessageText:
    //
    // A graph with the same ID already exists.
    //
    PEER_E_DUPLICATE_GRAPH = 0x80630012L,

    //
    // MessageId: PEER_E_GRAPH_NOT_READY
    //
    // MessageText:
    //
    // The graph is not ready.
    //
    PEER_E_GRAPH_NOT_READY = 0x80630013L,

    //
    // MessageId: PEER_E_GRAPH_SHUTTING_DOWN
    //
    // MessageText:
    //
    // The graph is shutting down.
    //
    PEER_E_GRAPH_SHUTTING_DOWN = 0x80630014L,

    //
    // MessageId: PEER_E_GRAPH_IN_USE
    //
    // MessageText:
    //
    // The graph is still in use.
    //
    PEER_E_GRAPH_IN_USE = 0x80630015L,

    //
    // MessageId: PEER_E_INVALID_DATABASE
    //
    // MessageText:
    //
    // The graph database is corrupt.
    //
    PEER_E_INVALID_DATABASE = 0x80630016L,

    //
    // MessageId: PEER_E_TOO_MANY_ATTRIBUTES
    //
    // MessageText:
    //
    // Too many attributes have been used.
    //
    PEER_E_TOO_MANY_ATTRIBUTES = 0x80630017L,

    //
    // MessageId: PEER_E_CONNECTION_NOT_FOUND
    //
    // MessageText:
    //
    // The connection can not be found.
    //
    PEER_E_CONNECTION_NOT_FOUND = 0x80630103L,

    //
    // MessageId: PEER_E_CONNECT_SELF
    //
    // MessageText:
    //
    // The peer attempted to connect to itself.
    //
    PEER_E_CONNECT_SELF = 0x80630106L,

    //
    // MessageId: PEER_E_ALREADY_LISTENING
    //
    // MessageText:
    //
    // The peer is already listening for connections.
    //
    PEER_E_ALREADY_LISTENING = 0x80630107L,

    //
    // MessageId: PEER_E_NODE_NOT_FOUND
    //
    // MessageText:
    //
    // The node was not found.
    //
    PEER_E_NODE_NOT_FOUND = 0x80630108L,

    //
    // MessageId: PEER_E_CONNECTION_FAILED
    //
    // MessageText:
    //
    // The Connection attempt failed.
    //
    PEER_E_CONNECTION_FAILED = 0x80630109L,

    //
    // MessageId: PEER_E_CONNECTION_NOT_AUTHENTICATED
    //
    // MessageText:
    //
    // The peer connection could not be authenticated.
    //
    PEER_E_CONNECTION_NOT_AUTHENTICATED = 0x8063010AL,

    //
    // MessageId: PEER_E_CONNECTION_REFUSED
    //
    // MessageText:
    //
    // The connection was refused.
    //
    PEER_E_CONNECTION_REFUSED = 0x8063010BL,

    //
    // MessageId: PEER_E_CLASSIFIER_TOO_LONG
    //
    // MessageText:
    //
    // The peer name classifier is too long.
    //
    PEER_E_CLASSIFIER_TOO_LONG = 0x80630201L,

    //
    // MessageId: PEER_E_TOO_MANY_IDENTITIES
    //
    // MessageText:
    //
    // The maximum number of identities have been created.
    //
    PEER_E_TOO_MANY_IDENTITIES = 0x80630202L,

    //
    // MessageId: PEER_E_NO_KEY_ACCESS
    //
    // MessageText:
    //
    // Unable to access a key.
    //
    PEER_E_NO_KEY_ACCESS = 0x80630203L,

    //
    // MessageId: PEER_E_GROUPS_EXIST
    //
    // MessageText:
    //
    // The group already exists.
    //
    PEER_E_GROUPS_EXIST = 0x80630204L,

    // record error codes
    //
    // MessageId: PEER_E_RECORD_NOT_FOUND
    //
    // MessageText:
    //
    // The requested record could not be found.
    //
    PEER_E_RECORD_NOT_FOUND = 0x80630301L,

    //
    // MessageId: PEER_E_DATABASE_ACCESSDENIED
    //
    // MessageText:
    //
    // Access to the database was denied.
    //
    PEER_E_DATABASE_ACCESSDENIED = 0x80630302L,

    //
    // MessageId: PEER_E_DBINITIALIZATION_FAILED
    //
    // MessageText:
    //
    // The Database could not be initialized.
    //
    PEER_E_DBINITIALIZATION_FAILED = 0x80630303L,

    //
    // MessageId: PEER_E_MAX_RECORD_SIZE_EXCEEDED
    //
    // MessageText:
    //
    // The record is too big.
    //
    PEER_E_MAX_RECORD_SIZE_EXCEEDED = 0x80630304L,

    //
    // MessageId: PEER_E_DATABASE_ALREADY_PRESENT
    //
    // MessageText:
    //
    // The database already exists.
    //
    PEER_E_DATABASE_ALREADY_PRESENT = 0x80630305L,

    //
    // MessageId: PEER_E_DATABASE_NOT_PRESENT
    //
    // MessageText:
    //
    // The database could not be found.
    //
    PEER_E_DATABASE_NOT_PRESENT = 0x80630306L,

    //
    // MessageId: PEER_E_IDENTITY_NOT_FOUND
    //
    // MessageText:
    //
    // The identity could not be found.
    //
    PEER_E_IDENTITY_NOT_FOUND = 0x80630401L,

    // eventing error
    //
    // MessageId: PEER_E_EVENT_HANDLE_NOT_FOUND
    //
    // MessageText:
    //
    // The event handle could not be found.
    //
    PEER_E_EVENT_HANDLE_NOT_FOUND = 0x80630501L,

    // searching error
    //
    // MessageId: PEER_E_INVALID_SEARCH
    //
    // MessageText:
    //
    // Invalid search.
    //
    PEER_E_INVALID_SEARCH = 0x80630601L,

    //
    // MessageId: PEER_E_INVALID_ATTRIBUTES
    //
    // MessageText:
    //
    // The search atributes are invalid.
    //
    PEER_E_INVALID_ATTRIBUTES = 0x80630602L,

    // certificate verification error codes
    //
    // MessageId: PEER_E_INVITATION_NOT_TRUSTED
    //
    // MessageText:
    //
    // The invitiation is not trusted.
    //
    PEER_E_INVITATION_NOT_TRUSTED = 0x80630701L,

    //
    // MessageId: PEER_E_CHAIN_TOO_LONG
    //
    // MessageText:
    //
    // The certchain is too long.
    //
    PEER_E_CHAIN_TOO_LONG = 0x80630703L,

    //
    // MessageId: PEER_E_INVALID_TIME_PERIOD
    //
    // MessageText:
    //
    // The time period is invalid.
    //
    PEER_E_INVALID_TIME_PERIOD = 0x80630705L,

    //
    // MessageId: PEER_E_CIRCULAR_CHAIN_DETECTED
    //
    // MessageText:
    //
    // A circular cert chain was detected.
    //
    PEER_E_CIRCULAR_CHAIN_DETECTED = 0x80630706L,

    //
    // MessageId: PEER_E_CERT_STORE_CORRUPTED
    //
    // MessageText:
    //
    // The certstore is corrupted.
    //
    PEER_E_CERT_STORE_CORRUPTED = 0x80630801L,

    //
    // MessageId: PEER_E_NO_CLOUD
    //
    // MessageText:
    //
    // The specified PNRP cloud deos not exist.
    //
    PEER_E_NO_CLOUD = 0x80631001L,

    //
    // MessageId: PEER_E_CLOUD_NAME_AMBIGUOUS
    //
    // MessageText:
    //
    // The cloud name is ambiguous.
    //
    PEER_E_CLOUD_NAME_AMBIGUOUS = 0x80631005L,

    //
    // MessageId: PEER_E_INVALID_RECORD
    //
    // MessageText:
    //
    // The record is invlaid.
    //
    PEER_E_INVALID_RECORD = 0x80632010L,

    //
    // MessageId: PEER_E_NOT_AUTHORIZED
    //
    // MessageText:
    //
    // Not authorized.
    //
    PEER_E_NOT_AUTHORIZED = 0x80632020L,

    //
    // MessageId: PEER_E_PASSWORD_DOES_NOT_MEET_POLICY
    //
    // MessageText:
    //
    // The password does not meet policy requirements.
    //
    PEER_E_PASSWORD_DOES_NOT_MEET_POLICY = 0x80632021L,

    //
    // MessageId: PEER_E_DEFERRED_VALIDATION
    //
    // MessageText:
    //
    // The record validation has been defered.
    //
    PEER_E_DEFERRED_VALIDATION = 0x80632030L,

    //
    // MessageId: PEER_E_INVALID_GROUP_PROPERTIES
    //
    // MessageText:
    //
    // The group properies are invalid.
    //
    PEER_E_INVALID_GROUP_PROPERTIES = 0x80632040L,

    //
    // MessageId: PEER_E_INVALID_PEER_NAME
    //
    // MessageText:
    //
    // The peername is invalid.
    //
    PEER_E_INVALID_PEER_NAME = 0x80632050L,

    //
    // MessageId: PEER_E_INVALID_CLASSIFIER
    //
    // MessageText:
    //
    // The classifier is invalid.
    //
    PEER_E_INVALID_CLASSIFIER = 0x80632060L,

    //
    // MessageId: PEER_E_INVALID_FRIENDLY_NAME
    //
    // MessageText:
    //
    // The friendly name is invalid.
    //
    PEER_E_INVALID_FRIENDLY_NAME = 0x80632070L,

    //
    // MessageId: PEER_E_INVALID_ROLE_PROPERTY
    //
    // MessageText:
    //
    // Invalid role property.
    //
    PEER_E_INVALID_ROLE_PROPERTY = 0x80632071L,

    //
    // MessageId: PEER_E_INVALID_CLASSIFIER_PROPERTY
    //
    // MessageText:
    //
    // Invalid classifer property.
    //
    PEER_E_INVALID_CLASSIFIER_PROPERTY = 0x80632072L,

    //
    // MessageId: PEER_E_INVALID_RECORD_EXPIRATION
    //
    // MessageText:
    //
    // Invlaid record expiration.
    //
    PEER_E_INVALID_RECORD_EXPIRATION = 0x80632080L,

    //
    // MessageId: PEER_E_INVALID_CREDENTIAL_INFO
    //
    // MessageText:
    //
    // Invlaid credential info.
    //
    PEER_E_INVALID_CREDENTIAL_INFO = 0x80632081L,

    //
    // MessageId: PEER_E_INVALID_CREDENTIAL
    //
    // MessageText:
    //
    // Invalid credential.
    //
    PEER_E_INVALID_CREDENTIAL = 0x80632082L,

    //
    // MessageId: PEER_E_INVALID_RECORD_SIZE
    //
    // MessageText:
    //
    // Invalid record size.
    //
    PEER_E_INVALID_RECORD_SIZE = 0x80632083L,

    //
    // MessageId: PEER_E_UNSUPPORTED_VERSION
    //
    // MessageText:
    //
    // Unsupported version.
    //
    PEER_E_UNSUPPORTED_VERSION = 0x80632090L,

    //
    // MessageId: PEER_E_GROUP_NOT_READY
    //
    // MessageText:
    //
    // The group is not ready.
    //
    PEER_E_GROUP_NOT_READY = 0x80632091L,

    //
    // MessageId: PEER_E_GROUP_IN_USE
    //
    // MessageText:
    //
    // The group is still in use.
    //
    PEER_E_GROUP_IN_USE = 0x80632092L,

    //
    // MessageId: PEER_E_INVALID_GROUP
    //
    // MessageText:
    //
    // The group is invalid.
    //
    PEER_E_INVALID_GROUP = 0x80632093L,

    //
    // MessageId: PEER_E_NO_MEMBERS_FOUND
    //
    // MessageText:
    //
    // No members were found.
    //
    PEER_E_NO_MEMBERS_FOUND = 0x80632094L,

    //
    // MessageId: PEER_E_NO_MEMBER_CONNECTIONS
    //
    // MessageText:
    //
    // There are no member connections.
    //
    PEER_E_NO_MEMBER_CONNECTIONS = 0x80632095L,

    //
    // MessageId: PEER_E_UNABLE_TO_LISTEN
    //
    // MessageText:
    //
    // Unable to listen.
    //
    PEER_E_UNABLE_TO_LISTEN = 0x80632096L,

    //
    // MessageId: PEER_E_IDENTITY_DELETED
    //
    // MessageText:
    //
    // The identity does not exist.
    //
    PEER_E_IDENTITY_DELETED = 0x806320A0L,

    //
    // MessageId: PEER_E_SERVICE_NOT_AVAILABLE
    //
    // MessageText:
    //
    // The service is not availible.
    //
    PEER_E_SERVICE_NOT_AVAILABLE = 0x806320A1L,

    // Contacts APIs error code
    //
    // MessageId: PEER_E_CONTACT_NOT_FOUND
    //
    // MessageText:
    //
    // THe contact could not be found.
    //
    PEER_E_CONTACT_NOT_FOUND = 0x80636001L,

    // Special success codes
    //
    // MessageId: PEER_S_GRAPH_DATA_CREATED
    //
    // MessageText:
    //
    // The graph data was created.
    //
    PEER_S_GRAPH_DATA_CREATED = 0x00630001L,

    //
    // MessageId: PEER_S_NO_EVENT_DATA
    //
    // MessageText:
    //
    // There is not more event data.
    //
    PEER_S_NO_EVENT_DATA = 0x00630002L,

    //
    // MessageId: PEER_S_ALREADY_CONNECTED
    //
    // MessageText:
    //
    // The graph is already connect.
    //
    PEER_S_ALREADY_CONNECTED = 0x00632000L,

    //
    // MessageId: PEER_S_SUBSCRIPTION_EXISTS
    //
    // MessageText:
    //
    // The subscription already exists.
    //
    PEER_S_SUBSCRIPTION_EXISTS = 0x00636000L,

    //
    // MessageId: PEER_S_NO_CONNECTIVITY
    //
    // MessageText:
    //
    // No connectivity.
    //
    PEER_S_NO_CONNECTIVITY = 0x00630005L,

    //
    // MessageId: PEER_S_ALREADY_A_MEMBER
    //
    // MessageText:
    //
    // Already a member.
    //
    PEER_S_ALREADY_A_MEMBER = 0x00630006L,

    // Pnrp helpers errors
    //
    // MessageId: PEER_E_CANNOT_CONVERT_PEER_NAME
    //
    // MessageText:
    //
    // The peername could not be converted to a DNS pnrp name.
    //
    PEER_E_CANNOT_CONVERT_PEER_NAME = 0x80634001L,

    //
    // MessageId: PEER_E_INVALID_PEER_HOST_NAME
    //
    // MessageText:
    //
    // Invalid peer host name.
    //
    PEER_E_INVALID_PEER_HOST_NAME = 0x80634002L,

    //
    // MessageId: PEER_E_NO_MORE
    //
    // MessageText:
    //
    // No more data could be found.
    //
    PEER_E_NO_MORE = 0x80634003L,

    //
    // MessageId: PEER_E_PNRP_DUPLICATE_PEER_NAME
    //
    // MessageText:
    //
    // The existing peer name is already registered.
    //
    PEER_E_PNRP_DUPLICATE_PEER_NAME = 0x80634005L,

    // AppInvite APIs error code
    //
    // MessageId: PEER_E_INVITE_CANCELLED
    //
    // MessageText:
    //
    // The app invite request was cancelled by the user.
    //
    PEER_E_INVITE_CANCELLED = 0x80637000L,

    //
    // MessageId: PEER_E_INVITE_RESPONSE_NOT_AVAILABLE
    //
    // MessageText:
    //
    // No response of the invite was received.
    //
    PEER_E_INVITE_RESPONSE_NOT_AVAILABLE = 0x80637001L,

    // Serverless presence error codes
    //
    // MessageId: PEER_E_NOT_SIGNED_IN
    //
    // MessageText:
    //
    // User is not signed into serverless presence.
    //
    PEER_E_NOT_SIGNED_IN = 0x80637003L,

    //
    // MessageId: PEER_E_PRIVACY_DECLINED
    //
    // MessageText:
    //
    // The user declined the privacy policy prompt.
    //
    PEER_E_PRIVACY_DECLINED = 0x80637004L,

    //
    // MessageId: PEER_E_TIMEOUT
    //
    // MessageText:
    //
    // A timeout occurred.
    //
    PEER_E_TIMEOUT = 0x80637005L,

    //
    // MessageId: PEER_E_INVALID_ADDRESS
    //
    // MessageText:
    //
    // The address is invalid.
    //
    PEER_E_INVALID_ADDRESS = 0x80637007L,

    //
    // MessageId: PEER_E_FW_EXCEPTION_DISABLED
    //
    // MessageText:
    //
    // A required firewall exception is disabled.
    //
    PEER_E_FW_EXCEPTION_DISABLED = 0x80637008L,

    //
    // MessageId: PEER_E_FW_BLOCKED_BY_POLICY
    //
    // MessageText:
    //
    // The service is blocked by a firewall policy.
    //
    PEER_E_FW_BLOCKED_BY_POLICY = 0x80637009L,

    //
    // MessageId: PEER_E_FW_BLOCKED_BY_SHIELDS_UP
    //
    // MessageText:
    //
    // Firewall exceptions are disabled.
    //
    PEER_E_FW_BLOCKED_BY_SHIELDS_UP = 0x8063700AL,

    //
    // MessageId: PEER_E_FW_DECLINED
    //
    // MessageText:
    //
    // The user declined to enable the firewall exceptions.
    //
    PEER_E_FW_DECLINED = 0x8063700BL,

    //
    // UI error codes
    //

    //
    // MessageId: UI_E_CREATE_FAILED
    //
    // MessageText:
    //
    // The object could not be created.
    //
    UI_E_CREATE_FAILED = 0x802A0001L,

    //
    // MessageId: UI_E_SHUTDOWN_CALLED
    //
    // MessageText:
    //
    // Shutdown was already called on this object or the object that owns it.
    //
    UI_E_SHUTDOWN_CALLED = 0x802A0002L,

    //
    // MessageId: UI_E_ILLEGAL_REENTRANCY
    //
    // MessageText:
    //
    // This method cannot be called during this type of callback.
    //
    UI_E_ILLEGAL_REENTRANCY = 0x802A0003L,

    //
    // MessageId: UI_E_OBJECT_SEALED
    //
    // MessageText:
    //
    // This object has been sealed, so this change is no longer allowed.
    //
    UI_E_OBJECT_SEALED = 0x802A0004L,

    //
    // MessageId: UI_E_VALUE_NOT_SET
    //
    // MessageText:
    //
    // The requested value was never set.
    //
    UI_E_VALUE_NOT_SET = 0x802A0005L,

    //
    // MessageId: UI_E_VALUE_NOT_DETERMINED
    //
    // MessageText:
    //
    // The requested value cannot be determined.
    //
    UI_E_VALUE_NOT_DETERMINED = 0x802A0006L,

    //
    // MessageId: UI_E_INVALID_OUTPUT
    //
    // MessageText:
    //
    // A callback returned an invalid output parameter.
    //
    UI_E_INVALID_OUTPUT = 0x802A0007L,

    //
    // MessageId: UI_E_BOOLEAN_EXPECTED
    //
    // MessageText:
    //
    // A callback returned a success code other than S_OK or S_FALSE.
    //
    UI_E_BOOLEAN_EXPECTED = 0x802A0008L,

    //
    // MessageId: UI_E_DIFFERENT_OWNER
    //
    // MessageText:
    //
    // A parameter that should be owned by this object is owned by a different object.
    //
    UI_E_DIFFERENT_OWNER = 0x802A0009L,

    //
    // MessageId: UI_E_AMBIGUOUS_MATCH
    //
    // MessageText:
    //
    // More than one item matched the search criteria.
    //
    UI_E_AMBIGUOUS_MATCH = 0x802A000AL,

    //
    // MessageId: UI_E_FP_OVERFLOW
    //
    // MessageText:
    //
    // A floating-point overflow occurred.
    //
    UI_E_FP_OVERFLOW = 0x802A000BL,

    //
    // MessageId: UI_E_WRONG_THREAD
    //
    // MessageText:
    //
    // This method can only be called from the thread that created the object.
    //
    UI_E_WRONG_THREAD = 0x802A000CL,

    //
    // MessageId: UI_E_STORYBOARD_ACTIVE
    //
    // MessageText:
    //
    // The storyboard is currently in the schedule.
    //
    UI_E_STORYBOARD_ACTIVE = 0x802A0101L,

    //
    // MessageId: UI_E_STORYBOARD_NOT_PLAYING
    //
    // MessageText:
    //
    // The storyboard is not playing.
    //
    UI_E_STORYBOARD_NOT_PLAYING = 0x802A0102L,

    //
    // MessageId: UI_E_START_KEYFRAME_AFTER_END
    //
    // MessageText:
    //
    // The start keyframe might occur after the end keyframe.
    //
    UI_E_START_KEYFRAME_AFTER_END = 0x802A0103L,

    //
    // MessageId: UI_E_END_KEYFRAME_NOT_DETERMINED
    //
    // MessageText:
    //
    // It might not be possible to determine the end keyframe time when the start keyframe is reached.
    //
    UI_E_END_KEYFRAME_NOT_DETERMINED = 0x802A0104L,

    //
    // MessageId: UI_E_LOOPS_OVERLAP
    //
    // MessageText:
    //
    // Two repeated portions of a storyboard might overlap.
    //
    UI_E_LOOPS_OVERLAP = 0x802A0105L,

    //
    // MessageId: UI_E_TRANSITION_ALREADY_USED
    //
    // MessageText:
    //
    // The transition has already been added to a storyboard.
    //
    UI_E_TRANSITION_ALREADY_USED = 0x802A0106L,

    //
    // MessageId: UI_E_TRANSITION_NOT_IN_STORYBOARD
    //
    // MessageText:
    //
    // The transition has not been added to a storyboard.
    //
    UI_E_TRANSITION_NOT_IN_STORYBOARD = 0x802A0107L,

    //
    // MessageId: UI_E_TRANSITION_ECLIPSED
    //
    // MessageText:
    //
    // The transition might eclipse the beginning of another transition in the storyboard.
    //
    UI_E_TRANSITION_ECLIPSED = 0x802A0108L,

    //
    // MessageId: UI_E_TIME_BEFORE_LAST_UPDATE
    //
    // MessageText:
    //
    // The given time is earlier than the time passed to the last update.
    //
    UI_E_TIME_BEFORE_LAST_UPDATE = 0x802A0109L,

    //
    // MessageId: UI_E_TIMER_CLIENT_ALREADY_CONNECTED
    //
    // MessageText:
    //
    // This client is already connected to a timer.
    //
    UI_E_TIMER_CLIENT_ALREADY_CONNECTED = 0x802A010AL,

    //
    // MessageId: UI_E_INVALID_DIMENSION
    //
    // MessageText:
    //
    // The passed dimension is invalid or does not match the object's dimension.
    //
    UI_E_INVALID_DIMENSION = 0x802A010BL,

    //
    // MessageId: UI_E_PRIMITIVE_OUT_OF_BOUNDS
    //
    // MessageText:
    //
    // The added primitive begins at or beyond the duration of the interpolator.
    //
    UI_E_PRIMITIVE_OUT_OF_BOUNDS = 0x802A010CL,

    //
    // MessageId: UI_E_WINDOW_CLOSED
    //
    // MessageText:
    //
    // The operation cannot be completed because the window is being closed.
    //
    UI_E_WINDOW_CLOSED = 0x802A0201L,

    //
    // Bluetooth Attribute Protocol Warnings
    //

    //
    // MessageId: E_BLUETOOTH_ATT_INVALID_HANDLE
    //
    // MessageText:
    //
    // The attribute handle given was not valid on this server.
    //
    E_BLUETOOTH_ATT_INVALID_HANDLE = 0x80650001L,

    //
    // MessageId: E_BLUETOOTH_ATT_READ_NOT_PERMITTED
    //
    // MessageText:
    //
    // The attribute cannot be read.
    //
    E_BLUETOOTH_ATT_READ_NOT_PERMITTED = 0x80650002L,

    //
    // MessageId: E_BLUETOOTH_ATT_WRITE_NOT_PERMITTED
    //
    // MessageText:
    //
    // The attribute cannot be written.
    //
    E_BLUETOOTH_ATT_WRITE_NOT_PERMITTED = 0x80650003L,

    //
    // MessageId: E_BLUETOOTH_ATT_INVALID_PDU
    //
    // MessageText:
    //
    // The attribute PDU was invalid.
    //
    E_BLUETOOTH_ATT_INVALID_PDU = 0x80650004L,

    //
    // MessageId: E_BLUETOOTH_ATT_INSUFFICIENT_AUTHENTICATION
    //
    // MessageText:
    //
    // The attribute requires authentication before it can be read or written.
    //
    E_BLUETOOTH_ATT_INSUFFICIENT_AUTHENTICATION = 0x80650005L,

    //
    // MessageId: E_BLUETOOTH_ATT_REQUEST_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Attribute server does not support the request received from the client.
    //
    E_BLUETOOTH_ATT_REQUEST_NOT_SUPPORTED = 0x80650006L,

    //
    // MessageId: E_BLUETOOTH_ATT_INVALID_OFFSET
    //
    // MessageText:
    //
    // Offset specified was past the end of the attribute.
    //
    E_BLUETOOTH_ATT_INVALID_OFFSET = 0x80650007L,

    //
    // MessageId: E_BLUETOOTH_ATT_INSUFFICIENT_AUTHORIZATION
    //
    // MessageText:
    //
    // The attribute requires authorization before it can be read or written.
    //
    E_BLUETOOTH_ATT_INSUFFICIENT_AUTHORIZATION = 0x80650008L,

    //
    // MessageId: E_BLUETOOTH_ATT_PREPARE_QUEUE_FULL
    //
    // MessageText:
    //
    // Too many prepare writes have been queued.
    //
    E_BLUETOOTH_ATT_PREPARE_QUEUE_FULL = 0x80650009L,

    //
    // MessageId: E_BLUETOOTH_ATT_ATTRIBUTE_NOT_FOUND
    //
    // MessageText:
    //
    // No attribute found within the given attribute handle range.
    //
    E_BLUETOOTH_ATT_ATTRIBUTE_NOT_FOUND = 0x8065000AL,

    //
    // MessageId: E_BLUETOOTH_ATT_ATTRIBUTE_NOT_LONG
    //
    // MessageText:
    //
    // The attribute cannot be read or written using the Read Blob Request.
    //
    E_BLUETOOTH_ATT_ATTRIBUTE_NOT_LONG = 0x8065000BL,

    //
    // MessageId: E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE
    //
    // MessageText:
    //
    // The Encryption Key Size used for encrypting this link is insufficient.
    //
    E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE = 0x8065000CL,

    //
    // MessageId: E_BLUETOOTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH
    //
    // MessageText:
    //
    // The attribute value length is invalid for the operation.
    //
    E_BLUETOOTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH = 0x8065000DL,

    //
    // MessageId: E_BLUETOOTH_ATT_UNLIKELY
    //
    // MessageText:
    //
    // The attribute request that was requested has encountered an error that was unlikely, and therefore could not be completed as requested.
    //
    E_BLUETOOTH_ATT_UNLIKELY = 0x8065000EL,

    //
    // MessageId: E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION
    //
    // MessageText:
    //
    // The attribute requires encryption before it can be read or written.
    //
    E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION = 0x8065000FL,

    //
    // MessageId: E_BLUETOOTH_ATT_UNSUPPORTED_GROUP_TYPE
    //
    // MessageText:
    //
    // The attribute type is not a supported grouping attribute as defined by a higher layer specification.
    //
    E_BLUETOOTH_ATT_UNSUPPORTED_GROUP_TYPE = 0x80650010L,

    //
    // MessageId: E_BLUETOOTH_ATT_INSUFFICIENT_RESOURCES
    //
    // MessageText:
    //
    // Insufficient Resources to complete the request.
    //
    E_BLUETOOTH_ATT_INSUFFICIENT_RESOURCES = 0x80650011L,

    //
    // MessageId: E_BLUETOOTH_ATT_UNKNOWN_ERROR
    //
    // MessageText:
    //
    // An error that lies in the reserved range has been received.
    //
    E_BLUETOOTH_ATT_UNKNOWN_ERROR = 0x80651000L,

    //
    // Audio errors
    //

    //
    // MessageId: E_AUDIO_ENGINE_NODE_NOT_FOUND
    //
    // MessageText:
    //
    // PortCls could not find an audio engine node exposed by a miniport driver claiming support for IMiniportAudioEngineNode.
    //
    E_AUDIO_ENGINE_NODE_NOT_FOUND = 0x80660001L,

    //
    // MessageId: E_HDAUDIO_EMPTY_CONNECTION_LIST
    //
    // MessageText:
    //
    // HD Audio widget encountered an unexpected empty connection list.
    //
    E_HDAUDIO_EMPTY_CONNECTION_LIST = 0x80660002L,

    //
    // MessageId: E_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED
    //
    // MessageText:
    //
    // HD Audio widget does not support the connection list parameter.
    //
    E_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED = 0x80660003L,

    //
    // MessageId: E_HDAUDIO_NO_LOGICAL_DEVICES_CREATED
    //
    // MessageText:
    //
    // No HD Audio subdevices were successfully created.
    //
    E_HDAUDIO_NO_LOGICAL_DEVICES_CREATED = 0x80660004L,

    //
    // MessageId: E_HDAUDIO_NULL_LINKED_LIST_ENTRY
    //
    // MessageText:
    //
    // An unexpected NULL pointer was encountered in a linked list.
    //
    E_HDAUDIO_NULL_LINKED_LIST_ENTRY = 0x80660005L,

    //
    // Spaceport errors
    //
    // Success
    //
    // MessageId: ERROR_SPACES_POOL_WAS_DELETED
    //
    // MessageText:
    //
    // The storage pool was deleted by the driver. The object cache should be updated.
    //
    ERROR_SPACES_POOL_WAS_DELETED = 0x00E70001L,

    // Errors
    //
    // MessageId: ERROR_SPACES_RESILIENCY_TYPE_INVALID
    //
    // MessageText:
    //
    // The specified resiliency type is not valid.
    //
    ERROR_SPACES_RESILIENCY_TYPE_INVALID = 0x80E70003L,

    //
    // MessageId: ERROR_SPACES_DRIVE_SECTOR_SIZE_INVALID
    //
    // MessageText:
    //
    // The physical disk's sector size is not supported by the storage pool.
    //
    ERROR_SPACES_DRIVE_SECTOR_SIZE_INVALID = 0x80E70004L,

    //
    // MessageId: ERROR_SPACES_DRIVE_REDUNDANCY_INVALID
    //
    // MessageText:
    //
    // The requested redundancy is outside of the supported range of values.
    //
    ERROR_SPACES_DRIVE_REDUNDANCY_INVALID = 0x80E70006L,

    //
    // MessageId: ERROR_SPACES_NUMBER_OF_DATA_COPIES_INVALID
    //
    // MessageText:
    //
    // The number of data copies requested is outside of the supported range of values.
    //
    ERROR_SPACES_NUMBER_OF_DATA_COPIES_INVALID = 0x80E70007L,

    //
    // MessageId: ERROR_SPACES_PARITY_LAYOUT_INVALID
    //
    // MessageText:
    //
    // The value for ParityLayout is outside of the supported range of values.
    //
    ERROR_SPACES_PARITY_LAYOUT_INVALID = 0x80E70008L,

    //
    // MessageId: ERROR_SPACES_INTERLEAVE_LENGTH_INVALID
    //
    // MessageText:
    //
    // The value for interleave length is outside of the supported range of values.
    //
    ERROR_SPACES_INTERLEAVE_LENGTH_INVALID = 0x80E70009L,

    //
    // MessageId: ERROR_SPACES_NUMBER_OF_COLUMNS_INVALID
    //
    // MessageText:
    //
    // The number of columns specified is outside of the supported range of values.
    //
    ERROR_SPACES_NUMBER_OF_COLUMNS_INVALID = 0x80E7000AL,

    //
    // MessageId: ERROR_SPACES_NOT_ENOUGH_DRIVES
    //
    // MessageText:
    //
    // There were not enough physical disks to complete the requested operation.
    //
    ERROR_SPACES_NOT_ENOUGH_DRIVES = 0x80E7000BL,

    //
    // Volsnap errors
    //
    // Success
    //
    // MessageId: ERROR_VOLSNAP_BOOTFILE_NOT_VALID
    //
    // MessageText:
    //
    // The bootfile is too small to support persistent snapshots.
    //
    ERROR_VOLSNAP_BOOTFILE_NOT_VALID = 0x80820001L,

    //
    // Tiering errors
    //
    // Errors
    //
    // MessageId: ERROR_TIERING_NOT_SUPPORTED_ON_VOLUME
    //
    // MessageText:
    //
    // The specified volume does not support storage tiers.
    //
    ERROR_TIERING_NOT_SUPPORTED_ON_VOLUME = 0x80830001L,

    //
    // MessageId: ERROR_TIERING_VOLUME_DISMOUNT_IN_PROGRESS
    //
    // MessageText:
    //
    // The Storage Tiers Management service detected that the specified volume is in the process of being dismounted.
    //
    ERROR_TIERING_VOLUME_DISMOUNT_IN_PROGRESS = 0x80830002L,

    //
    // MessageId: ERROR_TIERING_STORAGE_TIER_NOT_FOUND
    //
    // MessageText:
    //
    // The specified storage tier could not be found on the volume. Confirm that the storage tier name is valid.
    //
    ERROR_TIERING_STORAGE_TIER_NOT_FOUND = 0x80830003L,

    //
    // MessageId: ERROR_TIERING_INVALID_FILE_ID
    //
    // MessageText:
    //
    // The file identifier specified is not valid on the volume.
    //
    ERROR_TIERING_INVALID_FILE_ID = 0x80830004L,

    //
    // MessageId: ERROR_TIERING_WRONG_CLUSTER_NODE
    //
    // MessageText:
    //
    // Storage tier operations must be called on the clustering node that owns the metadata volume.
    //
    ERROR_TIERING_WRONG_CLUSTER_NODE = 0x80830005L,

    //
    // MessageId: ERROR_TIERING_ALREADY_PROCESSING
    //
    // MessageText:
    //
    // The Storage Tiers Management service is already optimizing the storage tiers on the specified volume.
    //
    ERROR_TIERING_ALREADY_PROCESSING = 0x80830006L,

    //
    // MessageId: ERROR_TIERING_CANNOT_PIN_OBJECT
    //
    // MessageText:
    //
    // The requested object type cannot be assigned to a storage tier.
    //
    ERROR_TIERING_CANNOT_PIN_OBJECT = 0x80830007L,

    //
    // ===============================
    // Facility Direct* Error Messages
    // ===============================
    //
    //

    //
    // DXGI status (success) codes
    //

    //
    // MessageId: DXGI_STATUS_OCCLUDED
    //
    // MessageText:
    //
    // The Present operation was invisible to the user.
    //
    DXGI_STATUS_OCCLUDED = 0x087A0001L,

    //
    // MessageId: DXGI_STATUS_CLIPPED
    //
    // MessageText:
    //
    // The Present operation was partially invisible to the user.
    //
    DXGI_STATUS_CLIPPED = 0x087A0002L,

    //
    // MessageId: DXGI_STATUS_NO_REDIRECTION
    //
    // MessageText:
    //
    // The driver is requesting that the DXGI runtime not use shared resources to communicate with the Desktop Window Manager.
    //
    DXGI_STATUS_NO_REDIRECTION = 0x087A0004L,

    //
    // MessageId: DXGI_STATUS_NO_DESKTOP_ACCESS
    //
    // MessageText:
    //
    // The Present operation was not visible because the Windows session has switched to another desktop (for example, ctrl-alt-del).
    //
    DXGI_STATUS_NO_DESKTOP_ACCESS = 0x087A0005L,

    //
    // MessageId: DXGI_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE
    //
    // MessageText:
    //
    // The Present operation was not visible because the target monitor was being used for some other purpose.
    //
    DXGI_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE = 0x087A0006L,

    //
    // MessageId: DXGI_STATUS_MODE_CHANGED
    //
    // MessageText:
    //
    // The Present operation was not visible because the display mode changed. DXGI will have re-attempted the presentation.
    //
    DXGI_STATUS_MODE_CHANGED = 0x087A0007L,

    //
    // MessageId: DXGI_STATUS_MODE_CHANGE_IN_PROGRESS
    //
    // MessageText:
    //
    // The Present operation was not visible because another Direct3D device was attempting to take fullscreen mode at the time.
    //
    DXGI_STATUS_MODE_CHANGE_IN_PROGRESS = 0x087A0008L,

    //
    // DXGI error codes
    //

    //
    // MessageId: DXGI_ERROR_INVALID_CALL
    //
    // MessageText:
    //
    // The application made a call that is invalid. Either the parameters of the call or the state of some object was incorrect.
    // Enable the D3D debug layer in order to see details via debug messages.
    //
    DXGI_ERROR_INVALID_CALL = 0x887A0001L,

    //
    // MessageId: DXGI_ERROR_NOT_FOUND
    //
    // MessageText:
    //
    // The object was not found. If calling IDXGIFactory::EnumAdaptes, there is no adapter with the specified ordinal.
    //
    DXGI_ERROR_NOT_FOUND = 0x887A0002L,

    //
    // MessageId: DXGI_ERROR_MORE_DATA
    //
    // MessageText:
    //
    // The caller did not supply a sufficiently large buffer.
    //
    DXGI_ERROR_MORE_DATA = 0x887A0003L,

    //
    // MessageId: DXGI_ERROR_UNSUPPORTED
    //
    // MessageText:
    //
    // The specified device interface or feature level is not supported on this system.
    //
    DXGI_ERROR_UNSUPPORTED = 0x887A0004L,

    //
    // MessageId: DXGI_ERROR_DEVICE_REMOVED
    //
    // MessageText:
    //
    // The GPU device instance has been suspended. Use GetDeviceRemovedReason to determine the appropriate action.
    //
    DXGI_ERROR_DEVICE_REMOVED = 0x887A0005L,

    //
    // MessageId: DXGI_ERROR_DEVICE_HUNG
    //
    // MessageText:
    //
    // The GPU will not respond to more commands, most likely because of an invalid command passed by the calling application.
    //
    DXGI_ERROR_DEVICE_HUNG = 0x887A0006L,

    //
    // MessageId: DXGI_ERROR_DEVICE_RESET
    //
    // MessageText:
    //
    // The GPU will not respond to more commands, most likely because some other application submitted invalid commands.
    // The calling application should re-create the device and continue.
    //
    DXGI_ERROR_DEVICE_RESET = 0x887A0007L,

    //
    // MessageId: DXGI_ERROR_WAS_STILL_DRAWING
    //
    // MessageText:
    //
    // The GPU was busy at the moment when the call was made, and the call was neither executed nor scheduled.
    //
    DXGI_ERROR_WAS_STILL_DRAWING = 0x887A000AL,

    //
    // MessageId: DXGI_ERROR_FRAME_STATISTICS_DISJOINT
    //
    // MessageText:
    //
    // An event (such as power cycle) interrupted the gathering of presentation statistics. Any previous statistics should be
    // considered invalid.
    //
    DXGI_ERROR_FRAME_STATISTICS_DISJOINT = 0x887A000BL,

    //
    // MessageId: DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE
    //
    // MessageText:
    //
    // Fullscreen mode could not be achieved because the specified output was already in use.
    //
    DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE = 0x887A000CL,

    //
    // MessageId: DXGI_ERROR_DRIVER_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal issue prevented the driver from carrying out the specified operation. The driver's state is probably suspect,
    // and the application should not continue.
    //
    DXGI_ERROR_DRIVER_INTERNAL_ERROR = 0x887A0020L,

    //
    // MessageId: DXGI_ERROR_NONEXCLUSIVE
    //
    // MessageText:
    //
    // A global counter resource was in use, and the specified counter cannot be used by this Direct3D device at this time.
    //
    DXGI_ERROR_NONEXCLUSIVE = 0x887A0021L,

    //
    // MessageId: DXGI_ERROR_NOT_CURRENTLY_AVAILABLE
    //
    // MessageText:
    //
    // A resource is not available at the time of the call, but may become available later.
    //
    DXGI_ERROR_NOT_CURRENTLY_AVAILABLE = 0x887A0022L,

    //
    // MessageId: DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED
    //
    // MessageText:
    //
    // The application's remote device has been removed due to session disconnect or network disconnect.
    // The application should call IDXGIFactory1::IsCurrent to find out when the remote device becomes available again.
    //
    DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED = 0x887A0023L,

    //
    // MessageId: DXGI_ERROR_REMOTE_OUTOFMEMORY
    //
    // MessageText:
    //
    // The device has been removed during a remote session because the remote computer ran out of memory.
    //
    DXGI_ERROR_REMOTE_OUTOFMEMORY = 0x887A0024L,

    //
    // MessageId: DXGI_ERROR_ACCESS_LOST
    //
    // MessageText:
    //
    // The keyed mutex was abandoned.
    //
    DXGI_ERROR_ACCESS_LOST = 0x887A0026L,

    //
    // MessageId: DXGI_ERROR_WAIT_TIMEOUT
    //
    // MessageText:
    //
    // The timeout value has elapsed and the resource is not yet available.
    //
    DXGI_ERROR_WAIT_TIMEOUT = 0x887A0027L,

    //
    // MessageId: DXGI_ERROR_SESSION_DISCONNECTED
    //
    // MessageText:
    //
    // The output duplication has been turned off because the Windows session ended or was disconnected.
    // This happens when a remote user disconnects, or when "switch user" is used locally.
    //
    DXGI_ERROR_SESSION_DISCONNECTED = 0x887A0028L,

    //
    // MessageId: DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE
    //
    // MessageText:
    //
    // The DXGI outuput (monitor) to which the swapchain content was restricted, has been disconnected or changed.
    //
    DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE = 0x887A0029L,

    //
    // MessageId: DXGI_ERROR_CANNOT_PROTECT_CONTENT
    //
    // MessageText:
    //
    // DXGI is unable to provide content protection on the swapchain. This is typically caused by an older driver,
    // or by the application using a swapchain that is incompatible with content protection.
    //
    DXGI_ERROR_CANNOT_PROTECT_CONTENT = 0x887A002AL,

    //
    // MessageId: DXGI_ERROR_ACCESS_DENIED
    //
    // MessageText:
    //
    // The application is trying to use a resource to which it does not have the required access privileges.
    // This is most commonly caused by writing to a shared resource with read-only access.
    //
    DXGI_ERROR_ACCESS_DENIED = 0x887A002BL,

    //
    // MessageId: DXGI_ERROR_NAME_ALREADY_EXISTS
    //
    // MessageText:
    //
    // The application is trying to create a shared handle using a name that is already associated with some other resource.
    //
    DXGI_ERROR_NAME_ALREADY_EXISTS = 0x887A002CL,

    //
    // MessageId: DXGI_ERROR_SDK_COMPONENT_MISSING
    //
    // MessageText:
    //
    // The application requested an operation that depends on an SDK component that is missing or mismatched.
    //
    DXGI_ERROR_SDK_COMPONENT_MISSING = 0x887A002DL,

    //
    // DXGI errors that are internal to the Desktop Window Manager
    //

    //
    // MessageId: DXGI_STATUS_UNOCCLUDED
    //
    // MessageText:
    //
    // The swapchain has become unoccluded.
    //
    DXGI_STATUS_UNOCCLUDED = 0x087A0009L,

    //
    // MessageId: DXGI_STATUS_DDA_WAS_STILL_DRAWING
    //
    // MessageText:
    //
    // The adapter did not have access to the required resources to complete the Desktop Duplication Present() call, the Present() call needs to be made again
    //
    DXGI_STATUS_DDA_WAS_STILL_DRAWING = 0x087A000AL,

    //
    // MessageId: DXGI_ERROR_MODE_CHANGE_IN_PROGRESS
    //
    // MessageText:
    //
    // An on-going mode change prevented completion of the call. The call may succeed if attempted later.
    //
    DXGI_ERROR_MODE_CHANGE_IN_PROGRESS = 0x887A0025L,

    //
    // DXGI DDI
    //

    //
    // MessageId: DXGI_DDI_ERR_WASSTILLDRAWING
    //
    // MessageText:
    //
    // The GPU was busy when the operation was requested.
    //
    DXGI_DDI_ERR_WASSTILLDRAWING = 0x887B0001L,

    //
    // MessageId: DXGI_DDI_ERR_UNSUPPORTED
    //
    // MessageText:
    //
    // The driver has rejected the creation of this resource.
    //
    DXGI_DDI_ERR_UNSUPPORTED = 0x887B0002L,

    //
    // MessageId: DXGI_DDI_ERR_NONEXCLUSIVE
    //
    // MessageText:
    //
    // The GPU counter was in use by another process or d3d device when application requested access to it.
    //
    DXGI_DDI_ERR_NONEXCLUSIVE = 0x887B0003L,

    //
    // Direct3D10
    //

    //
    // MessageId: D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS
    //
    // MessageText:
    //
    // The application has exceeded the maximum number of unique state objects per Direct3D device.
    // The limit is 4096 for feature levels up to 11.1.
    //
    D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS = 0x88790001L,

    //
    // MessageId: D3D10_ERROR_FILE_NOT_FOUND
    //
    // MessageText:
    //
    // The specified file was not found.
    //
    D3D10_ERROR_FILE_NOT_FOUND = 0x88790002L,

    //
    // Direct3D11
    //

    //
    // MessageId: D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS
    //
    // MessageText:
    //
    // The application has exceeded the maximum number of unique state objects per Direct3D device.
    // The limit is 4096 for feature levels up to 11.1.
    //
    D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS = 0x887C0001L,

    //
    // MessageId: D3D11_ERROR_FILE_NOT_FOUND
    //
    // MessageText:
    //
    // The specified file was not found.
    //
    D3D11_ERROR_FILE_NOT_FOUND = 0x887C0002L,

    //
    // MessageId: D3D11_ERROR_TOO_MANY_UNIQUE_VIEW_OBJECTS
    //
    // MessageText:
    //
    // The application has exceeded the maximum number of unique view objects per Direct3D device.
    // The limit is 2^20 for feature levels up to 11.1.
    //
    D3D11_ERROR_TOO_MANY_UNIQUE_VIEW_OBJECTS = 0x887C0003L,

    //
    // MessageId: D3D11_ERROR_DEFERRED_CONTEXT_MAP_WITHOUT_INITIAL_DISCARD
    //
    // MessageText:
    //
    // The application's first call per command list to Map on a deferred context did not use D3D11_MAP_WRITE_DISCARD.
    //
    D3D11_ERROR_DEFERRED_CONTEXT_MAP_WITHOUT_INITIAL_DISCARD = 0x887C0004L,

    //
    // Direct2D
    //

    //
    // MessageId: D2DERR_WRONG_STATE
    //
    // MessageText:
    //
    // The object was not in the correct state to process the method.
    //
    D2DERR_WRONG_STATE = 0x88990001L,

    //
    // MessageId: D2DERR_NOT_INITIALIZED
    //
    // MessageText:
    //
    // The object has not yet been initialized.
    //
    D2DERR_NOT_INITIALIZED = 0x88990002L,

    //
    // MessageId: D2DERR_UNSUPPORTED_OPERATION
    //
    // MessageText:
    //
    // The requested operation is not supported.
    //
    D2DERR_UNSUPPORTED_OPERATION = 0x88990003L,

    //
    // MessageId: D2DERR_SCANNER_FAILED
    //
    // MessageText:
    //
    // The geometry scanner failed to process the data.
    //
    D2DERR_SCANNER_FAILED = 0x88990004L,

    //
    // MessageId: D2DERR_SCREEN_ACCESS_DENIED
    //
    // MessageText:
    //
    // Direct2D could not access the screen.
    //
    D2DERR_SCREEN_ACCESS_DENIED = 0x88990005L,

    //
    // MessageId: D2DERR_DISPLAY_STATE_INVALID
    //
    // MessageText:
    //
    // A valid display state could not be determined.
    //
    D2DERR_DISPLAY_STATE_INVALID = 0x88990006L,

    //
    // MessageId: D2DERR_ZERO_VECTOR
    //
    // MessageText:
    //
    // The supplied vector is zero.
    //
    D2DERR_ZERO_VECTOR = 0x88990007L,

    //
    // MessageId: D2DERR_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal error (Direct2D bug) occurred. On checked builds, we would assert. The application should close this instance of Direct2D and should consider restarting its process.
    //
    D2DERR_INTERNAL_ERROR = 0x88990008L,

    //
    // MessageId: D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The display format Direct2D needs to render is not supported by the hardware device.
    //
    D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED = 0x88990009L,

    //
    // MessageId: D2DERR_INVALID_CALL
    //
    // MessageText:
    //
    // A call to this method is invalid.
    //
    D2DERR_INVALID_CALL = 0x8899000AL,

    //
    // MessageId: D2DERR_NO_HARDWARE_DEVICE
    //
    // MessageText:
    //
    // No hardware rendering device is available for this operation.
    //
    D2DERR_NO_HARDWARE_DEVICE = 0x8899000BL,

    //
    // MessageId: D2DERR_RECREATE_TARGET
    //
    // MessageText:
    //
    // There has been a presentation error that may be recoverable. The caller needs to recreate, rerender the entire frame, and reattempt present.
    //
    D2DERR_RECREATE_TARGET = 0x8899000CL,

    //
    // MessageId: D2DERR_TOO_MANY_SHADER_ELEMENTS
    //
    // MessageText:
    //
    // Shader construction failed because it was too complex.
    //
    D2DERR_TOO_MANY_SHADER_ELEMENTS = 0x8899000DL,

    //
    // MessageId: D2DERR_SHADER_COMPILE_FAILED
    //
    // MessageText:
    //
    // Shader compilation failed.
    //
    D2DERR_SHADER_COMPILE_FAILED = 0x8899000EL,

    //
    // MessageId: D2DERR_MAX_TEXTURE_SIZE_EXCEEDED
    //
    // MessageText:
    //
    // Requested DirectX surface size exceeded maximum texture size.
    //
    D2DERR_MAX_TEXTURE_SIZE_EXCEEDED = 0x8899000FL,

    //
    // MessageId: D2DERR_UNSUPPORTED_VERSION
    //
    // MessageText:
    //
    // The requested Direct2D version is not supported.
    //
    D2DERR_UNSUPPORTED_VERSION = 0x88990010L,

    //
    // MessageId: D2DERR_BAD_NUMBER
    //
    // MessageText:
    //
    // Invalid number.
    //
    D2DERR_BAD_NUMBER = 0x88990011L,

    //
    // MessageId: D2DERR_WRONG_FACTORY
    //
    // MessageText:
    //
    // Objects used together must be created from the same factory instance.
    //
    D2DERR_WRONG_FACTORY = 0x88990012L,

    //
    // MessageId: D2DERR_LAYER_ALREADY_IN_USE
    //
    // MessageText:
    //
    // A layer resource can only be in use once at any point in time.
    //
    D2DERR_LAYER_ALREADY_IN_USE = 0x88990013L,

    //
    // MessageId: D2DERR_POP_CALL_DID_NOT_MATCH_PUSH
    //
    // MessageText:
    //
    // The pop call did not match the corresponding push call.
    //
    D2DERR_POP_CALL_DID_NOT_MATCH_PUSH = 0x88990014L,

    //
    // MessageId: D2DERR_WRONG_RESOURCE_DOMAIN
    //
    // MessageText:
    //
    // The resource was realized on the wrong render target.
    //
    D2DERR_WRONG_RESOURCE_DOMAIN = 0x88990015L,

    //
    // MessageId: D2DERR_PUSH_POP_UNBALANCED
    //
    // MessageText:
    //
    // The push and pop calls were unbalanced.
    //
    D2DERR_PUSH_POP_UNBALANCED = 0x88990016L,

    //
    // MessageId: D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT
    //
    // MessageText:
    //
    // Attempt to copy from a render target while a layer or clip rect is applied.
    //
    D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT = 0x88990017L,

    //
    // MessageId: D2DERR_INCOMPATIBLE_BRUSH_TYPES
    //
    // MessageText:
    //
    // The brush types are incompatible for the call.
    //
    D2DERR_INCOMPATIBLE_BRUSH_TYPES = 0x88990018L,

    //
    // MessageId: D2DERR_WIN32_ERROR
    //
    // MessageText:
    //
    // An unknown win32 failure occurred.
    //
    D2DERR_WIN32_ERROR = 0x88990019L,

    //
    // MessageId: D2DERR_TARGET_NOT_GDI_COMPATIBLE
    //
    // MessageText:
    //
    // The render target is not compatible with GDI.
    //
    D2DERR_TARGET_NOT_GDI_COMPATIBLE = 0x8899001AL,

    //
    // MessageId: D2DERR_TEXT_EFFECT_IS_WRONG_TYPE
    //
    // MessageText:
    //
    // A text client drawing effect object is of the wrong type.
    //
    D2DERR_TEXT_EFFECT_IS_WRONG_TYPE = 0x8899001BL,

    //
    // MessageId: D2DERR_TEXT_RENDERER_NOT_RELEASED
    //
    // MessageText:
    //
    // The application is holding a reference to the IDWriteTextRenderer interface after the corresponding DrawText or DrawTextLayout call has returned. The IDWriteTextRenderer instance will be invalid.
    //
    D2DERR_TEXT_RENDERER_NOT_RELEASED = 0x8899001CL,

    //
    // MessageId: D2DERR_EXCEEDS_MAX_BITMAP_SIZE
    //
    // MessageText:
    //
    // The requested size is larger than the guaranteed supported texture size at the Direct3D device's current feature level.
    //
    D2DERR_EXCEEDS_MAX_BITMAP_SIZE = 0x8899001DL,

    //
    // MessageId: D2DERR_INVALID_GRAPH_CONFIGURATION
    //
    // MessageText:
    //
    // There was a configuration error in the graph.
    //
    D2DERR_INVALID_GRAPH_CONFIGURATION = 0x8899001EL,

    //
    // MessageId: D2DERR_INVALID_INTERNAL_GRAPH_CONFIGURATION
    //
    // MessageText:
    //
    // There was a internal configuration error in the graph.
    //
    D2DERR_INVALID_INTERNAL_GRAPH_CONFIGURATION = 0x8899001FL,

    //
    // MessageId: D2DERR_CYCLIC_GRAPH
    //
    // MessageText:
    //
    // There was a cycle in the graph.
    //
    D2DERR_CYCLIC_GRAPH = 0x88990020L,

    //
    // MessageId: D2DERR_BITMAP_CANNOT_DRAW
    //
    // MessageText:
    //
    // Cannot draw with a bitmap that has the D2D1_BITMAP_OPTIONS_CANNOT_DRAW option.
    //
    D2DERR_BITMAP_CANNOT_DRAW = 0x88990021L,

    //
    // MessageId: D2DERR_OUTSTANDING_BITMAP_REFERENCES
    //
    // MessageText:
    //
    // The operation cannot complete while there are outstanding references to the target bitmap.
    //
    D2DERR_OUTSTANDING_BITMAP_REFERENCES = 0x88990022L,

    //
    // MessageId: D2DERR_ORIGINAL_TARGET_NOT_BOUND
    //
    // MessageText:
    //
    // The operation failed because the original target is not currently bound as a target.
    //
    D2DERR_ORIGINAL_TARGET_NOT_BOUND = 0x88990023L,

    //
    // MessageId: D2DERR_INVALID_TARGET
    //
    // MessageText:
    //
    // Cannot set the image as a target because it is either an effect or is a bitmap that does not have the D2D1_BITMAP_OPTIONS_TARGET flag set.
    //
    D2DERR_INVALID_TARGET = 0x88990024L,

    //
    // MessageId: D2DERR_BITMAP_BOUND_AS_TARGET
    //
    // MessageText:
    //
    // Cannot draw with a bitmap that is currently bound as the target bitmap.
    //
    D2DERR_BITMAP_BOUND_AS_TARGET = 0x88990025L,

    //
    // MessageId: D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES
    //
    // MessageText:
    //
    // D3D Device does not have sufficient capabilities to perform the requested action.
    //
    D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES = 0x88990026L,

    //
    // MessageId: D2DERR_INTERMEDIATE_TOO_LARGE
    //
    // MessageText:
    //
    // The graph could not be rendered with the context's current tiling settings.
    //
    D2DERR_INTERMEDIATE_TOO_LARGE = 0x88990027L,

    //
    // MessageId: D2DERR_EFFECT_IS_NOT_REGISTERED
    //
    // MessageText:
    //
    // The CLSID provided to Unregister did not correspond to a registered effect.
    //
    D2DERR_EFFECT_IS_NOT_REGISTERED = 0x88990028L,

    //
    // MessageId: D2DERR_INVALID_PROPERTY
    //
    // MessageText:
    //
    // The specified property does not exist.
    //
    D2DERR_INVALID_PROPERTY = 0x88990029L,

    //
    // MessageId: D2DERR_NO_SUBPROPERTIES
    //
    // MessageText:
    //
    // The specified sub-property does not exist.
    //
    D2DERR_NO_SUBPROPERTIES = 0x8899002AL,

    //
    // MessageId: D2DERR_PRINT_JOB_CLOSED
    //
    // MessageText:
    //
    // AddPage or Close called after print job is already closed.
    //
    D2DERR_PRINT_JOB_CLOSED = 0x8899002BL,

    //
    // MessageId: D2DERR_PRINT_FORMAT_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Error during print control creation. Indicates that none of the package target types (representing printer formats) are supported by Direct2D print control.
    //
    D2DERR_PRINT_FORMAT_NOT_SUPPORTED = 0x8899002CL,

    //
    // MessageId: D2DERR_TOO_MANY_TRANSFORM_INPUTS
    //
    // MessageText:
    //
    // An effect attempted to use a transform with too many inputs.
    //
    D2DERR_TOO_MANY_TRANSFORM_INPUTS = 0x8899002DL,

    //
    // DirectWrite
    //

    //
    // MessageId: DWRITE_E_FILEFORMAT
    //
    // MessageText:
    //
    // Indicates an error in an input file such as a font file.
    //
    DWRITE_E_FILEFORMAT = 0x88985000L,

    //
    // MessageId: DWRITE_E_UNEXPECTED
    //
    // MessageText:
    //
    // Indicates an error originating in DirectWrite code, which is not expected to occur but is safe to recover from.
    //
    DWRITE_E_UNEXPECTED = 0x88985001L,

    //
    // MessageId: DWRITE_E_NOFONT
    //
    // MessageText:
    //
    // Indicates the specified font does not exist.
    //
    DWRITE_E_NOFONT = 0x88985002L,

    //
    // MessageId: DWRITE_E_FILENOTFOUND
    //
    // MessageText:
    //
    // A font file could not be opened because the file, directory, network location, drive, or other storage location does not exist or is unavailable.
    //
    DWRITE_E_FILENOTFOUND = 0x88985003L,

    //
    // MessageId: DWRITE_E_FILEACCESS
    //
    // MessageText:
    //
    // A font file exists but could not be opened due to access denied, sharing violation, or similar error.
    //
    DWRITE_E_FILEACCESS = 0x88985004L,

    //
    // MessageId: DWRITE_E_FONTCOLLECTIONOBSOLETE
    //
    // MessageText:
    //
    // A font collection is obsolete due to changes in the system.
    //
    DWRITE_E_FONTCOLLECTIONOBSOLETE = 0x88985005L,

    //
    // MessageId: DWRITE_E_ALREADYREGISTERED
    //
    // MessageText:
    //
    // The given interface is already registered.
    //
    DWRITE_E_ALREADYREGISTERED = 0x88985006L,

    //
    // MessageId: DWRITE_E_CACHEFORMAT
    //
    // MessageText:
    //
    // The font cache contains invalid data.
    //
    DWRITE_E_CACHEFORMAT = 0x88985007L,

    //
    // MessageId: DWRITE_E_CACHEVERSION
    //
    // MessageText:
    //
    // A font cache file corresponds to a different version of DirectWrite.
    //
    DWRITE_E_CACHEVERSION = 0x88985008L,

    //
    // MessageId: DWRITE_E_UNSUPPORTEDOPERATION
    //
    // MessageText:
    //
    // The operation is not supported for this type of font.
    //
    DWRITE_E_UNSUPPORTEDOPERATION = 0x88985009L,

    //
    // MessageId: DWRITE_E_TEXTRENDERERINCOMPATIBLE
    //
    // MessageText:
    //
    // The version of the text renderer interface is not compatible.
    //
    DWRITE_E_TEXTRENDERERINCOMPATIBLE = 0x8898500AL,

    //
    // MessageId: DWRITE_E_FLOWDIRECTIONCONFLICTS
    //
    // MessageText:
    //
    // The flow direction conflicts with the reading direction. They must be perpendicular to each other.
    //
    DWRITE_E_FLOWDIRECTIONCONFLICTS = 0x8898500BL,

    //
    // MessageId: DWRITE_E_NOCOLOR
    //
    // MessageText:
    //
    // The font or glyph run does not contain any colored glyphs.
    //
    DWRITE_E_NOCOLOR = 0x8898500CL,

    //
    // Windows Codecs
    //

    //
    // MessageId: WINCODEC_ERR_WRONGSTATE
    //
    // MessageText:
    //
    // The codec is in the wrong state.
    //
    WINCODEC_ERR_WRONGSTATE = 0x88982F04L,

    //
    // MessageId: WINCODEC_ERR_VALUEOUTOFRANGE
    //
    // MessageText:
    //
    // The value is out of range.
    //
    WINCODEC_ERR_VALUEOUTOFRANGE = 0x88982F05L,

    //
    // MessageId: WINCODEC_ERR_UNKNOWNIMAGEFORMAT
    //
    // MessageText:
    //
    // The image format is unknown.
    //
    WINCODEC_ERR_UNKNOWNIMAGEFORMAT = 0x88982F07L,

    //
    // MessageId: WINCODEC_ERR_UNSUPPORTEDVERSION
    //
    // MessageText:
    //
    // The SDK version is unsupported.
    //
    WINCODEC_ERR_UNSUPPORTEDVERSION = 0x88982F0BL,

    //
    // MessageId: WINCODEC_ERR_NOTINITIALIZED
    //
    // MessageText:
    //
    // The component is not initialized.
    //
    WINCODEC_ERR_NOTINITIALIZED = 0x88982F0CL,

    //
    // MessageId: WINCODEC_ERR_ALREADYLOCKED
    //
    // MessageText:
    //
    // There is already an outstanding read or write lock.
    //
    WINCODEC_ERR_ALREADYLOCKED = 0x88982F0DL,

    //
    // MessageId: WINCODEC_ERR_PROPERTYNOTFOUND
    //
    // MessageText:
    //
    // The specified bitmap property cannot be found.
    //
    WINCODEC_ERR_PROPERTYNOTFOUND = 0x88982F40L,

    //
    // MessageId: WINCODEC_ERR_PROPERTYNOTSUPPORTED
    //
    // MessageText:
    //
    // The bitmap codec does not support the bitmap property.
    //
    WINCODEC_ERR_PROPERTYNOTSUPPORTED = 0x88982F41L,

    //
    // MessageId: WINCODEC_ERR_PROPERTYSIZE
    //
    // MessageText:
    //
    // The bitmap property size is invalid.
    //
    WINCODEC_ERR_PROPERTYSIZE = 0x88982F42L,

    //
    // MessageId: WINCODEC_ERR_CODECPRESENT
    //
    // MessageText:
    //
    // An unknown error has occurred.
    //
    WINCODEC_ERR_CODECPRESENT = 0x88982F43L,

    //
    // MessageId: WINCODEC_ERR_CODECNOTHUMBNAIL
    //
    // MessageText:
    //
    // The bitmap codec does not support a thumbnail.
    //
    WINCODEC_ERR_CODECNOTHUMBNAIL = 0x88982F44L,

    //
    // MessageId: WINCODEC_ERR_PALETTEUNAVAILABLE
    //
    // MessageText:
    //
    // The bitmap palette is unavailable.
    //
    WINCODEC_ERR_PALETTEUNAVAILABLE = 0x88982F45L,

    //
    // MessageId: WINCODEC_ERR_CODECTOOMANYSCANLINES
    //
    // MessageText:
    //
    // Too many scanlines were requested.
    //
    WINCODEC_ERR_CODECTOOMANYSCANLINES = 0x88982F46L,

    //
    // MessageId: WINCODEC_ERR_INTERNALERROR
    //
    // MessageText:
    //
    // An internal error occurred.
    //
    WINCODEC_ERR_INTERNALERROR = 0x88982F48L,

    //
    // MessageId: WINCODEC_ERR_SOURCERECTDOESNOTMATCHDIMENSIONS
    //
    // MessageText:
    //
    // The bitmap bounds do not match the bitmap dimensions.
    //
    WINCODEC_ERR_SOURCERECTDOESNOTMATCHDIMENSIONS = 0x88982F49L,

    //
    // MessageId: WINCODEC_ERR_COMPONENTNOTFOUND
    //
    // MessageText:
    //
    // The component cannot be found.
    //
    WINCODEC_ERR_COMPONENTNOTFOUND = 0x88982F50L,

    //
    // MessageId: WINCODEC_ERR_IMAGESIZEOUTOFRANGE
    //
    // MessageText:
    //
    // The bitmap size is outside the valid range.
    //
    WINCODEC_ERR_IMAGESIZEOUTOFRANGE = 0x88982F51L,

    //
    // MessageId: WINCODEC_ERR_TOOMUCHMETADATA
    //
    // MessageText:
    //
    // There is too much metadata to be written to the bitmap.
    //
    WINCODEC_ERR_TOOMUCHMETADATA = 0x88982F52L,

    //
    // MessageId: WINCODEC_ERR_BADIMAGE
    //
    // MessageText:
    //
    // The image is unrecognized.
    //
    WINCODEC_ERR_BADIMAGE = 0x88982F60L,

    //
    // MessageId: WINCODEC_ERR_BADHEADER
    //
    // MessageText:
    //
    // The image header is unrecognized.
    //
    WINCODEC_ERR_BADHEADER = 0x88982F61L,

    //
    // MessageId: WINCODEC_ERR_FRAMEMISSING
    //
    // MessageText:
    //
    // The bitmap frame is missing.
    //
    WINCODEC_ERR_FRAMEMISSING = 0x88982F62L,

    //
    // MessageId: WINCODEC_ERR_BADMETADATAHEADER
    //
    // MessageText:
    //
    // The image metadata header is unrecognized.
    //
    WINCODEC_ERR_BADMETADATAHEADER = 0x88982F63L,

    //
    // MessageId: WINCODEC_ERR_BADSTREAMDATA
    //
    // MessageText:
    //
    // The stream data is unrecognized.
    //
    WINCODEC_ERR_BADSTREAMDATA = 0x88982F70L,

    //
    // MessageId: WINCODEC_ERR_STREAMWRITE
    //
    // MessageText:
    //
    // Failed to write to the stream.
    //
    WINCODEC_ERR_STREAMWRITE = 0x88982F71L,

    //
    // MessageId: WINCODEC_ERR_STREAMREAD
    //
    // MessageText:
    //
    // Failed to read from the stream.
    //
    WINCODEC_ERR_STREAMREAD = 0x88982F72L,

    //
    // MessageId: WINCODEC_ERR_STREAMNOTAVAILABLE
    //
    // MessageText:
    //
    // The stream is not available.
    //
    WINCODEC_ERR_STREAMNOTAVAILABLE = 0x88982F73L,

    //
    // MessageId: WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT
    //
    // MessageText:
    //
    // The bitmap pixel format is unsupported.
    //
    WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT = 0x88982F80L,

    //
    // MessageId: WINCODEC_ERR_UNSUPPORTEDOPERATION
    //
    // MessageText:
    //
    // The operation is unsupported.
    //
    WINCODEC_ERR_UNSUPPORTEDOPERATION = 0x88982F81L,

    //
    // MessageId: WINCODEC_ERR_INVALIDREGISTRATION
    //
    // MessageText:
    //
    // The component registration is invalid.
    //
    WINCODEC_ERR_INVALIDREGISTRATION = 0x88982F8AL,

    //
    // MessageId: WINCODEC_ERR_COMPONENTINITIALIZEFAILURE
    //
    // MessageText:
    //
    // The component initialization has failed.
    //
    WINCODEC_ERR_COMPONENTINITIALIZEFAILURE = 0x88982F8BL,

    //
    // MessageId: WINCODEC_ERR_INSUFFICIENTBUFFER
    //
    // MessageText:
    //
    // The buffer allocated is insufficient.
    //
    WINCODEC_ERR_INSUFFICIENTBUFFER = 0x88982F8CL,

    //
    // MessageId: WINCODEC_ERR_DUPLICATEMETADATAPRESENT
    //
    // MessageText:
    //
    // Duplicate metadata is present.
    //
    WINCODEC_ERR_DUPLICATEMETADATAPRESENT = 0x88982F8DL,

    //
    // MessageId: WINCODEC_ERR_PROPERTYUNEXPECTEDTYPE
    //
    // MessageText:
    //
    // The bitmap property type is unexpected.
    //
    WINCODEC_ERR_PROPERTYUNEXPECTEDTYPE = 0x88982F8EL,

    //
    // MessageId: WINCODEC_ERR_UNEXPECTEDSIZE
    //
    // MessageText:
    //
    // The size is unexpected.
    //
    WINCODEC_ERR_UNEXPECTEDSIZE = 0x88982F8FL,

    //
    // MessageId: WINCODEC_ERR_INVALIDQUERYREQUEST
    //
    // MessageText:
    //
    // The property query is invalid.
    //
    WINCODEC_ERR_INVALIDQUERYREQUEST = 0x88982F90L,

    //
    // MessageId: WINCODEC_ERR_UNEXPECTEDMETADATATYPE
    //
    // MessageText:
    //
    // The metadata type is unexpected.
    //
    WINCODEC_ERR_UNEXPECTEDMETADATATYPE = 0x88982F91L,

    //
    // MessageId: WINCODEC_ERR_REQUESTONLYVALIDATMETADATAROOT
    //
    // MessageText:
    //
    // The specified bitmap property is only valid at root level.
    //
    WINCODEC_ERR_REQUESTONLYVALIDATMETADATAROOT = 0x88982F92L,

    //
    // MessageId: WINCODEC_ERR_INVALIDQUERYCHARACTER
    //
    // MessageText:
    //
    // The query string contains an invalid character.
    //
    WINCODEC_ERR_INVALIDQUERYCHARACTER = 0x88982F93L,

    //
    // MessageId: WINCODEC_ERR_WIN32ERROR
    //
    // MessageText:
    //
    // Windows Codecs received an error from the Win32 system.
    //
    WINCODEC_ERR_WIN32ERROR = 0x88982F94L,

    //
    // MessageId: WINCODEC_ERR_INVALIDPROGRESSIVELEVEL
    //
    // MessageText:
    //
    // The requested level of detail is not present.
    //
    WINCODEC_ERR_INVALIDPROGRESSIVELEVEL = 0x88982F95L,

    //
    // MIL/DWM
    //

    //
    // MessageId: MILERR_OBJECTBUSY
    //
    // MessageText:
    //
    // MILERR_OBJECTBUSY
    //
    MILERR_OBJECTBUSY = 0x88980001L,

    //
    // MessageId: MILERR_INSUFFICIENTBUFFER
    //
    // MessageText:
    //
    // MILERR_INSUFFICIENTBUFFER
    //
    MILERR_INSUFFICIENTBUFFER = 0x88980002L,

    //
    // MessageId: MILERR_WIN32ERROR
    //
    // MessageText:
    //
    // MILERR_WIN32ERROR
    //
    MILERR_WIN32ERROR = 0x88980003L,

    //
    // MessageId: MILERR_SCANNER_FAILED
    //
    // MessageText:
    //
    // MILERR_SCANNER_FAILED
    //
    MILERR_SCANNER_FAILED = 0x88980004L,

    //
    // MessageId: MILERR_SCREENACCESSDENIED
    //
    // MessageText:
    //
    // MILERR_SCREENACCESSDENIED
    //
    MILERR_SCREENACCESSDENIED = 0x88980005L,

    //
    // MessageId: MILERR_DISPLAYSTATEINVALID
    //
    // MessageText:
    //
    // MILERR_DISPLAYSTATEINVALID
    //
    MILERR_DISPLAYSTATEINVALID = 0x88980006L,

    //
    // MessageId: MILERR_NONINVERTIBLEMATRIX
    //
    // MessageText:
    //
    // MILERR_NONINVERTIBLEMATRIX
    //
    MILERR_NONINVERTIBLEMATRIX = 0x88980007L,

    //
    // MessageId: MILERR_ZEROVECTOR
    //
    // MessageText:
    //
    // MILERR_ZEROVECTOR
    //
    MILERR_ZEROVECTOR = 0x88980008L,

    //
    // MessageId: MILERR_TERMINATED
    //
    // MessageText:
    //
    // MILERR_TERMINATED
    //
    MILERR_TERMINATED = 0x88980009L,

    //
    // MessageId: MILERR_BADNUMBER
    //
    // MessageText:
    //
    // MILERR_BADNUMBER
    //
    MILERR_BADNUMBER = 0x8898000AL,

    //
    // MessageId: MILERR_INTERNALERROR
    //
    // MessageText:
    //
    // An internal error (MIL bug) occurred. On checked builds, an assert would be raised.
    //
    MILERR_INTERNALERROR = 0x88980080L,

    //
    // MessageId: MILERR_DISPLAYFORMATNOTSUPPORTED
    //
    // MessageText:
    //
    // The display format we need to render is not supported by the hardware device.
    //
    MILERR_DISPLAYFORMATNOTSUPPORTED = 0x88980084L,

    //
    // MessageId: MILERR_INVALIDCALL
    //
    // MessageText:
    //
    // A call to this method is invalid.
    //
    MILERR_INVALIDCALL = 0x88980085L,

    //
    // MessageId: MILERR_ALREADYLOCKED
    //
    // MessageText:
    //
    // Lock attempted on an already locked object.
    //
    MILERR_ALREADYLOCKED = 0x88980086L,

    //
    // MessageId: MILERR_NOTLOCKED
    //
    // MessageText:
    //
    // Unlock attempted on an unlocked object.
    //
    MILERR_NOTLOCKED = 0x88980087L,

    //
    // MessageId: MILERR_DEVICECANNOTRENDERTEXT
    //
    // MessageText:
    //
    // No algorithm avaliable to render text with this device
    //
    MILERR_DEVICECANNOTRENDERTEXT = 0x88980088L,

    //
    // MessageId: MILERR_GLYPHBITMAPMISSED
    //
    // MessageText:
    //
    // Some glyph bitmaps, required for glyph run rendering, are not contained in glyph cache.
    //
    MILERR_GLYPHBITMAPMISSED = 0x88980089L,

    //
    // MessageId: MILERR_MALFORMEDGLYPHCACHE
    //
    // MessageText:
    //
    // Some glyph bitmaps in glyph cache are unexpectedly big.
    //
    MILERR_MALFORMEDGLYPHCACHE = 0x8898008AL,

    //
    // MessageId: MILERR_GENERIC_IGNORE
    //
    // MessageText:
    //
    // Marker error for known Win32 errors that are currently being ignored by the compositor. This is to avoid returning S_OK when an error has occurred, but still unwind the stack in the correct location.
    //
    MILERR_GENERIC_IGNORE = 0x8898008BL,

    //
    // MessageId: MILERR_MALFORMED_GUIDELINE_DATA
    //
    // MessageText:
    //
    // Guideline coordinates are not sorted properly or contain NaNs.
    //
    MILERR_MALFORMED_GUIDELINE_DATA = 0x8898008CL,

    //
    // MessageId: MILERR_NO_HARDWARE_DEVICE
    //
    // MessageText:
    //
    // No HW rendering device is available for this operation.
    //
    MILERR_NO_HARDWARE_DEVICE = 0x8898008DL,

    //
    // MessageId: MILERR_NEED_RECREATE_AND_PRESENT
    //
    // MessageText:
    //
    // There has been a presentation error that may be recoverable. The caller needs to recreate, rerender the entire frame, and reattempt present.
    // There are two known case for this: 1) D3D Driver Internal error 2) D3D E_FAIL 2a) Unknown root cause b) When resizing too quickly for DWM and D3D stay in sync
    //
    MILERR_NEED_RECREATE_AND_PRESENT = 0x8898008EL,

    //
    // MessageId: MILERR_ALREADY_INITIALIZED
    //
    // MessageText:
    //
    // The object has already been initialized.
    //
    MILERR_ALREADY_INITIALIZED = 0x8898008FL,

    //
    // MessageId: MILERR_MISMATCHED_SIZE
    //
    // MessageText:
    //
    // The size of the object does not match the expected size.
    //
    MILERR_MISMATCHED_SIZE = 0x88980090L,

    //
    // MessageId: MILERR_NO_REDIRECTION_SURFACE_AVAILABLE
    //
    // MessageText:
    //
    // No Redirection surface available.
    //
    MILERR_NO_REDIRECTION_SURFACE_AVAILABLE = 0x88980091L,

    //
    // MessageId: MILERR_REMOTING_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Remoting of this content is not supported.
    //
    MILERR_REMOTING_NOT_SUPPORTED = 0x88980092L,

    //
    // MessageId: MILERR_QUEUED_PRESENT_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Queued Presents are not supported.
    //
    MILERR_QUEUED_PRESENT_NOT_SUPPORTED = 0x88980093L,

    //
    // MessageId: MILERR_NOT_QUEUING_PRESENTS
    //
    // MessageText:
    //
    // Queued Presents are not being used.
    //
    MILERR_NOT_QUEUING_PRESENTS = 0x88980094L,

    //
    // MessageId: MILERR_NO_REDIRECTION_SURFACE_RETRY_LATER
    //
    // MessageText:
    //
    // No redirection surface was available. Caller should retry the call.
    //
    MILERR_NO_REDIRECTION_SURFACE_RETRY_LATER = 0x88980095L,

    //
    // MessageId: MILERR_TOOMANYSHADERELEMNTS
    //
    // MessageText:
    //
    // Shader construction failed because it was too complex.
    //
    MILERR_TOOMANYSHADERELEMNTS = 0x88980096L,

    //
    // MessageId: MILERR_MROW_READLOCK_FAILED
    //
    // MessageText:
    //
    // MROW attempt to get a read lock failed.
    //
    MILERR_MROW_READLOCK_FAILED = 0x88980097L,

    //
    // MessageId: MILERR_MROW_UPDATE_FAILED
    //
    // MessageText:
    //
    // MROW attempt to update the data failed because another update was outstanding.
    //
    MILERR_MROW_UPDATE_FAILED = 0x88980098L,

    //
    // MessageId: MILERR_SHADER_COMPILE_FAILED
    //
    // MessageText:
    //
    // Shader compilation failed.
    //
    MILERR_SHADER_COMPILE_FAILED = 0x88980099L,

    //
    // MessageId: MILERR_MAX_TEXTURE_SIZE_EXCEEDED
    //
    // MessageText:
    //
    // Requested DX redirection surface size exceeded maximum texture size.
    //
    MILERR_MAX_TEXTURE_SIZE_EXCEEDED = 0x8898009AL,

    //
    // MessageId: MILERR_QPC_TIME_WENT_BACKWARD
    //
    // MessageText:
    //
    // QueryPerformanceCounter returned a time in the past.
    //
    MILERR_QPC_TIME_WENT_BACKWARD = 0x8898009BL,

    //
    // MessageId: MILERR_DXGI_ENUMERATION_OUT_OF_SYNC
    //
    // MessageText:
    //
    // Primary Display device returned an invalid refresh rate.
    //
    MILERR_DXGI_ENUMERATION_OUT_OF_SYNC = 0x8898009DL,

    //
    // MessageId: MILERR_ADAPTER_NOT_FOUND
    //
    // MessageText:
    //
    // DWM can not find the adapter specified by the LUID.
    //
    MILERR_ADAPTER_NOT_FOUND = 0x8898009EL,

    //
    // MessageId: MILERR_COLORSPACE_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The requested bitmap color space is not supported.
    //
    MILERR_COLORSPACE_NOT_SUPPORTED = 0x8898009FL,

    //
    // MessageId: MILERR_PREFILTER_NOT_SUPPORTED
    //
    // MessageText:
    //
    // The requested bitmap pre-filtering state is not supported.
    //
    MILERR_PREFILTER_NOT_SUPPORTED = 0x889800A0L,

    //
    // MessageId: MILERR_DISPLAYID_ACCESS_DENIED
    //
    // MessageText:
    //
    // Access is denied to the requested bitmap for the specified display id.
    //
    MILERR_DISPLAYID_ACCESS_DENIED = 0x889800A1L,

    // Composition engine errors
    //
    // MessageId: UCEERR_INVALIDPACKETHEADER
    //
    // MessageText:
    //
    // UCEERR_INVALIDPACKETHEADER
    //
    UCEERR_INVALIDPACKETHEADER = 0x88980400L,

    //
    // MessageId: UCEERR_UNKNOWNPACKET
    //
    // MessageText:
    //
    // UCEERR_UNKNOWNPACKET
    //
    UCEERR_UNKNOWNPACKET = 0x88980401L,

    //
    // MessageId: UCEERR_ILLEGALPACKET
    //
    // MessageText:
    //
    // UCEERR_ILLEGALPACKET
    //
    UCEERR_ILLEGALPACKET = 0x88980402L,

    //
    // MessageId: UCEERR_MALFORMEDPACKET
    //
    // MessageText:
    //
    // UCEERR_MALFORMEDPACKET
    //
    UCEERR_MALFORMEDPACKET = 0x88980403L,

    //
    // MessageId: UCEERR_ILLEGALHANDLE
    //
    // MessageText:
    //
    // UCEERR_ILLEGALHANDLE
    //
    UCEERR_ILLEGALHANDLE = 0x88980404L,

    //
    // MessageId: UCEERR_HANDLELOOKUPFAILED
    //
    // MessageText:
    //
    // UCEERR_HANDLELOOKUPFAILED
    //
    UCEERR_HANDLELOOKUPFAILED = 0x88980405L,

    //
    // MessageId: UCEERR_RENDERTHREADFAILURE
    //
    // MessageText:
    //
    // UCEERR_RENDERTHREADFAILURE
    //
    UCEERR_RENDERTHREADFAILURE = 0x88980406L,

    //
    // MessageId: UCEERR_CTXSTACKFRSTTARGETNULL
    //
    // MessageText:
    //
    // UCEERR_CTXSTACKFRSTTARGETNULL
    //
    UCEERR_CTXSTACKFRSTTARGETNULL = 0x88980407L,

    //
    // MessageId: UCEERR_CONNECTIONIDLOOKUPFAILED
    //
    // MessageText:
    //
    // UCEERR_CONNECTIONIDLOOKUPFAILED
    //
    UCEERR_CONNECTIONIDLOOKUPFAILED = 0x88980408L,

    //
    // MessageId: UCEERR_BLOCKSFULL
    //
    // MessageText:
    //
    // UCEERR_BLOCKSFULL
    //
    UCEERR_BLOCKSFULL = 0x88980409L,

    //
    // MessageId: UCEERR_MEMORYFAILURE
    //
    // MessageText:
    //
    // UCEERR_MEMORYFAILURE
    //
    UCEERR_MEMORYFAILURE = 0x8898040AL,

    //
    // MessageId: UCEERR_PACKETRECORDOUTOFRANGE
    //
    // MessageText:
    //
    // UCEERR_PACKETRECORDOUTOFRANGE
    //
    UCEERR_PACKETRECORDOUTOFRANGE = 0x8898040BL,

    //
    // MessageId: UCEERR_ILLEGALRECORDTYPE
    //
    // MessageText:
    //
    // UCEERR_ILLEGALRECORDTYPE
    //
    UCEERR_ILLEGALRECORDTYPE = 0x8898040CL,

    //
    // MessageId: UCEERR_OUTOFHANDLES
    //
    // MessageText:
    //
    // UCEERR_OUTOFHANDLES
    //
    UCEERR_OUTOFHANDLES = 0x8898040DL,

    //
    // MessageId: UCEERR_UNCHANGABLE_UPDATE_ATTEMPTED
    //
    // MessageText:
    //
    // UCEERR_UNCHANGABLE_UPDATE_ATTEMPTED
    //
    UCEERR_UNCHANGABLE_UPDATE_ATTEMPTED = 0x8898040EL,

    //
    // MessageId: UCEERR_NO_MULTIPLE_WORKER_THREADS
    //
    // MessageText:
    //
    // UCEERR_NO_MULTIPLE_WORKER_THREADS
    //
    UCEERR_NO_MULTIPLE_WORKER_THREADS = 0x8898040FL,

    //
    // MessageId: UCEERR_REMOTINGNOTSUPPORTED
    //
    // MessageText:
    //
    // UCEERR_REMOTINGNOTSUPPORTED
    //
    UCEERR_REMOTINGNOTSUPPORTED = 0x88980410L,

    //
    // MessageId: UCEERR_MISSINGENDCOMMAND
    //
    // MessageText:
    //
    // UCEERR_MISSINGENDCOMMAND
    //
    UCEERR_MISSINGENDCOMMAND = 0x88980411L,

    //
    // MessageId: UCEERR_MISSINGBEGINCOMMAND
    //
    // MessageText:
    //
    // UCEERR_MISSINGBEGINCOMMAND
    //
    UCEERR_MISSINGBEGINCOMMAND = 0x88980412L,

    //
    // MessageId: UCEERR_CHANNELSYNCTIMEDOUT
    //
    // MessageText:
    //
    // UCEERR_CHANNELSYNCTIMEDOUT
    //
    UCEERR_CHANNELSYNCTIMEDOUT = 0x88980413L,

    //
    // MessageId: UCEERR_CHANNELSYNCABANDONED
    //
    // MessageText:
    //
    // UCEERR_CHANNELSYNCABANDONED
    //
    UCEERR_CHANNELSYNCABANDONED = 0x88980414L,

    //
    // MessageId: UCEERR_UNSUPPORTEDTRANSPORTVERSION
    //
    // MessageText:
    //
    // UCEERR_UNSUPPORTEDTRANSPORTVERSION
    //
    UCEERR_UNSUPPORTEDTRANSPORTVERSION = 0x88980415L,

    //
    // MessageId: UCEERR_TRANSPORTUNAVAILABLE
    //
    // MessageText:
    //
    // UCEERR_TRANSPORTUNAVAILABLE
    //
    UCEERR_TRANSPORTUNAVAILABLE = 0x88980416L,

    //
    // MessageId: UCEERR_FEEDBACK_UNSUPPORTED
    //
    // MessageText:
    //
    // UCEERR_FEEDBACK_UNSUPPORTED
    //
    UCEERR_FEEDBACK_UNSUPPORTED = 0x88980417L,

    //
    // MessageId: UCEERR_COMMANDTRANSPORTDENIED
    //
    // MessageText:
    //
    // UCEERR_COMMANDTRANSPORTDENIED
    //
    UCEERR_COMMANDTRANSPORTDENIED = 0x88980418L,

    //
    // MessageId: UCEERR_GRAPHICSSTREAMUNAVAILABLE
    //
    // MessageText:
    //
    // UCEERR_GRAPHICSSTREAMUNAVAILABLE
    //
    UCEERR_GRAPHICSSTREAMUNAVAILABLE = 0x88980419L,

    //
    // MessageId: UCEERR_GRAPHICSSTREAMALREADYOPEN
    //
    // MessageText:
    //
    // UCEERR_GRAPHICSSTREAMALREADYOPEN
    //
    UCEERR_GRAPHICSSTREAMALREADYOPEN = 0x88980420L,

    //
    // MessageId: UCEERR_TRANSPORTDISCONNECTED
    //
    // MessageText:
    //
    // UCEERR_TRANSPORTDISCONNECTED
    //
    UCEERR_TRANSPORTDISCONNECTED = 0x88980421L,

    //
    // MessageId: UCEERR_TRANSPORTOVERLOADED
    //
    // MessageText:
    //
    // UCEERR_TRANSPORTOVERLOADED
    //
    UCEERR_TRANSPORTOVERLOADED = 0x88980422L,

    //
    // MessageId: UCEERR_PARTITION_ZOMBIED
    //
    // MessageText:
    //
    // UCEERR_PARTITION_ZOMBIED
    //
    UCEERR_PARTITION_ZOMBIED = 0x88980423L,

    // MIL AV Specific errors
    //
    // MessageId: MILAVERR_NOCLOCK
    //
    // MessageText:
    //
    // MILAVERR_NOCLOCK
    //
    MILAVERR_NOCLOCK = 0x88980500L,

    //
    // MessageId: MILAVERR_NOMEDIATYPE
    //
    // MessageText:
    //
    // MILAVERR_NOMEDIATYPE
    //
    MILAVERR_NOMEDIATYPE = 0x88980501L,

    //
    // MessageId: MILAVERR_NOVIDEOMIXER
    //
    // MessageText:
    //
    // MILAVERR_NOVIDEOMIXER
    //
    MILAVERR_NOVIDEOMIXER = 0x88980502L,

    //
    // MessageId: MILAVERR_NOVIDEOPRESENTER
    //
    // MessageText:
    //
    // MILAVERR_NOVIDEOPRESENTER
    //
    MILAVERR_NOVIDEOPRESENTER = 0x88980503L,

    //
    // MessageId: MILAVERR_NOREADYFRAMES
    //
    // MessageText:
    //
    // MILAVERR_NOREADYFRAMES
    //
    MILAVERR_NOREADYFRAMES = 0x88980504L,

    //
    // MessageId: MILAVERR_MODULENOTLOADED
    //
    // MessageText:
    //
    // MILAVERR_MODULENOTLOADED
    //
    MILAVERR_MODULENOTLOADED = 0x88980505L,

    //
    // MessageId: MILAVERR_WMPFACTORYNOTREGISTERED
    //
    // MessageText:
    //
    // MILAVERR_WMPFACTORYNOTREGISTERED
    //
    MILAVERR_WMPFACTORYNOTREGISTERED = 0x88980506L,

    //
    // MessageId: MILAVERR_INVALIDWMPVERSION
    //
    // MessageText:
    //
    // MILAVERR_INVALIDWMPVERSION
    //
    MILAVERR_INVALIDWMPVERSION = 0x88980507L,

    //
    // MessageId: MILAVERR_INSUFFICIENTVIDEORESOURCES
    //
    // MessageText:
    //
    // MILAVERR_INSUFFICIENTVIDEORESOURCES
    //
    MILAVERR_INSUFFICIENTVIDEORESOURCES = 0x88980508L,

    //
    // MessageId: MILAVERR_VIDEOACCELERATIONNOTAVAILABLE
    //
    // MessageText:
    //
    // MILAVERR_VIDEOACCELERATIONNOTAVAILABLE
    //
    MILAVERR_VIDEOACCELERATIONNOTAVAILABLE = 0x88980509L,

    //
    // MessageId: MILAVERR_REQUESTEDTEXTURETOOBIG
    //
    // MessageText:
    //
    // MILAVERR_REQUESTEDTEXTURETOOBIG
    //
    MILAVERR_REQUESTEDTEXTURETOOBIG = 0x8898050AL,

    //
    // MessageId: MILAVERR_SEEKFAILED
    //
    // MessageText:
    //
    // MILAVERR_SEEKFAILED
    //
    MILAVERR_SEEKFAILED = 0x8898050BL,

    //
    // MessageId: MILAVERR_UNEXPECTEDWMPFAILURE
    //
    // MessageText:
    //
    // MILAVERR_UNEXPECTEDWMPFAILURE
    //
    MILAVERR_UNEXPECTEDWMPFAILURE = 0x8898050CL,

    //
    // MessageId: MILAVERR_MEDIAPLAYERCLOSED
    //
    // MessageText:
    //
    // MILAVERR_MEDIAPLAYERCLOSED
    //
    MILAVERR_MEDIAPLAYERCLOSED = 0x8898050DL,

    //
    // MessageId: MILAVERR_UNKNOWNHARDWAREERROR
    //
    // MessageText:
    //
    // MILAVERR_UNKNOWNHARDWAREERROR
    //
    MILAVERR_UNKNOWNHARDWAREERROR = 0x8898050EL,

    // MIL Bitmap Effet errors
    //
    // MessageId: MILEFFECTSERR_UNKNOWNPROPERTY
    //
    // MessageText:
    //
    // MILEFFECTSERR_UNKNOWNPROPERTY
    //
    MILEFFECTSERR_UNKNOWNPROPERTY = 0x8898060EL,

    //
    // MessageId: MILEFFECTSERR_EFFECTNOTPARTOFGROUP
    //
    // MessageText:
    //
    // MILEFFECTSERR_EFFECTNOTPARTOFGROUP
    //
    MILEFFECTSERR_EFFECTNOTPARTOFGROUP = 0x8898060FL,

    //
    // MessageId: MILEFFECTSERR_NOINPUTSOURCEATTACHED
    //
    // MessageText:
    //
    // MILEFFECTSERR_NOINPUTSOURCEATTACHED
    //
    MILEFFECTSERR_NOINPUTSOURCEATTACHED = 0x88980610L,

    //
    // MessageId: MILEFFECTSERR_CONNECTORNOTCONNECTED
    //
    // MessageText:
    //
    // MILEFFECTSERR_CONNECTORNOTCONNECTED
    //
    MILEFFECTSERR_CONNECTORNOTCONNECTED = 0x88980611L,

    //
    // MessageId: MILEFFECTSERR_CONNECTORNOTASSOCIATEDWITHEFFECT
    //
    // MessageText:
    //
    // MILEFFECTSERR_CONNECTORNOTASSOCIATEDWITHEFFECT
    //
    MILEFFECTSERR_CONNECTORNOTASSOCIATEDWITHEFFECT = 0x88980612L,

    //
    // MessageId: MILEFFECTSERR_RESERVED
    //
    // MessageText:
    //
    // MILEFFECTSERR_RESERVED
    //
    MILEFFECTSERR_RESERVED = 0x88980613L,

    //
    // MessageId: MILEFFECTSERR_CYCLEDETECTED
    //
    // MessageText:
    //
    // MILEFFECTSERR_CYCLEDETECTED
    //
    MILEFFECTSERR_CYCLEDETECTED = 0x88980614L,

    //
    // MessageId: MILEFFECTSERR_EFFECTINMORETHANONEGRAPH
    //
    // MessageText:
    //
    // MILEFFECTSERR_EFFECTINMORETHANONEGRAPH
    //
    MILEFFECTSERR_EFFECTINMORETHANONEGRAPH = 0x88980615L,

    //
    // MessageId: MILEFFECTSERR_EFFECTALREADYINAGRAPH
    //
    // MessageText:
    //
    // MILEFFECTSERR_EFFECTALREADYINAGRAPH
    //
    MILEFFECTSERR_EFFECTALREADYINAGRAPH = 0x88980616L,

    //
    // MessageId: MILEFFECTSERR_EFFECTHASNOCHILDREN
    //
    // MessageText:
    //
    // MILEFFECTSERR_EFFECTHASNOCHILDREN
    //
    MILEFFECTSERR_EFFECTHASNOCHILDREN = 0x88980617L,

    //
    // MessageId: MILEFFECTSERR_ALREADYATTACHEDTOLISTENER
    //
    // MessageText:
    //
    // MILEFFECTSERR_ALREADYATTACHEDTOLISTENER
    //
    MILEFFECTSERR_ALREADYATTACHEDTOLISTENER = 0x88980618L,

    //
    // MessageId: MILEFFECTSERR_NOTAFFINETRANSFORM
    //
    // MessageText:
    //
    // MILEFFECTSERR_NOTAFFINETRANSFORM
    //
    MILEFFECTSERR_NOTAFFINETRANSFORM = 0x88980619L,

    //
    // MessageId: MILEFFECTSERR_EMPTYBOUNDS
    //
    // MessageText:
    //
    // MILEFFECTSERR_EMPTYBOUNDS
    //
    MILEFFECTSERR_EMPTYBOUNDS = 0x8898061AL,

    //
    // MessageId: MILEFFECTSERR_OUTPUTSIZETOOLARGE
    //
    // MessageText:
    //
    // MILEFFECTSERR_OUTPUTSIZETOOLARGE
    //
    MILEFFECTSERR_OUTPUTSIZETOOLARGE = 0x8898061BL,

    // DWM specific errors
    //
    // MessageId: DWMERR_STATE_TRANSITION_FAILED
    //
    // MessageText:
    //
    // DWMERR_STATE_TRANSITION_FAILED
    //
    DWMERR_STATE_TRANSITION_FAILED = 0x88980700L,

    //
    // MessageId: DWMERR_THEME_FAILED
    //
    // MessageText:
    //
    // DWMERR_THEME_FAILED
    //
    DWMERR_THEME_FAILED = 0x88980701L,

    //
    // MessageId: DWMERR_CATASTROPHIC_FAILURE
    //
    // MessageText:
    //
    // DWMERR_CATASTROPHIC_FAILURE
    //
    DWMERR_CATASTROPHIC_FAILURE = 0x88980702L,

    //
    // DirectComposition
    //

    //
    // MessageId: DCOMPOSITION_ERROR_WINDOW_ALREADY_COMPOSED
    //
    // MessageText:
    //
    // DCOMPOSITION_ERROR_WINDOW_ALREADY_COMPOSED
    //
    DCOMPOSITION_ERROR_WINDOW_ALREADY_COMPOSED = 0x88980800L,

    //
    // MessageId: DCOMPOSITION_ERROR_SURFACE_BEING_RENDERED
    //
    // MessageText:
    //
    // DCOMPOSITION_ERROR_SURFACE_BEING_RENDERED
    //
    DCOMPOSITION_ERROR_SURFACE_BEING_RENDERED = 0x88980801L,

    //
    // MessageId: DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED
    //
    // MessageText:
    //
    // DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED
    //
    DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED = 0x88980802L,

    //
    // OnlineId
    //

    //
    // MessageId: ONL_E_INVALID_AUTHENTICATION_TARGET
    //
    // MessageText:
    //
    // Authentication target is invalid or not configured correctly.
    //
    ONL_E_INVALID_AUTHENTICATION_TARGET = 0x80860001L,

    //
    // MessageId: ONL_E_ACCESS_DENIED_BY_TOU
    //
    // MessageText:
    //
    // Your application cannot get the Online Id properties due to the Terms of Use accepted by the user.
    //
    ONL_E_ACCESS_DENIED_BY_TOU = 0x80860002L,

    //
    // MessageId: ONL_E_INVALID_APPLICATION
    //
    // MessageText:
    //
    // The application requesting authentication tokens is either disabled or incorrectly configured.
    //
    ONL_E_INVALID_APPLICATION = 0x80860003L,

    //
    // MessageId: ONL_E_PASSWORD_UPDATE_REQUIRED
    //
    // MessageText:
    //
    // Online Id password must be updated before signin.
    //
    ONL_E_PASSWORD_UPDATE_REQUIRED = 0x80860004L,

    //
    // MessageId: ONL_E_ACCOUNT_UPDATE_REQUIRED
    //
    // MessageText:
    //
    // Online Id account properties must be updated before signin.
    //
    ONL_E_ACCOUNT_UPDATE_REQUIRED = 0x80860005L,

    //
    // MessageId: ONL_E_FORCESIGNIN
    //
    // MessageText:
    //
    // To help protect your Online Id account you must signin again.
    //
    ONL_E_FORCESIGNIN = 0x80860006L,

    //
    // MessageId: ONL_E_ACCOUNT_LOCKED
    //
    // MessageText:
    //
    // Online Id account was locked because there have been too many attempts to sign in.
    //
    ONL_E_ACCOUNT_LOCKED = 0x80860007L,

    //
    // MessageId: ONL_E_PARENTAL_CONSENT_REQUIRED
    //
    // MessageText:
    //
    // Online Id account requires parental consent before proceeding.
    //
    ONL_E_PARENTAL_CONSENT_REQUIRED = 0x80860008L,

    //
    // MessageId: ONL_E_EMAIL_VERIFICATION_REQUIRED
    //
    // MessageText:
    //
    // Online Id signin name is not yet verified. Email verification is required before signin.
    //
    ONL_E_EMAIL_VERIFICATION_REQUIRED = 0x80860009L,

    //
    // MessageId: ONL_E_ACCOUNT_SUSPENDED_COMPROIMISE
    //
    // MessageText:
    //
    // We have noticed some unusual activity in your Online Id account. Your action is needed to make sure no one else is using your account.
    //
    ONL_E_ACCOUNT_SUSPENDED_COMPROIMISE = 0x8086000AL,

    //
    // MessageId: ONL_E_ACCOUNT_SUSPENDED_ABUSE
    //
    // MessageText:
    //
    // We detected some suspicious activity with your Online Id account. To help protect you, we've temporarily blocked your account.
    //
    ONL_E_ACCOUNT_SUSPENDED_ABUSE = 0x8086000BL,

    //
    // MessageId: ONL_E_ACTION_REQUIRED
    //
    // MessageText:
    //
    // User interaction is required for authentication.
    //
    ONL_E_ACTION_REQUIRED = 0x8086000CL,

    //
    // MessageId: ONL_CONNECTION_COUNT_LIMIT
    //
    // MessageText:
    //
    // User has reached the maximum device associations per user limit.
    //
    ONL_CONNECTION_COUNT_LIMIT = 0x8086000DL,

    //
    // MessageId: ONL_E_CONNECTED_ACCOUNT_CAN_NOT_SIGNOUT
    //
    // MessageText:
    //
    // Cannot sign out from the application since the user account is connected.
    //
    ONL_E_CONNECTED_ACCOUNT_CAN_NOT_SIGNOUT = 0x8086000EL,

    //
    // MessageId: ONL_E_USER_AUTHENTICATION_REQUIRED
    //
    // MessageText:
    //
    // User authentication is required for this operation.
    //
    ONL_E_USER_AUTHENTICATION_REQUIRED = 0x8086000FL,

    //
    // MessageId: ONL_E_REQUEST_THROTTLED
    //
    // MessageText:
    //
    // We want to make sure this is you. User interaction is required for authentication.
    //
    ONL_E_REQUEST_THROTTLED = 0x80860010L,

    //
    // Facility Shell Error codes
    //

    //
    // MessageId: FA_E_MAX_PERSISTED_ITEMS_REACHED
    //
    // MessageText:
    //
    // The maximum number of items for the access list has been reached. An item must be removed before another item is added.
    //
    FA_E_MAX_PERSISTED_ITEMS_REACHED = 0x80270220L,

    //
    // MessageId: FA_E_HOMEGROUP_NOT_AVAILABLE
    //
    // MessageText:
    //
    // Cannot access Homegroup. Homegroup may not be set up or may have encountered an error.
    //
    FA_E_HOMEGROUP_NOT_AVAILABLE = 0x80270222L,

    //
    // MessageId: E_MONITOR_RESOLUTION_TOO_LOW
    //
    // MessageText:
    //
    // This app can't start because the screen resolution is below 1024x768. Choose a higher screen resolution and then try again.
    //
    E_MONITOR_RESOLUTION_TOO_LOW = 0x80270250L,

    //
    // MessageId: E_ELEVATED_ACTIVATION_NOT_SUPPORTED
    //
    // MessageText:
    //
    // This app can't be activated from an elevated context.
    //
    E_ELEVATED_ACTIVATION_NOT_SUPPORTED = 0x80270251L,

    //
    // MessageId: E_UAC_DISABLED
    //
    // MessageText:
    //
    // This app can't be activated when UAC is disabled.
    //
    E_UAC_DISABLED = 0x80270252L,

    //
    // MessageId: E_FULL_ADMIN_NOT_SUPPORTED
    //
    // MessageText:
    //
    // This app can't be activated by the Built-in Administrator.
    //
    E_FULL_ADMIN_NOT_SUPPORTED = 0x80270253L,

    //
    // MessageId: E_APPLICATION_NOT_REGISTERED
    //
    // MessageText:
    //
    // This app does not support the contract specified or is not installed.
    //
    E_APPLICATION_NOT_REGISTERED = 0x80270254L,

    //
    // MessageId: E_MULTIPLE_EXTENSIONS_FOR_APPLICATION
    //
    // MessageText:
    //
    // This app has mulitple extensions registered to support the specified contract. Activation by AppUserModelId is ambiguous.
    //
    E_MULTIPLE_EXTENSIONS_FOR_APPLICATION = 0x80270255L,

    //
    // MessageId: E_MULTIPLE_PACKAGES_FOR_FAMILY
    //
    // MessageText:
    //
    // This app's package family has more than one package installed. This is not supported.
    //
    E_MULTIPLE_PACKAGES_FOR_FAMILY = 0x80270256L,

    //
    // MessageId: E_APPLICATION_MANAGER_NOT_RUNNING
    //
    // MessageText:
    //
    // The app manager is required to activate applications, but is not running.
    //
    E_APPLICATION_MANAGER_NOT_RUNNING = 0x80270257L,

    //
    // MessageId: S_STORE_LAUNCHED_FOR_REMEDIATION
    //
    // MessageText:
    //
    // The Store was launched instead of the specified app because the app's package was in an invalid state.
    //
    S_STORE_LAUNCHED_FOR_REMEDIATION = 0x00270258L,

    //
    // MessageId: S_APPLICATION_ACTIVATION_ERROR_HANDLED_BY_DIALOG
    //
    // MessageText:
    //
    // This app failed to launch, but the error was handled with a dialog.
    //
    S_APPLICATION_ACTIVATION_ERROR_HANDLED_BY_DIALOG = 0x00270259L,

    //
    // MessageId: E_APPLICATION_ACTIVATION_TIMED_OUT
    //
    // MessageText:
    //
    // The app didn't start in the required time.
    //
    E_APPLICATION_ACTIVATION_TIMED_OUT = 0x8027025AL,

    //
    // MessageId: E_APPLICATION_ACTIVATION_EXEC_FAILURE
    //
    // MessageText:
    //
    // The app didn't start.
    //
    E_APPLICATION_ACTIVATION_EXEC_FAILURE = 0x8027025BL,

    //
    // MessageId: E_APPLICATION_TEMPORARY_LICENSE_ERROR
    //
    // MessageText:
    //
    // This app failed to launch because of an issue with its license. Please try again in a moment.
    //
    E_APPLICATION_TEMPORARY_LICENSE_ERROR = 0x8027025CL,

    //
    // MessageId: E_APPLICATION_TRIAL_LICENSE_EXPIRED
    //
    // MessageText:
    //
    // This app failed to launch because its trial license has expired.
    //
    E_APPLICATION_TRIAL_LICENSE_EXPIRED = 0x8027025DL,

    //
    // MessageId: E_SKYDRIVE_ROOT_TARGET_FILE_SYSTEM_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Please choose a folder on a drive that's formatted with the NTFS file system.
    //
    E_SKYDRIVE_ROOT_TARGET_FILE_SYSTEM_NOT_SUPPORTED = 0x80270260L,

    //
    // MessageId: E_SKYDRIVE_ROOT_TARGET_OVERLAP
    //
    // MessageText:
    //
    // This location is already being used. Please choose a different location.
    //
    E_SKYDRIVE_ROOT_TARGET_OVERLAP = 0x80270261L,

    //
    // MessageId: E_SKYDRIVE_ROOT_TARGET_CANNOT_INDEX
    //
    // MessageText:
    //
    // This location cannot be indexed. Please choose a different location.
    //
    E_SKYDRIVE_ROOT_TARGET_CANNOT_INDEX = 0x80270262L,

    //
    // MessageId: E_SKYDRIVE_FILE_NOT_UPLOADED
    //
    // MessageText:
    //
    // Sorry, the action couldn't be completed because the file hasn't finished uploading. Try again later.
    //
    E_SKYDRIVE_FILE_NOT_UPLOADED = 0x80270263L,

    //
    // MessageId: E_SKYDRIVE_UPDATE_AVAILABILITY_FAIL
    //
    // MessageText:
    //
    // Sorry, the action couldn't be completed.
    //
    E_SKYDRIVE_UPDATE_AVAILABILITY_FAIL = 0x80270264L,

    //
    // MessageId: E_SKYDRIVE_ROOT_TARGET_VOLUME_ROOT_NOT_SUPPORTED
    //
    // MessageText:
    //
    // This content can only be moved to a folder. To move the content to this drive, please choose or create a folder.
    //
    E_SKYDRIVE_ROOT_TARGET_VOLUME_ROOT_NOT_SUPPORTED = 0x80270265L,

    // Sync Engine File Error Codes

    //
    // MessageId: E_SYNCENGINE_FILE_SIZE_OVER_LIMIT
    //
    // MessageText:
    //
    // The file size is larger than supported by the sync engine.
    //
    E_SYNCENGINE_FILE_SIZE_OVER_LIMIT = 0x8802B001L,

    //
    // MessageId: E_SYNCENGINE_FILE_SIZE_EXCEEDS_REMAINING_QUOTA
    //
    // MessageText:
    //
    // The file cannot be uploaded because it doesn't fit in the user's available service provided storage space.
    //
    E_SYNCENGINE_FILE_SIZE_EXCEEDS_REMAINING_QUOTA = 0x8802B002L,

    //
    // MessageId: E_SYNCENGINE_UNSUPPORTED_FILE_NAME
    //
    // MessageText:
    //
    // The file name contains invalid characters.
    //
    E_SYNCENGINE_UNSUPPORTED_FILE_NAME = 0x8802B003L,

    //
    // MessageId: E_SYNCENGINE_FOLDER_ITEM_COUNT_LIMIT_EXCEEDED
    //
    // MessageText:
    //
    // The maximum file count has been reached for this folder in the sync engine.
    //
    E_SYNCENGINE_FOLDER_ITEM_COUNT_LIMIT_EXCEEDED = 0x8802B004L,

    //
    // MessageId: E_SYNCENGINE_FILE_SYNC_PARTNER_ERROR
    //
    // MessageText:
    //
    // The file sync has been delegated to another program and has run into an issue.
    //
    E_SYNCENGINE_FILE_SYNC_PARTNER_ERROR = 0x8802B005L,

    //
    // MessageId: E_SYNCENGINE_SYNC_PAUSED_BY_SERVICE
    //
    // MessageText:
    //
    // Sync has been delayed due to a throttling request from the service.
    //
    E_SYNCENGINE_SYNC_PAUSED_BY_SERVICE = 0x8802B006L,

    // Sync Engine Stream Resolver Errors

    //
    // MessageId: E_SYNCENGINE_FILE_IDENTIFIER_UNKNOWN
    //
    // MessageText:
    //
    // We can't seem to find that file. Please try again later.
    //
    E_SYNCENGINE_FILE_IDENTIFIER_UNKNOWN = 0x8802C002L,

    //
    // MessageId: E_SYNCENGINE_SERVICE_AUTHENTICATION_FAILED
    //
    // MessageText:
    //
    // The account you're signed in with doesn't have permission to open this file.
    //
    E_SYNCENGINE_SERVICE_AUTHENTICATION_FAILED = 0x8802C003L,

    //
    // MessageId: E_SYNCENGINE_UNKNOWN_SERVICE_ERROR
    //
    // MessageText:
    //
    // There was a problem connecting to the service. Please try again later.
    //
    E_SYNCENGINE_UNKNOWN_SERVICE_ERROR = 0x8802C004L,

    //
    // MessageId: E_SYNCENGINE_SERVICE_RETURNED_UNEXPECTED_SIZE
    //
    // MessageText:
    //
    // Sorry, there was a problem downloading the file.
    //
    E_SYNCENGINE_SERVICE_RETURNED_UNEXPECTED_SIZE = 0x8802C005L,

    //
    // MessageId: E_SYNCENGINE_REQUEST_BLOCKED_BY_SERVICE
    //
    // MessageText:
    //
    // We're having trouble downloading the file right now. Please try again later.
    //
    E_SYNCENGINE_REQUEST_BLOCKED_BY_SERVICE = 0x8802C006L,

    //
    // MessageId: E_SYNCENGINE_REQUEST_BLOCKED_DUE_TO_CLIENT_ERROR
    //
    // MessageText:
    //
    // We're having trouble downloading the file right now. Please try again later.
    //
    E_SYNCENGINE_REQUEST_BLOCKED_DUE_TO_CLIENT_ERROR = 0x8802C007L,

    // Sync Engine Global Errors

    //
    // MessageId: E_SYNCENGINE_FOLDER_INACCESSIBLE
    //
    // MessageText:
    //
    // The sync engine does not have permissions to access a local folder under the sync root.
    //
    E_SYNCENGINE_FOLDER_INACCESSIBLE = 0x8802D001L,

    //
    // MessageId: E_SYNCENGINE_UNSUPPORTED_FOLDER_NAME
    //
    // MessageText:
    //
    // The folder name contains invalid characters.
    //
    E_SYNCENGINE_UNSUPPORTED_FOLDER_NAME = 0x8802D002L,

    //
    // MessageId: E_SYNCENGINE_UNSUPPORTED_MARKET
    //
    // MessageText:
    //
    // The sync engine is not allowed to run in your current market.
    //
    E_SYNCENGINE_UNSUPPORTED_MARKET = 0x8802D003L,

    //
    // MessageId: E_SYNCENGINE_PATH_LENGTH_LIMIT_EXCEEDED
    //
    // MessageText:
    //
    // All files and folders can't be uploaded because a path of a file or folder is too long.
    //
    E_SYNCENGINE_PATH_LENGTH_LIMIT_EXCEEDED = 0x8802D004L,

    //
    // MessageId: E_SYNCENGINE_REMOTE_PATH_LENGTH_LIMIT_EXCEEDED
    //
    // MessageText:
    //
    // All file and folders cannot be synchronized because a path of a file or folder would exceed the local path limit.
    //
    E_SYNCENGINE_REMOTE_PATH_LENGTH_LIMIT_EXCEEDED = 0x8802D005L,

    //
    // MessageId: E_SYNCENGINE_CLIENT_UPDATE_NEEDED
    //
    // MessageText:
    //
    // Updates are needed in order to use the sync engine.
    //
    E_SYNCENGINE_CLIENT_UPDATE_NEEDED = 0x8802D006L,

    //
    // MessageId: E_SYNCENGINE_PROXY_AUTHENTICATION_REQUIRED
    //
    // MessageText:
    //
    // The sync engine needs to authenticate with a proxy server.
    //
    E_SYNCENGINE_PROXY_AUTHENTICATION_REQUIRED = 0x8802D007L,

    //
    // MessageId: E_SYNCENGINE_STORAGE_SERVICE_PROVISIONING_FAILED
    //
    // MessageText:
    //
    // There was a problem setting up the storage services for the account.
    //
    E_SYNCENGINE_STORAGE_SERVICE_PROVISIONING_FAILED = 0x8802D008L,

    //
    // MessageId: E_SYNCENGINE_UNSUPPORTED_REPARSE_POINT
    //
    // MessageText:
    //
    // Files can't be uploaded because there's an unsupported reparse point.
    //
    E_SYNCENGINE_UNSUPPORTED_REPARSE_POINT = 0x8802D009L,

    //
    // MessageId: E_SYNCENGINE_STORAGE_SERVICE_BLOCKED
    //
    // MessageText:
    //
    // The service has blocked your account from accessing the storage service.
    //
    E_SYNCENGINE_STORAGE_SERVICE_BLOCKED = 0x8802D00AL,

    //
    // MessageId: E_SYNCENGINE_FOLDER_IN_REDIRECTION
    //
    // MessageText:
    //
    // The action can't be performed right now because this folder is being moved. Please try again later.
    //
    E_SYNCENGINE_FOLDER_IN_REDIRECTION = 0x8802D00BL,

    //
    // EAS
    //

    //
    // MessageId: EAS_E_POLICY_NOT_MANAGED_BY_OS
    //
    // MessageText:
    //
    // Windows cannot evaluate this EAS policy since this is not managed by the operating system.
    //
    EAS_E_POLICY_NOT_MANAGED_BY_OS = 0x80550001L,

    //
    // MessageId: EAS_E_POLICY_COMPLIANT_WITH_ACTIONS
    //
    // MessageText:
    //
    // The system can be made compliant to this EAS policy if certain actions are performed by the user.
    //
    EAS_E_POLICY_COMPLIANT_WITH_ACTIONS = 0x80550002L,

    //
    // MessageId: EAS_E_REQUESTED_POLICY_NOT_ENFORCEABLE
    //
    // MessageText:
    //
    // The EAS policy being evaluated cannot be enforced by the system.
    //
    EAS_E_REQUESTED_POLICY_NOT_ENFORCEABLE = 0x80550003L,

    //
    // MessageId: EAS_E_CURRENT_USER_HAS_BLANK_PASSWORD
    //
    // MessageText:
    //
    // EAS password policies for the user cannot be evaluated as the user has a blank password.
    //
    EAS_E_CURRENT_USER_HAS_BLANK_PASSWORD = 0x80550004L,

    //
    // MessageId: EAS_E_REQUESTED_POLICY_PASSWORD_EXPIRATION_INCOMPATIBLE
    //
    // MessageText:
    //
    // EAS password expiration policy cannot be satisfied as the password expiration interval is less than the minimum password interval of the system.
    //
    EAS_E_REQUESTED_POLICY_PASSWORD_EXPIRATION_INCOMPATIBLE = 0x80550005L,

    //
    // MessageId: EAS_E_USER_CANNOT_CHANGE_PASSWORD
    //
    // MessageText:
    //
    // The user is not allowed to change her password.
    //
    EAS_E_USER_CANNOT_CHANGE_PASSWORD = 0x80550006L,

    //
    // MessageId: EAS_E_ADMINS_HAVE_BLANK_PASSWORD
    //
    // MessageText:
    //
    // EAS password policies cannot be evaluated as one or more admins have blank passwords.
    //
    EAS_E_ADMINS_HAVE_BLANK_PASSWORD = 0x80550007L,

    //
    // MessageId: EAS_E_ADMINS_CANNOT_CHANGE_PASSWORD
    //
    // MessageText:
    //
    // One or more admins are not allowed to change their password.
    //
    EAS_E_ADMINS_CANNOT_CHANGE_PASSWORD = 0x80550008L,

    //
    // MessageId: EAS_E_LOCAL_CONTROLLED_USERS_CANNOT_CHANGE_PASSWORD
    //
    // MessageText:
    //
    // There are other standard users present who are not allowed to change their password.
    //
    EAS_E_LOCAL_CONTROLLED_USERS_CANNOT_CHANGE_PASSWORD = 0x80550009L,

    //
    // MessageId: EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CONNECTED_ADMINS
    //
    // MessageText:
    //
    // The EAS password policy cannot be enforced by the connected account provider of at least one administrator.
    //
    EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CONNECTED_ADMINS = 0x8055000AL,

    //
    // MessageId: EAS_E_CONNECTED_ADMINS_NEED_TO_CHANGE_PASSWORD
    //
    // MessageText:
    //
    // There is at least one administrator whose connected account password needs to be changed for EAS password policy compliance.
    //
    EAS_E_CONNECTED_ADMINS_NEED_TO_CHANGE_PASSWORD = 0x8055000BL,

    //
    // MessageId: EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CURRENT_CONNECTED_USER
    //
    // MessageText:
    //
    // The EAS password policy cannot be enforced by the connected account provider of the current user.
    //
    EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CURRENT_CONNECTED_USER = 0x8055000CL,

    //
    // MessageId: EAS_E_CURRENT_CONNECTED_USER_NEED_TO_CHANGE_PASSWORD
    //
    // MessageText:
    //
    // The connected account password of the current user needs to be changed for EAS password policy compliance.
    //
    EAS_E_CURRENT_CONNECTED_USER_NEED_TO_CHANGE_PASSWORD = 0x8055000DL,

    //
    // MessageId: WEB_E_UNSUPPORTED_FORMAT
    //
    // MessageText:
    //
    // Unsupported format.
    //
    WEB_E_UNSUPPORTED_FORMAT = 0x83750001L,

    //
    // MessageId: WEB_E_INVALID_XML
    //
    // MessageText:
    //
    // Invalid XML.
    //
    WEB_E_INVALID_XML = 0x83750002L,

    //
    // MessageId: WEB_E_MISSING_REQUIRED_ELEMENT
    //
    // MessageText:
    //
    // Missing required element.
    //
    WEB_E_MISSING_REQUIRED_ELEMENT = 0x83750003L,

    //
    // MessageId: WEB_E_MISSING_REQUIRED_ATTRIBUTE
    //
    // MessageText:
    //
    // Missing required attribute.
    //
    WEB_E_MISSING_REQUIRED_ATTRIBUTE = 0x83750004L,

    //
    // MessageId: WEB_E_UNEXPECTED_CONTENT
    //
    // MessageText:
    //
    // Unexpected content.
    //
    WEB_E_UNEXPECTED_CONTENT = 0x83750005L,

    //
    // MessageId: WEB_E_RESOURCE_TOO_LARGE
    //
    // MessageText:
    //
    // Resource too large.
    //
    WEB_E_RESOURCE_TOO_LARGE = 0x83750006L,

    //
    // MessageId: WEB_E_INVALID_JSON_STRING
    //
    // MessageText:
    //
    // Invalid JSON string.
    //
    WEB_E_INVALID_JSON_STRING = 0x83750007L,

    //
    // MessageId: WEB_E_INVALID_JSON_NUMBER
    //
    // MessageText:
    //
    // Invalid JSON number.
    //
    WEB_E_INVALID_JSON_NUMBER = 0x83750008L,

    //
    // MessageId: WEB_E_JSON_VALUE_NOT_FOUND
    //
    // MessageText:
    //
    // JSON value not found.
    //
    WEB_E_JSON_VALUE_NOT_FOUND = 0x83750009L,

    //
    // MessageId: HTTP_E_STATUS_UNEXPECTED
    //
    // MessageText:
    //
    // Unexpected HTTP status code.
    //
    HTTP_E_STATUS_UNEXPECTED = 0x80190001L,

    //
    // MessageId: HTTP_E_STATUS_UNEXPECTED_REDIRECTION
    //
    // MessageText:
    //
    // Unexpected redirection status code (3xx).
    //
    HTTP_E_STATUS_UNEXPECTED_REDIRECTION = 0x80190003L,

    //
    // MessageId: HTTP_E_STATUS_UNEXPECTED_CLIENT_ERROR
    //
    // MessageText:
    //
    // Unexpected client error status code (4xx).
    //
    HTTP_E_STATUS_UNEXPECTED_CLIENT_ERROR = 0x80190004L,

    //
    // MessageId: HTTP_E_STATUS_UNEXPECTED_SERVER_ERROR
    //
    // MessageText:
    //
    // Unexpected server error status code (5xx).
    //
    HTTP_E_STATUS_UNEXPECTED_SERVER_ERROR = 0x80190005L,

    //
    // MessageId: HTTP_E_STATUS_AMBIGUOUS
    //
    // MessageText:
    //
    // Multiple choices (300).
    //
    HTTP_E_STATUS_AMBIGUOUS = 0x8019012CL,

    //
    // MessageId: HTTP_E_STATUS_MOVED
    //
    // MessageText:
    //
    // Moved permanently (301).
    //
    HTTP_E_STATUS_MOVED = 0x8019012DL,

    //
    // MessageId: HTTP_E_STATUS_REDIRECT
    //
    // MessageText:
    //
    // Found (302).
    //
    HTTP_E_STATUS_REDIRECT = 0x8019012EL,

    //
    // MessageId: HTTP_E_STATUS_REDIRECT_METHOD
    //
    // MessageText:
    //
    // See Other (303).
    //
    HTTP_E_STATUS_REDIRECT_METHOD = 0x8019012FL,

    //
    // MessageId: HTTP_E_STATUS_NOT_MODIFIED
    //
    // MessageText:
    //
    // Not modified (304).
    //
    HTTP_E_STATUS_NOT_MODIFIED = 0x80190130L,

    //
    // MessageId: HTTP_E_STATUS_USE_PROXY
    //
    // MessageText:
    //
    // Use proxy (305).
    //
    HTTP_E_STATUS_USE_PROXY = 0x80190131L,

    //
    // MessageId: HTTP_E_STATUS_REDIRECT_KEEP_VERB
    //
    // MessageText:
    //
    // Temporary redirect (307).
    //
    HTTP_E_STATUS_REDIRECT_KEEP_VERB = 0x80190133L,

    //
    // MessageId: HTTP_E_STATUS_BAD_REQUEST
    //
    // MessageText:
    //
    // Bad request (400).
    //
    HTTP_E_STATUS_BAD_REQUEST = 0x80190190L,

    //
    // MessageId: HTTP_E_STATUS_DENIED
    //
    // MessageText:
    //
    // Unauthorized (401).
    //
    HTTP_E_STATUS_DENIED = 0x80190191L,

    //
    // MessageId: HTTP_E_STATUS_PAYMENT_REQ
    //
    // MessageText:
    //
    // Payment required (402).
    //
    HTTP_E_STATUS_PAYMENT_REQ = 0x80190192L,

    //
    // MessageId: HTTP_E_STATUS_FORBIDDEN
    //
    // MessageText:
    //
    // Forbidden (403).
    //
    HTTP_E_STATUS_FORBIDDEN = 0x80190193L,

    //
    // MessageId: HTTP_E_STATUS_NOT_FOUND
    //
    // MessageText:
    //
    // Not found (404).
    //
    HTTP_E_STATUS_NOT_FOUND = 0x80190194L,

    //
    // MessageId: HTTP_E_STATUS_BAD_METHOD
    //
    // MessageText:
    //
    // Method not allowed (405).
    //
    HTTP_E_STATUS_BAD_METHOD = 0x80190195L,

    //
    // MessageId: HTTP_E_STATUS_NONE_ACCEPTABLE
    //
    // MessageText:
    //
    // Not acceptable (406).
    //
    HTTP_E_STATUS_NONE_ACCEPTABLE = 0x80190196L,

    //
    // MessageId: HTTP_E_STATUS_PROXY_AUTH_REQ
    //
    // MessageText:
    //
    // Proxy authentication required (407).
    //
    HTTP_E_STATUS_PROXY_AUTH_REQ = 0x80190197L,

    //
    // MessageId: HTTP_E_STATUS_REQUEST_TIMEOUT
    //
    // MessageText:
    //
    // Request timeout (408).
    //
    HTTP_E_STATUS_REQUEST_TIMEOUT = 0x80190198L,

    //
    // MessageId: HTTP_E_STATUS_CONFLICT
    //
    // MessageText:
    //
    // Conflict (409).
    //
    HTTP_E_STATUS_CONFLICT = 0x80190199L,

    //
    // MessageId: HTTP_E_STATUS_GONE
    //
    // MessageText:
    //
    // Gone (410).
    //
    HTTP_E_STATUS_GONE = 0x8019019AL,

    //
    // MessageId: HTTP_E_STATUS_LENGTH_REQUIRED
    //
    // MessageText:
    //
    // Length required (411).
    //
    HTTP_E_STATUS_LENGTH_REQUIRED = 0x8019019BL,

    //
    // MessageId: HTTP_E_STATUS_PRECOND_FAILED
    //
    // MessageText:
    //
    // Precondition failed (412).
    //
    HTTP_E_STATUS_PRECOND_FAILED = 0x8019019CL,

    //
    // MessageId: HTTP_E_STATUS_REQUEST_TOO_LARGE
    //
    // MessageText:
    //
    // Request entity too large (413).
    //
    HTTP_E_STATUS_REQUEST_TOO_LARGE = 0x8019019DL,

    //
    // MessageId: HTTP_E_STATUS_URI_TOO_LONG
    //
    // MessageText:
    //
    // Request-URI too long (414).
    //
    HTTP_E_STATUS_URI_TOO_LONG = 0x8019019EL,

    //
    // MessageId: HTTP_E_STATUS_UNSUPPORTED_MEDIA
    //
    // MessageText:
    //
    // Unsupported media type (415).
    //
    HTTP_E_STATUS_UNSUPPORTED_MEDIA = 0x8019019FL,

    //
    // MessageId: HTTP_E_STATUS_RANGE_NOT_SATISFIABLE
    //
    // MessageText:
    //
    // Requested range not satisfiable (416).
    //
    HTTP_E_STATUS_RANGE_NOT_SATISFIABLE = 0x801901A0L,

    //
    // MessageId: HTTP_E_STATUS_EXPECTATION_FAILED
    //
    // MessageText:
    //
    // Expectation failed (417).
    //
    HTTP_E_STATUS_EXPECTATION_FAILED = 0x801901A1L,

    //
    // MessageId: HTTP_E_STATUS_SERVER_ERROR
    //
    // MessageText:
    //
    // Internal server error (500).
    //
    HTTP_E_STATUS_SERVER_ERROR = 0x801901F4L,

    //
    // MessageId: HTTP_E_STATUS_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Not implemented (501).
    //
    HTTP_E_STATUS_NOT_SUPPORTED = 0x801901F5L,

    //
    // MessageId: HTTP_E_STATUS_BAD_GATEWAY
    //
    // MessageText:
    //
    // Bad gateway (502).
    //
    HTTP_E_STATUS_BAD_GATEWAY = 0x801901F6L,

    //
    // MessageId: HTTP_E_STATUS_SERVICE_UNAVAIL
    //
    // MessageText:
    //
    // Service unavailable (503).
    //
    HTTP_E_STATUS_SERVICE_UNAVAIL = 0x801901F7L,

    //
    // MessageId: HTTP_E_STATUS_GATEWAY_TIMEOUT
    //
    // MessageText:
    //
    // Gateway timeout (504).
    //
    HTTP_E_STATUS_GATEWAY_TIMEOUT = 0x801901F8L,

    //
    // MessageId: HTTP_E_STATUS_VERSION_NOT_SUP
    //
    // MessageText:
    //
    // Version not supported (505).
    //
    HTTP_E_STATUS_VERSION_NOT_SUP = 0x801901F9L,

    //
    // WebSocket
    //

    //
    // MessageId: E_INVALID_PROTOCOL_OPERATION
    //
    // MessageText:
    //
    // Invalid operation performed by the protocol.
    //
    E_INVALID_PROTOCOL_OPERATION = 0x83760001L,

    //
    // MessageId: E_INVALID_PROTOCOL_FORMAT
    //
    // MessageText:
    //
    // Invalid data format for the specific protocol operation.
    //
    E_INVALID_PROTOCOL_FORMAT = 0x83760002L,

    //
    // MessageId: E_PROTOCOL_EXTENSIONS_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Protocol extensions are not supported.
    //
    E_PROTOCOL_EXTENSIONS_NOT_SUPPORTED = 0x83760003L,

    //
    // MessageId: E_SUBPROTOCOL_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Subrotocol is not supported.
    //
    E_SUBPROTOCOL_NOT_SUPPORTED = 0x83760004L,

    //
    // MessageId: E_PROTOCOL_VERSION_NOT_SUPPORTED
    //
    // MessageText:
    //
    // Incorrect protocol version.
    //
    E_PROTOCOL_VERSION_NOT_SUPPORTED = 0x83760005L,

    //
    // Touch and Pen Input Platform Error Codes
    //

    //
    // MessageId: INPUT_E_OUT_OF_ORDER
    //
    // MessageText:
    //
    // Input data cannot be processed in the non-chronological order.
    //
    INPUT_E_OUT_OF_ORDER = 0x80400000L,

    //
    // MessageId: INPUT_E_REENTRANCY
    //
    // MessageText:
    //
    // Requested operation cannot be performed inside the callback or event handler.
    //
    INPUT_E_REENTRANCY = 0x80400001L,

    //
    // MessageId: INPUT_E_MULTIMODAL
    //
    // MessageText:
    //
    // Input cannot be processed because there is ongoing interaction with another pointer type.
    //
    INPUT_E_MULTIMODAL = 0x80400002L,

    //
    // MessageId: INPUT_E_PACKET
    //
    // MessageText:
    //
    // One or more fields in the input packet are invalid.
    //
    INPUT_E_PACKET = 0x80400003L,

    //
    // MessageId: INPUT_E_FRAME
    //
    // MessageText:
    //
    // Packets in the frame are inconsistent. Either pointer ids are not unique or there is a discrepancy in timestamps, frame ids, pointer types or source devices.
    //
    INPUT_E_FRAME = 0x80400004L,

    //
    // MessageId: INPUT_E_HISTORY
    //
    // MessageText:
    //
    // The history of frames is inconsistent. Pointer ids, types, source devices don't match, or frame ids are not unique, or timestamps are out of order.
    //
    INPUT_E_HISTORY = 0x80400005L,

    //
    // MessageId: INPUT_E_DEVICE_INFO
    //
    // MessageText:
    //
    // Failed to retrieve information about the input device.
    //
    INPUT_E_DEVICE_INFO = 0x80400006L,

    //
    // MessageId: INPUT_E_TRANSFORM
    //
    // MessageText:
    //
    // Coordinate system transformation failed to transform the data.
    //
    INPUT_E_TRANSFORM = 0x80400007L,

    //
    // MessageId: INPUT_E_DEVICE_PROPERTY
    //
    // MessageText:
    //
    // The property is not supported or not reported correctly by the input device.
    //
    INPUT_E_DEVICE_PROPERTY = 0x80400008L,

    //
    // Internet
    //
    //
    // MessageId: INET_E_INVALID_URL
    //
    // MessageText:
    //
    // The URL is invalid.
    //
    INET_E_INVALID_URL = 0x800C0002L,

    //
    // MessageId: INET_E_NO_SESSION
    //
    // MessageText:
    //
    // No Internet session has been established.
    //
    INET_E_NO_SESSION = 0x800C0003L,

    //
    // MessageId: INET_E_CANNOT_CONNECT
    //
    // MessageText:
    //
    // Unable to connect to the target server.
    //
    INET_E_CANNOT_CONNECT = 0x800C0004L,

    //
    // MessageId: INET_E_RESOURCE_NOT_FOUND
    //
    // MessageText:
    //
    // The system cannot locate the resource specified.
    //
    INET_E_RESOURCE_NOT_FOUND = 0x800C0005L,

    //
    // MessageId: INET_E_OBJECT_NOT_FOUND
    //
    // MessageText:
    //
    // The system cannot locate the object specified.
    //
    INET_E_OBJECT_NOT_FOUND = 0x800C0006L,

    //
    // MessageId: INET_E_DATA_NOT_AVAILABLE
    //
    // MessageText:
    //
    // No data is available for the requested resource.
    //
    INET_E_DATA_NOT_AVAILABLE = 0x800C0007L,

    //
    // MessageId: INET_E_DOWNLOAD_FAILURE
    //
    // MessageText:
    //
    // The download of the specified resource has failed.
    //
    INET_E_DOWNLOAD_FAILURE = 0x800C0008L,

    //
    // MessageId: INET_E_AUTHENTICATION_REQUIRED
    //
    // MessageText:
    //
    // Authentication is required to access this resource.
    //
    INET_E_AUTHENTICATION_REQUIRED = 0x800C0009L,

    //
    // MessageId: INET_E_NO_VALID_MEDIA
    //
    // MessageText:
    //
    // The server could not recognize the provided mime type.
    //
    INET_E_NO_VALID_MEDIA = 0x800C000AL,

    //
    // MessageId: INET_E_CONNECTION_TIMEOUT
    //
    // MessageText:
    //
    // The operation was timed out.
    //
    INET_E_CONNECTION_TIMEOUT = 0x800C000BL,

    //
    // MessageId: INET_E_INVALID_REQUEST
    //
    // MessageText:
    //
    // The server did not understand the request, or the request was invalid.
    //
    INET_E_INVALID_REQUEST = 0x800C000CL,

    //
    // MessageId: INET_E_UNKNOWN_PROTOCOL
    //
    // MessageText:
    //
    // The specified protocol is unknown.
    //
    INET_E_UNKNOWN_PROTOCOL = 0x800C000DL,

    //
    // MessageId: INET_E_SECURITY_PROBLEM
    //
    // MessageText:
    //
    // A security problem occurred.
    //
    INET_E_SECURITY_PROBLEM = 0x800C000EL,

    //
    // MessageId: INET_E_CANNOT_LOAD_DATA
    //
    // MessageText:
    //
    // The system could not load the persisted data.
    //
    INET_E_CANNOT_LOAD_DATA = 0x800C000FL,

    //
    // MessageId: INET_E_CANNOT_INSTANTIATE_OBJECT
    //
    // MessageText:
    //
    // Unable to instantiate the object.
    //
    INET_E_CANNOT_INSTANTIATE_OBJECT = 0x800C0010L,

    //
    // MessageId: INET_E_INVALID_CERTIFICATE
    //
    // MessageText:
    //
    // Security certificate required to access this resource is invalid.
    //
    INET_E_INVALID_CERTIFICATE = 0x800C0019L,

    //
    // MessageId: INET_E_REDIRECT_FAILED
    //
    // MessageText:
    //
    // A redirection problem occurred.
    //
    INET_E_REDIRECT_FAILED = 0x800C0014L,

    //
    // MessageId: INET_E_REDIRECT_TO_DIR
    //
    // MessageText:
    //
    // The requested resource is a directory, not a file.
    //
    INET_E_REDIRECT_TO_DIR = 0x800C0015L,

    //
    // Debuggers
    //
    //
    // MessageId: ERROR_DBG_CREATE_PROCESS_FAILURE_LOCKDOWN
    //
    // MessageText:
    //
    // Could not create new process from ARM architecture device.
    //
    ERROR_DBG_CREATE_PROCESS_FAILURE_LOCKDOWN = 0x80B00001L,

    //
    // MessageId: ERROR_DBG_ATTACH_PROCESS_FAILURE_LOCKDOWN
    //
    // MessageText:
    //
    // Could not attach to the application process from ARM architecture device.
    //
    ERROR_DBG_ATTACH_PROCESS_FAILURE_LOCKDOWN = 0x80B00002L,

    //
    // MessageId: ERROR_DBG_CONNECT_SERVER_FAILURE_LOCKDOWN
    //
    // MessageText:
    //
    // Could not connect to dbgsrv server from ARM architecture device.
    //
    ERROR_DBG_CONNECT_SERVER_FAILURE_LOCKDOWN = 0x80B00003L,

    //
    // MessageId: ERROR_DBG_START_SERVER_FAILURE_LOCKDOWN
    //
    // MessageText:
    //
    // Could not start dbgsrv server from ARM architecture device.
    //
    ERROR_DBG_START_SERVER_FAILURE_LOCKDOWN = 0x80B00004L,

    //
    //Sdbus
    //
    //
    // MessageId: ERROR_IO_PREEMPTED
    //
    // MessageText:
    //
    // The operation was preempted by a higher priority operation. It must be resumed later.
    //
    ERROR_IO_PREEMPTED = 0x89010001L,

    //
    //JScript
    //
    //
    // MessageId: JSCRIPT_E_CANTEXECUTE
    //
    // MessageText:
    //
    // Function could not execute because it was deleted or garbage collected.
    //
    JSCRIPT_E_CANTEXECUTE = 0x89020001L,

    //
    //WEP - Windows Encryption Providers
    //
    //
    // MessageId: WEP_E_NOT_PROVISIONED_ON_ALL_VOLUMES
    //
    // MessageText:
    //
    // One or more fixed volumes are not provisioned with the 3rd party encryption providers to support device encryption. Enable encryption with the 3rd party provider to comply with policy.
    //
    WEP_E_NOT_PROVISIONED_ON_ALL_VOLUMES = 0x88010001L,

    //
    // MessageId: WEP_E_FIXED_DATA_NOT_SUPPORTED
    //
    // MessageText:
    //
    // This computer is not fully encrypted. There are fixed volumes present which are not supported for encryption.
    //
    WEP_E_FIXED_DATA_NOT_SUPPORTED = 0x88010002L,

    //
    // MessageId: WEP_E_HARDWARE_NOT_COMPLIANT
    //
    // MessageText:
    //
    // This computer does not meet the hardware requirements to support device encryption with the installed 3rd party provider.
    //
    WEP_E_HARDWARE_NOT_COMPLIANT = 0x88010003L,

    //
    //device lock feature - requires encryption software to use something like a TPM or a secure location to store failed counts of the password in an interactive logon to lock out the device
    //
    //
    // MessageId: WEP_E_LOCK_NOT_CONFIGURED
    //
    // MessageText:
    //
    // This computer cannot support device encryption because the requisites for the device lock feature are not configured.
    //
    WEP_E_LOCK_NOT_CONFIGURED = 0x88010004L,

    //
    // MessageId: WEP_E_PROTECTION_SUSPENDED
    //
    // MessageText:
    //
    // Protection is enabled on this volume but is not in the active state.
    //
    WEP_E_PROTECTION_SUSPENDED = 0x88010005L,

    //
    // MessageId: WEP_E_NO_LICENSE
    //
    // MessageText:
    //
    // The 3rd party provider has been installed, but cannot activate encryption beacuse a license has not been activated.
    //
    WEP_E_NO_LICENSE = 0x88010006L,

    //
    // MessageId: WEP_E_OS_NOT_PROTECTED
    //
    // MessageText:
    //
    // The operating system drive is not protected by 3rd party drive encryption.
    //
    WEP_E_OS_NOT_PROTECTED = 0x88010007L,

    //
    // MessageId: WEP_E_UNEXPECTED_FAIL
    //
    // MessageText:
    //
    // Unexpected failure was encountered while calling into the 3rd Party drive encryption plugin.
    //
    WEP_E_UNEXPECTED_FAIL = 0x88010008L,

    //
    // MessageId: WEP_E_BUFFER_TOO_LARGE
    //
    // MessageText:
    //
    // The input buffer size for the lockout metadata used by the 3rd party drive encryption is too large.
    //
    WEP_E_BUFFER_TOO_LARGE = 0x88010009L,

    //
    // Shared VHDX status codes (svhdxflt.sys)
    //
    //
    // MessageId: ERROR_SVHDX_ERROR_STORED
    //
    // MessageText:
    //
    // The proper error code with sense data was stored on server side.
    //
    ERROR_SVHDX_ERROR_STORED = 0xC05C0000L,

    //
    // MessageId: ERROR_SVHDX_ERROR_NOT_AVAILABLE
    //
    // MessageText:
    //
    // The requested error data is not available on the server.
    //
    ERROR_SVHDX_ERROR_NOT_AVAILABLE = 0xC05CFF00L,

    //
    // MessageId: ERROR_SVHDX_UNIT_ATTENTION_AVAILABLE
    //
    // MessageText:
    //
    // Unit Attention data is available for the initiator to query.
    //
    ERROR_SVHDX_UNIT_ATTENTION_AVAILABLE = 0xC05CFF01L,

    //
    // MessageId: ERROR_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED
    //
    // MessageText:
    //
    // The data capacity of the device has changed, resulting in a Unit Attention condition.
    //
    ERROR_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED = 0xC05CFF02L,

    //
    // MessageId: ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED
    //
    // MessageText:
    //
    // A previous operation resulted in this initiator's reservations being preempted, resulting in a Unit Attention condition.
    //
    ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED = 0xC05CFF03L,

    //
    // MessageId: ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED
    //
    // MessageText:
    //
    // A previous operation resulted in this initiator's reservations being released, resulting in a Unit Attention condition.
    //
    ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED = 0xC05CFF04L,

    //
    // MessageId: ERROR_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED
    //
    // MessageText:
    //
    // A previous operation resulted in this initiator's registrations being preempted, resulting in a Unit Attention condition.
    //
    ERROR_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED = 0xC05CFF05L,

    //
    // MessageId: ERROR_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED
    //
    // MessageText:
    //
    // The data storage format of the device has changed, resulting in a Unit Attention condition.
    //
    ERROR_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED = 0xC05CFF06L,

    //
    // MessageId: ERROR_SVHDX_RESERVATION_CONFLICT
    //
    // MessageText:
    //
    // The current initiator is not allowed to perform the SCSI command because of a reservation conflict.
    //
    ERROR_SVHDX_RESERVATION_CONFLICT = 0xC05CFF07L,

    //
    // MessageId: ERROR_SVHDX_WRONG_FILE_TYPE
    //
    // MessageText:
    //
    // Multiple virtual machines sharing a virtual hard disk is supported only on Fixed or Dynamic VHDX format virtual hard disks.
    //
    ERROR_SVHDX_WRONG_FILE_TYPE = 0xC05CFF08L,

    //
    // MessageId: ERROR_SVHDX_VERSION_MISMATCH
    //
    // MessageText:
    //
    // The server version does not match the requested version.
    //
    ERROR_SVHDX_VERSION_MISMATCH = 0xC05CFF09L,

    //
    // MessageId: ERROR_VHD_SHARED
    //
    // MessageText:
    //
    // The requested operation cannot be performed on the virtual disk as it is currently used in shared mode.
    //
    ERROR_VHD_SHARED = 0xC05CFF0AL,

    //
    // WININET.DLL errors - propagated as HRESULT's using FACILITY=WIN32
    //
    //
    // MessageId: WININET_E_OUT_OF_HANDLES
    //
    // MessageText:
    //
    // No more Internet handles can be allocated
    //
    WININET_E_OUT_OF_HANDLES = 0x80072EE1L,

    //
    // MessageId: WININET_E_TIMEOUT
    //
    // MessageText:
    //
    // The operation timed out
    //
    WININET_E_TIMEOUT = 0x80072EE2L,

    //
    // MessageId: WININET_E_EXTENDED_ERROR
    //
    // MessageText:
    //
    // The server returned extended information
    //
    WININET_E_EXTENDED_ERROR = 0x80072EE3L,

    //
    // MessageId: WININET_E_INTERNAL_ERROR
    //
    // MessageText:
    //
    // An internal error occurred in the Microsoft Internet extensions
    //
    WININET_E_INTERNAL_ERROR = 0x80072EE4L,

    //
    // MessageId: WININET_E_INVALID_URL
    //
    // MessageText:
    //
    // The URL is invalid
    //
    WININET_E_INVALID_URL = 0x80072EE5L,

    //
    // MessageId: WININET_E_UNRECOGNIZED_SCHEME
    //
    // MessageText:
    //
    // The URL does not use a recognized protocol
    //
    WININET_E_UNRECOGNIZED_SCHEME = 0x80072EE6L,

    //
    // MessageId: WININET_E_NAME_NOT_RESOLVED
    //
    // MessageText:
    //
    // The server name or address could not be resolved
    //
    WININET_E_NAME_NOT_RESOLVED = 0x80072EE7L,

    //
    // MessageId: WININET_E_PROTOCOL_NOT_FOUND
    //
    // MessageText:
    //
    // A protocol with the required capabilities was not found
    //
    WININET_E_PROTOCOL_NOT_FOUND = 0x80072EE8L,

    //
    // MessageId: WININET_E_INVALID_OPTION
    //
    // MessageText:
    //
    // The option is invalid
    //
    WININET_E_INVALID_OPTION = 0x80072EE9L,

    //
    // MessageId: WININET_E_BAD_OPTION_LENGTH
    //
    // MessageText:
    //
    // The length is incorrect for the option type
    //
    WININET_E_BAD_OPTION_LENGTH = 0x80072EEAL,

    //
    // MessageId: WININET_E_OPTION_NOT_SETTABLE
    //
    // MessageText:
    //
    // The option value cannot be set
    //
    WININET_E_OPTION_NOT_SETTABLE = 0x80072EEBL,

    //
    // MessageId: WININET_E_SHUTDOWN
    //
    // MessageText:
    //
    // Microsoft Internet Extension support has been shut down
    //
    WININET_E_SHUTDOWN = 0x80072EECL,

    //
    // MessageId: WININET_E_INCORRECT_USER_NAME
    //
    // MessageText:
    //
    // The user name was not allowed
    //
    WININET_E_INCORRECT_USER_NAME = 0x80072EEDL,

    //
    // MessageId: WININET_E_INCORRECT_PASSWORD
    //
    // MessageText:
    //
    // The password was not allowed
    //
    WININET_E_INCORRECT_PASSWORD = 0x80072EEEL,

    //
    // MessageId: WININET_E_LOGIN_FAILURE
    //
    // MessageText:
    //
    // The login request was denied
    //
    WININET_E_LOGIN_FAILURE = 0x80072EEFL,

    //
    // MessageId: WININET_E_INVALID_OPERATION
    //
    // MessageText:
    //
    // The requested operation is invalid
    //
    WININET_E_INVALID_OPERATION = 0x80072EF0L,

    //
    // MessageId: WININET_E_OPERATION_CANCELLED
    //
    // MessageText:
    //
    // The operation has been canceled
    //
    WININET_E_OPERATION_CANCELLED = 0x80072EF1L,

    //
    // MessageId: WININET_E_INCORRECT_HANDLE_TYPE
    //
    // MessageText:
    //
    // The supplied handle is the wrong type for the requested operation
    //
    WININET_E_INCORRECT_HANDLE_TYPE = 0x80072EF2L,

    //
    // MessageId: WININET_E_INCORRECT_HANDLE_STATE
    //
    // MessageText:
    //
    // The handle is in the wrong state for the requested operation
    //
    WININET_E_INCORRECT_HANDLE_STATE = 0x80072EF3L,

    //
    // MessageId: WININET_E_NOT_PROXY_REQUEST
    //
    // MessageText:
    //
    // The request cannot be made on a Proxy session
    //
    WININET_E_NOT_PROXY_REQUEST = 0x80072EF4L,

    //
    // MessageId: WININET_E_REGISTRY_VALUE_NOT_FOUND
    //
    // MessageText:
    //
    // The registry value could not be found
    //
    WININET_E_REGISTRY_VALUE_NOT_FOUND = 0x80072EF5L,

    //
    // MessageId: WININET_E_BAD_REGISTRY_PARAMETER
    //
    // MessageText:
    //
    // The registry parameter is incorrect
    //
    WININET_E_BAD_REGISTRY_PARAMETER = 0x80072EF6L,

    //
    // MessageId: WININET_E_NO_DIRECT_ACCESS
    //
    // MessageText:
    //
    // Direct Internet access is not available
    //
    WININET_E_NO_DIRECT_ACCESS = 0x80072EF7L,

    //
    // MessageId: WININET_E_NO_CONTEXT
    //
    // MessageText:
    //
    // No context value was supplied
    //
    WININET_E_NO_CONTEXT = 0x80072EF8L,

    //
    // MessageId: WININET_E_NO_CALLBACK
    //
    // MessageText:
    //
    // No status callback was supplied
    //
    WININET_E_NO_CALLBACK = 0x80072EF9L,

    //
    // MessageId: WININET_E_REQUEST_PENDING
    //
    // MessageText:
    //
    // There are outstanding requests
    //
    WININET_E_REQUEST_PENDING = 0x80072EFAL,

    //
    // MessageId: WININET_E_INCORRECT_FORMAT
    //
    // MessageText:
    //
    // The information format is incorrect
    //
    WININET_E_INCORRECT_FORMAT = 0x80072EFBL,

    //
    // MessageId: WININET_E_ITEM_NOT_FOUND
    //
    // MessageText:
    //
    // The requested item could not be found
    //
    WININET_E_ITEM_NOT_FOUND = 0x80072EFCL,

    //
    // MessageId: WININET_E_CANNOT_CONNECT
    //
    // MessageText:
    //
    // A connection with the server could not be established
    //
    WININET_E_CANNOT_CONNECT = 0x80072EFDL,

    //
    // MessageId: WININET_E_CONNECTION_ABORTED
    //
    // MessageText:
    //
    // The connection with the server was terminated abnormally
    //
    WININET_E_CONNECTION_ABORTED = 0x80072EFEL,

    //
    // MessageId: WININET_E_CONNECTION_RESET
    //
    // MessageText:
    //
    // The connection with the server was reset
    //
    WININET_E_CONNECTION_RESET = 0x80072EFFL,

    //
    // MessageId: WININET_E_FORCE_RETRY
    //
    // MessageText:
    //
    // The action must be retried
    //
    WININET_E_FORCE_RETRY = 0x80072F00L,

    //
    // MessageId: WININET_E_INVALID_PROXY_REQUEST
    //
    // MessageText:
    //
    // The proxy request is invalid
    //
    WININET_E_INVALID_PROXY_REQUEST = 0x80072F01L,

    //
    // MessageId: WININET_E_NEED_UI
    //
    // MessageText:
    //
    // User interaction is required to complete the operation
    //
    WININET_E_NEED_UI = 0x80072F02L,

    //
    // MessageId: WININET_E_HANDLE_EXISTS
    //
    // MessageText:
    //
    // The handle already exists
    //
    WININET_E_HANDLE_EXISTS = 0x80072F04L,

    //
    // MessageId: WININET_E_SEC_CERT_DATE_INVALID
    //
    // MessageText:
    //
    // The date in the certificate is invalid or has expired
    //
    WININET_E_SEC_CERT_DATE_INVALID = 0x80072F05L,

    //
    // MessageId: WININET_E_SEC_CERT_CN_INVALID
    //
    // MessageText:
    //
    // The host name in the certificate is invalid or does not match
    //
    WININET_E_SEC_CERT_CN_INVALID = 0x80072F06L,

    //
    // MessageId: WININET_E_HTTP_TO_HTTPS_ON_REDIR
    //
    // MessageText:
    //
    // A redirect request will change a non-secure to a secure connection
    //
    WININET_E_HTTP_TO_HTTPS_ON_REDIR = 0x80072F07L,

    //
    // MessageId: WININET_E_HTTPS_TO_HTTP_ON_REDIR
    //
    // MessageText:
    //
    // A redirect request will change a secure to a non-secure connection
    //
    WININET_E_HTTPS_TO_HTTP_ON_REDIR = 0x80072F08L,

    //
    // MessageId: WININET_E_MIXED_SECURITY
    //
    // MessageText:
    //
    // Mixed secure and non-secure connections
    //
    WININET_E_MIXED_SECURITY = 0x80072F09L,

    //
    // MessageId: WININET_E_CHG_POST_IS_NON_SECURE
    //
    // MessageText:
    //
    // Changing to non-secure post
    //
    WININET_E_CHG_POST_IS_NON_SECURE = 0x80072F0AL,

    //
    // MessageId: WININET_E_POST_IS_NON_SECURE
    //
    // MessageText:
    //
    // Data is being posted on a non-secure connection
    //
    WININET_E_POST_IS_NON_SECURE = 0x80072F0BL,

    //
    // MessageId: WININET_E_CLIENT_AUTH_CERT_NEEDED
    //
    // MessageText:
    //
    // A certificate is required to complete client authentication
    //
    WININET_E_CLIENT_AUTH_CERT_NEEDED = 0x80072F0CL,

    //
    // MessageId: WININET_E_INVALID_CA
    //
    // MessageText:
    //
    // The certificate authority is invalid or incorrect
    //
    WININET_E_INVALID_CA = 0x80072F0DL,

    //
    // MessageId: WININET_E_CLIENT_AUTH_NOT_SETUP
    //
    // MessageText:
    //
    // Client authentication has not been correctly installed
    //
    WININET_E_CLIENT_AUTH_NOT_SETUP = 0x80072F0EL,

    //
    // MessageId: WININET_E_ASYNC_THREAD_FAILED
    //
    // MessageText:
    //
    // An error has occurred in a Wininet asynchronous thread. You may need to restart
    //
    WININET_E_ASYNC_THREAD_FAILED = 0x80072F0FL,

    //
    // MessageId: WININET_E_REDIRECT_SCHEME_CHANGE
    //
    // MessageText:
    //
    // The protocol scheme has changed during a redirect operaiton
    //
    WININET_E_REDIRECT_SCHEME_CHANGE = 0x80072F10L,

    //
    // MessageId: WININET_E_DIALOG_PENDING
    //
    // MessageText:
    //
    // There are operations awaiting retry
    //
    WININET_E_DIALOG_PENDING = 0x80072F11L,

    //
    // MessageId: WININET_E_RETRY_DIALOG
    //
    // MessageText:
    //
    // The operation must be retried
    //
    WININET_E_RETRY_DIALOG = 0x80072F12L,

    //
    // MessageId: WININET_E_NO_NEW_CONTAINERS
    //
    // MessageText:
    //
    // There are no new cache containers
    //
    WININET_E_NO_NEW_CONTAINERS = 0x80072F13L,

    //
    // MessageId: WININET_E_HTTPS_HTTP_SUBMIT_REDIR
    //
    // MessageText:
    //
    // A security zone check indicates the operation must be retried
    //
    WININET_E_HTTPS_HTTP_SUBMIT_REDIR = 0x80072F14L,

    //
    // MessageId: WININET_E_SEC_CERT_ERRORS
    //
    // MessageText:
    //
    // The SSL certificate contains errors.
    //
    WININET_E_SEC_CERT_ERRORS = 0x80072F17L,

    //
    // MessageId: WININET_E_SEC_CERT_REV_FAILED
    //
    // MessageText:
    //
    // It was not possible to connect to the revocation server or a definitive response could not be obtained.
    //
    WININET_E_SEC_CERT_REV_FAILED = 0x80072F19L,

    //
    // MessageId: WININET_E_HEADER_NOT_FOUND
    //
    // MessageText:
    //
    // The requested header was not found
    //
    WININET_E_HEADER_NOT_FOUND = 0x80072F76L,

    //
    // MessageId: WININET_E_DOWNLEVEL_SERVER
    //
    // MessageText:
    //
    // The server does not support the requested protocol level
    //
    WININET_E_DOWNLEVEL_SERVER = 0x80072F77L,

    //
    // MessageId: WININET_E_INVALID_SERVER_RESPONSE
    //
    // MessageText:
    //
    // The server returned an invalid or unrecognized response
    //
    WININET_E_INVALID_SERVER_RESPONSE = 0x80072F78L,

    //
    // MessageId: WININET_E_INVALID_HEADER
    //
    // MessageText:
    //
    // The supplied HTTP header is invalid
    //
    WININET_E_INVALID_HEADER = 0x80072F79L,

    //
    // MessageId: WININET_E_INVALID_QUERY_REQUEST
    //
    // MessageText:
    //
    // The request for a HTTP header is invalid
    //
    WININET_E_INVALID_QUERY_REQUEST = 0x80072F7AL,

    //
    // MessageId: WININET_E_HEADER_ALREADY_EXISTS
    //
    // MessageText:
    //
    // The HTTP header already exists
    //
    WININET_E_HEADER_ALREADY_EXISTS = 0x80072F7BL,

    //
    // MessageId: WININET_E_REDIRECT_FAILED
    //
    // MessageText:
    //
    // The HTTP redirect request failed
    //
    WININET_E_REDIRECT_FAILED = 0x80072F7CL,

    //
    // MessageId: WININET_E_SECURITY_CHANNEL_ERROR
    //
    // MessageText:
    //
    // An error occurred in the secure channel support
    //
    WININET_E_SECURITY_CHANNEL_ERROR = 0x80072F7DL,

    //
    // MessageId: WININET_E_UNABLE_TO_CACHE_FILE
    //
    // MessageText:
    //
    // The file could not be written to the cache
    //
    WININET_E_UNABLE_TO_CACHE_FILE = 0x80072F7EL,

    //
    // MessageId: WININET_E_TCPIP_NOT_INSTALLED
    //
    // MessageText:
    //
    // The TCP/IP protocol is not installed properly
    //
    WININET_E_TCPIP_NOT_INSTALLED = 0x80072F7FL,

    //
    // MessageId: WININET_E_DISCONNECTED
    //
    // MessageText:
    //
    // The computer is disconnected from the network
    //
    WININET_E_DISCONNECTED = 0x80072F83L,

    //
    // MessageId: WININET_E_SERVER_UNREACHABLE
    //
    // MessageText:
    //
    // The server is unreachable
    //
    WININET_E_SERVER_UNREACHABLE = 0x80072F84L,

    //
    // MessageId: WININET_E_PROXY_SERVER_UNREACHABLE
    //
    // MessageText:
    //
    // The proxy server is unreachable
    //
    WININET_E_PROXY_SERVER_UNREACHABLE = 0x80072F85L,

    //
    // MessageId: WININET_E_BAD_AUTO_PROXY_SCRIPT
    //
    // MessageText:
    //
    // The proxy auto-configuration script is in error
    //
    WININET_E_BAD_AUTO_PROXY_SCRIPT = 0x80072F86L,

    //
    // MessageId: WININET_E_UNABLE_TO_DOWNLOAD_SCRIPT
    //
    // MessageText:
    //
    // Could not download the proxy auto-configuration script file
    //
    WININET_E_UNABLE_TO_DOWNLOAD_SCRIPT = 0x80072F87L,

    //
    // MessageId: WININET_E_SEC_INVALID_CERT
    //
    // MessageText:
    //
    // The supplied certificate is invalid
    //
    WININET_E_SEC_INVALID_CERT = 0x80072F89L,

    //
    // MessageId: WININET_E_SEC_CERT_REVOKED
    //
    // MessageText:
    //
    // The supplied certificate has been revoked
    //
    WININET_E_SEC_CERT_REVOKED = 0x80072F8AL,

    //
    // MessageId: WININET_E_FAILED_DUETOSECURITYCHECK
    //
    // MessageText:
    //
    // The Dialup failed because file sharing was turned on and a failure was requested if security check was needed
    //
    WININET_E_FAILED_DUETOSECURITYCHECK = 0x80072F8BL,

    //
    // MessageId: WININET_E_NOT_INITIALIZED
    //
    // MessageText:
    //
    // Initialization of the WinINet API has not occurred
    //
    WININET_E_NOT_INITIALIZED = 0x80072F8CL,

    //
    // MessageId: WININET_E_LOGIN_FAILURE_DISPLAY_ENTITY_BODY
    //
    // MessageText:
    //
    // Login failed and the client should display the entity body to the user
    //
    WININET_E_LOGIN_FAILURE_DISPLAY_ENTITY_BODY = 0x80072F8EL,

    //
    // MessageId: WININET_E_DECODING_FAILED
    //
    // MessageText:
    //
    // Content decoding has failed
    //
    WININET_E_DECODING_FAILED = 0x80072F8FL,

    //
    // MessageId: WININET_E_NOT_REDIRECTED
    //
    // MessageText:
    //
    // The HTTP request was not redirected
    //
    WININET_E_NOT_REDIRECTED = 0x80072F80L,

    //
    // MessageId: WININET_E_COOKIE_NEEDS_CONFIRMATION
    //
    // MessageText:
    //
    // A cookie from the server must be confirmed by the user
    //
    WININET_E_COOKIE_NEEDS_CONFIRMATION = 0x80072F81L,

    //
    // MessageId: WININET_E_COOKIE_DECLINED
    //
    // MessageText:
    //
    // A cookie from the server has been declined acceptance
    //
    WININET_E_COOKIE_DECLINED = 0x80072F82L,

    //
    // MessageId: WININET_E_REDIRECT_NEEDS_CONFIRMATION
    //
    // MessageText:
    //
    // The HTTP redirect request must be confirmed by the user
    //
    WININET_E_REDIRECT_NEEDS_CONFIRMATION = 0x80072F88L,
};

//
// Generic test for success on any status value (non-negative numbers
// indicate success).
//

#define SUCCEEDED(hr) (((long)(hr)) >= 0)

//
// and the inverse
//

#define FAILED(hr) (((long)(hr)) < 0)

//
// Generic test for error on any status value.
//

#define IS_ERROR(Status) (((unsigned long)(Status)) >> 31 == 1)


#define FACILITY_NT_BIT         0x10000000
#define HRESULT_FROM_NT(x)      ((HRESULT) ((x) | FACILITY_NT_BIT))


#define HRESULT_FROM_WIN32(x) ((long)(x) <= 0 ? ((HRESULT)(x)) : ((HRESULT) (((x) & 0x0000FFFF) | (FACILITY_WIN32 << 16) | 0x80000000)))


#define HRESULT_FROM_SETUPAPI(x) ((((x) & (APPLICATION_ERROR_MASK | ERROR_SEVERITY_ERROR)) == (APPLICATION_ERROR_MASK | ERROR_SEVERITY_ERROR)) \
                                      ? ((HRESULT)(((x)&0x0000FFFF) | (FACILITY_SETUPAPI << 16) | 0x80000000))                                 \
                                      : HRESULT_FROM_WIN32(x))
