#include <map>
#include <string>

#define DESCRIPTOR_DB_DEC(Classname) \
namespace tinyrefl { \
class Descriptor \
{ \
public: \
    std::string name_; \
    Classname *handler_base_; \
}; \
class DescriptorDatabase \
{ \
public: \
    std::map<std::string, Descriptor> kdd; \
    void AddDescriptor(Descriptor d) \
    { \
        kdd[d.name_] = d; \
    } \
    Classname *FindHandlerByName(const std::string &name) \
    { \
        if (kdd.find(name) == kdd.end()) \
            return NULL; \
        return kdd[name].handler_base_; \
    } \
    void GlobalShutDown() \
    { \
        std::map<std::string, Descriptor>::iterator it = kdd.begin(); \
        for (; it != kdd.end(); it++) \
        { \
            if (it->second.handler_base_) \
            { \
                delete it->second.handler_base_; \
                it->second.handler_base_ = NULL; \
            } \
        } \
    } \
}; \
extern DescriptorDatabase *kdb; \
inline void InitDatabaseOnce() \
{ \
    if (!kdb) kdb = new DescriptorDatabase(); \
} \
inline Classname *MessageFactory(const std::string &name) \
{ \
    if (!kdb) return NULL; \
    return kdb->FindHandlerByName(name); \
} \
inline void DestroyMessageFactory() \
{ \
    if (kdb) kdb->GlobalShutDown(); \
} \
} \

#define DESCRIPTOR_DB_DEF(Classname) \
namespace tinyrefl { \
DescriptorDatabase *kdb; \
struct TDescriptorDatabasesdfsdffsd \
{ \
    ~TDescriptorDatabasesdfsdffsd() \
    { \
        DestroyMessageFactory(); \
    } \
}; \
} \

#define TINYREFL_CLASS_DEC_BEGIN(Classname) \
class Classname \
{ \
public: \
    Classname *New() \
    { \
        return new Classname(); \
    } \
    static void Refl() \
    { \
        default_instance_ = new Classname(); \
    } \
    static Classname *GetDefaultInstance() \
    { \
        return default_instance_; \
    } \
private: \
    static Classname *default_instance_; \
public: \

#define TINYREFL_CLASS_DEC_END(Classname) \
}; \

#define TINYREFL_SUBCLASS_DEC_BEGIN(Classname, Parent) \
class Classname : public Parent\
{ \
public: \
    Classname *New() \
    { \
        return new Classname(); \
    } \
    static void Refl() \
    { \
        default_instance_ = new Classname(); \
    } \
    static Classname *GetDefaultInstance() \
    { \
        return default_instance_; \
    } \
private: \
    static Classname *default_instance_; \
public: \

#define TINYREFL_SUBCLASS_DEC_END(Classname, Parent) \
}; \

#define TINYREFL_CLASS_DEF(Classname) \
static void Classname##__abksdfjsdkfdk() \
{ \
    tinyrefl::InitDatabaseOnce(); \
    Classname::Refl(); \
    tinyrefl::Descriptor d; \
    d.name_ = #Classname; \
    d.handler_base_ = Classname::GetDefaultInstance(); \
    tinyrefl::kdb->AddDescriptor(d); \
} \
static struct Classname##_Tabksdfjsdkfdk \
{ \
    Classname##_Tabksdfjsdkfdk() \
    { \
        Classname##__abksdfjsdkfdk(); \
    } \
} v##Classname##_Tabksdfjsdkfd; \
Classname *Classname::default_instance_ = NULL; \

