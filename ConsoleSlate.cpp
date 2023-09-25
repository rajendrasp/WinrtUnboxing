#include <inspectable.h>

template <typename T>
struct consume;

template <typename D, typename I = D>
using consume_t = typename consume<I>::template type<D>;

namespace ABI {
	struct __declspec(uuid("b176486a-d293-492c-a058-db575b3e3c0f")) __declspec(novtable)
		IContactField : public IInspectable
	{
	public:
		virtual HRESULT STDMETHODCALLTYPE get_Name(
			HSTRING* value
		) = 0;
		virtual HRESULT STDMETHODCALLTYPE get_Value(
			HSTRING* value
		) = 0;
	};
}

namespace winrt {
	interface IContactField;
}

template <typename D>
struct consume_Windows_ApplicationModel_Contacts_IContactField
{
	[[nodiscard]] auto Name() const;
	[[nodiscard]] auto Value() const;
};
template <> struct consume<winrt::IContactField>
{
	template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactField<D>;
};

struct take_ownership_from_abi_t {};
inline constexpr take_ownership_from_abi_t take_ownership_from_abi{};

template <typename D> auto consume_Windows_ApplicationModel_Contacts_IContactField<D>::Name() const
{
	return nullptr;
}
template <typename D> auto consume_Windows_ApplicationModel_Contacts_IContactField<D>::Value() const
{
	return nullptr;
}

namespace winrt {
	struct __declspec(empty_bases)IContactField :
		/*winrt::Windows::Foundation::IInspectable,*/
		consume_t<IContactField>
	{
		IContactField(std::nullptr_t = nullptr) noexcept {}
		IContactField(void* ptr, take_ownership_from_abi_t) noexcept /* : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) */ {}
	};
}

struct __declspec(empty_bases)ContactField : winrt::IContactField
{
	ContactField(std::nullptr_t) noexcept {}
	ContactField(void* ptr, take_ownership_from_abi_t) noexcept : IContactField(ptr, take_ownership_from_abi) {}
};

int main()
{
	ContactField field(nullptr);
	auto result = field.Name();

	int size = sizeof(field);
}
