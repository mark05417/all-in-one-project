// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: person.proto
// Protobuf C++ Version: 5.30.0-dev

#include "person.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;

inline constexpr Person::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        name_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        email_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        id_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Person::Person(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(Person_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct PersonDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PersonDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~PersonDefaultTypeInternal() {}
  union {
    Person _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PersonDefaultTypeInternal _Person_default_instance_;
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_person_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_person_2eproto = nullptr;
const ::uint32_t
    TableStruct_person_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::Person, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::Person, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::Person, _impl_.id_),
        PROTOBUF_FIELD_OFFSET(::Person, _impl_.name_),
        PROTOBUF_FIELD_OFFSET(::Person, _impl_.email_),
        2,
        0,
        1,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 11, -1, sizeof(::Person)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_Person_default_instance_._instance,
};
const char descriptor_table_protodef_person_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\014person.proto\"1\n\006Person\022\n\n\002id\030\001 \001(\005\022\014\n\004"
    "name\030\002 \001(\t\022\r\n\005email\030\003 \001(\tb\006proto3"
};
static ::absl::once_flag descriptor_table_person_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_person_2eproto = {
    false,
    false,
    73,
    descriptor_table_protodef_person_2eproto,
    "person.proto",
    &descriptor_table_person_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_person_2eproto::offsets,
    file_level_enum_descriptors_person_2eproto,
    file_level_service_descriptors_person_2eproto,
};
// ===================================================================

class Person::_Internal {
 public:
  using HasBits =
      decltype(std::declval<Person>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(Person, _impl_._has_bits_);
};

Person::Person(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, Person_class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Person)
}
PROTOBUF_NDEBUG_INLINE Person::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::Person& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        name_(arena, from.name_),
        email_(arena, from.email_) {}

Person::Person(
    ::google::protobuf::Arena* arena,
    const Person& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, Person_class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  Person* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  _impl_.id_ = from._impl_.id_;

  // @@protoc_insertion_point(copy_constructor:Person)
}
PROTOBUF_NDEBUG_INLINE Person::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        name_(arena),
        email_(arena) {}

inline void Person::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.id_ = {};
}
Person::~Person() {
  // @@protoc_insertion_point(destructor:Person)
  SharedDtor(*this);
}
inline void Person::SharedDtor(MessageLite& self) {
  Person& this_ = static_cast<Person&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.name_.Destroy();
  this_._impl_.email_.Destroy();
  this_._impl_.~Impl_();
}

inline void* Person::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) Person(arena);
}
constexpr auto Person::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(Person),
                                            alignof(Person));
}
constexpr auto Person::InternalGenerateClassData_() {
  return ::google::protobuf::internal::ClassDataFull{
      ::google::protobuf::internal::ClassData{
          &_Person_default_instance_._instance,
          &_table_.header,
          nullptr,  // OnDemandRegisterArenaDtor
          nullptr,  // IsInitialized
          &Person::MergeImpl,
          ::google::protobuf::Message::GetNewImpl<Person>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
          &Person::SharedDtor,
          ::google::protobuf::Message::GetClearImpl<Person>(), &Person::ByteSizeLong,
              &Person::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
          PROTOBUF_FIELD_OFFSET(Person, _impl_._cached_size_),
          false,
      },
      &Person::kDescriptorMethods,
      &descriptor_table_person_2eproto,
      nullptr,  // tracker
  };
}

PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 const ::google::protobuf::internal::ClassDataFull
        Person_class_data_ =
            Person::InternalGenerateClassData_();

const ::google::protobuf::internal::ClassData* Person::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&Person_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(Person_class_data_.tc_table);
  return Person_class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 3, 0, 24, 2> Person::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Person, _impl_._has_bits_),
    0, // no _extensions_
    3, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967288,  // skipmap
    offsetof(decltype(_table_), field_entries),
    3,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    Person_class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::Person>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // int32 id = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Person, _impl_.id_), 2>(),
     {8, 2, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.id_)}},
    // string name = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 0, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.name_)}},
    // string email = 3;
    {::_pbi::TcParser::FastUS1,
     {26, 1, 0, PROTOBUF_FIELD_OFFSET(Person, _impl_.email_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int32 id = 1;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.id_), _Internal::kHasBitsOffset + 2, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // string name = 2;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.name_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string email = 3;
    {PROTOBUF_FIELD_OFFSET(Person, _impl_.email_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\6\0\4\5\0\0\0\0"
    "Person"
    "name"
    "email"
  }},
};

PROTOBUF_NOINLINE void Person::Clear() {
// @@protoc_insertion_point(message_clear_start:Person)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      _impl_.name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      _impl_.email_.ClearNonDefaultToEmpty();
    }
  }
  _impl_.id_ = 0;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* Person::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const Person& this_ = static_cast<const Person&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* Person::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const Person& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:Person)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // int32 id = 1;
          if ((this_._impl_._has_bits_[0] & 0x00000004u) != 0) {
            if (this_._internal_id() != 0) {
              target = ::google::protobuf::internal::WireFormatLite::
                  WriteInt32ToArrayWithField<1>(
                      stream, this_._internal_id(), target);
            }
          }

          // string name = 2;
          if ((this_._impl_._has_bits_[0] & 0x00000001u) != 0) {
            if (!this_._internal_name().empty()) {
              const std::string& _s = this_._internal_name();
              ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                  _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Person.name");
              target = stream->WriteStringMaybeAliased(2, _s, target);
            }
          }

          // string email = 3;
          if ((this_._impl_._has_bits_[0] & 0x00000002u) != 0) {
            if (!this_._internal_email().empty()) {
              const std::string& _s = this_._internal_email();
              ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                  _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Person.email");
              target = stream->WriteStringMaybeAliased(3, _s, target);
            }
          }

          if (ABSL_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:Person)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t Person::ByteSizeLong(const MessageLite& base) {
          const Person& this_ = static_cast<const Person&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t Person::ByteSizeLong() const {
          const Person& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:Person)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
          cached_has_bits = this_._impl_._has_bits_[0];
          if (cached_has_bits & 0x00000007u) {
            // string name = 2;
            if (cached_has_bits & 0x00000001u) {
              if (!this_._internal_name().empty()) {
                total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                                this_._internal_name());
              }
            }
            // string email = 3;
            if (cached_has_bits & 0x00000002u) {
              if (!this_._internal_email().empty()) {
                total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                                this_._internal_email());
              }
            }
            // int32 id = 1;
            if (cached_has_bits & 0x00000004u) {
              if (this_._internal_id() != 0) {
                total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
                    this_._internal_id());
              }
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void Person::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Person*>(&to_msg);
  auto& from = static_cast<const Person&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Person)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      if (!from._internal_name().empty()) {
        _this->_internal_set_name(from._internal_name());
      } else {
        if (_this->_impl_.name_.IsDefault()) {
          _this->_internal_set_name("");
        }
      }
    }
    if (cached_has_bits & 0x00000002u) {
      if (!from._internal_email().empty()) {
        _this->_internal_set_email(from._internal_email());
      } else {
        if (_this->_impl_.email_.IsDefault()) {
          _this->_internal_set_email("");
        }
      }
    }
    if (cached_has_bits & 0x00000004u) {
      if (from._internal_id() != 0) {
        _this->_impl_.id_ = from._impl_.id_;
      }
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Person::CopyFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Person::InternalSwap(Person* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.name_, &other->_impl_.name_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.email_, &other->_impl_.email_, arena);
        swap(_impl_.id_, other->_impl_.id_);
}

::google::protobuf::Metadata Person::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ [[maybe_unused]] =
        (::_pbi::AddDescriptors(&descriptor_table_person_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"