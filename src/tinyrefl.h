#include <map>
#include <string>

#define DESCRIPTOR_DB_DEC(Classname)                                \
  namespace tinyrefl {                                              \
  struct Descriptor {                                               \
    std::string name;                                               \
    Classname *msgptr;                                              \
  };                                                                \
  class DescriptorDatabase {                                        \
   public:                                                          \
    std::map<std::string, Descriptor> kdd;                          \
    void AddDescriptor(Descriptor d) { kdd[d.name] = d; }           \
    Classname *FindHandlerByName(const std::string &name) {         \
      if (kdd.find(name) == kdd.end()) return NULL;                 \
      return kdd[name].msgptr;                                      \
    }                                                               \
    void GlobalShutDown() {                                         \
      std::map<std::string, Descriptor>::iterator it = kdd.begin(); \
      for (; it != kdd.end(); it++) {                               \
        if (it->second.msgptr) {                                    \
          delete it->second.msgptr;                                 \
          it->second.msgptr = NULL;                                 \
        }                                                           \
      }                                                             \
    }                                                               \
  };                                                                \
  extern DescriptorDatabase *kdb;                                   \
  inline void InitDatabaseOnce() {                                  \
    if (!kdb) kdb = new DescriptorDatabase();                       \
  }                                                                 \
  inline Classname *MessageFactory(const std::string &name) {       \
    if (!kdb) return NULL;                                          \
    return kdb->FindHandlerByName(name);                            \
  }                                                                 \
  inline void DestroyMessageFactory() {                             \
    if (kdb) kdb->GlobalShutDown();                                 \
  }                                                                 \
  }

#define DESCRIPTOR_DB_DEF(Classname)                             \
  namespace tinyrefl {                                           \
  DescriptorDatabase *kdb;                                       \
  struct TDescriptorDatabasesdfsdffsd {                          \
    ~TDescriptorDatabasesdfsdffsd() { DestroyMessageFactory(); } \
  };                                                             \
  }

#define TINYREFL_CLASS_DEC_BEGIN(Classname)                              \
  class Classname {                                                      \
   public:                                                               \
    Classname *New() { return new Classname(); }                         \
    static void Refl() { default_instance_ = new Classname(); }          \
    static Classname *GetDefaultInstance() { return default_instance_; } \
                                                                         \
   private:                                                              \
    static Classname *default_instance_;                                 \
                                                                         \
   public:
#define TINYREFL_CLASS_DEC_END(Classname) \
  }                                       \
  ;

#define TINYREFL_SUBCLASS_DEC_BEGIN(Classname, Parent)                   \
  class Classname : public Parent {                                      \
   public:                                                               \
    Classname *New() { return new Classname(); }                         \
    static void Refl() { default_instance_ = new Classname(); }          \
    static Classname *GetDefaultInstance() { return default_instance_; } \
                                                                         \
   private:                                                              \
    static Classname *default_instance_;                                 \
                                                                         \
   public:
#define TINYREFL_SUBCLASS_DEC_END(Classname, Parent) \
  }                                                  \
  ;

#define TINYREFL_CLASS_DEF(Classname)                              \
  static void Classname##__abksdfjsdkfdk() {                       \
    tinyrefl::InitDatabaseOnce();                                  \
    Classname::Refl();                                             \
    tinyrefl::Descriptor d;                                        \
    d.name = #Classname;                                           \
    d.msgptr = Classname::GetDefaultInstance();                    \
    tinyrefl::kdb->AddDescriptor(d);                               \
  }                                                                \
  static struct Classname##_Tabksdfjsdkfdk {                       \
    Classname##_Tabksdfjsdkfdk() { Classname##__abksdfjsdkfdk(); } \
  } v##Classname##_Tabksdfjsdkfd;                                  \
  Classname *Classname::default_instance_ = NULL;
