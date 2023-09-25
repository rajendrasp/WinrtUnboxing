#include <vector>
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
		IContactField(const IContactField& other) noexcept {}
		IContactField(void* ptr, take_ownership_from_abi_t) noexcept /* : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) */ {}
	};
}

struct __declspec(empty_bases)ContactField : winrt::IContactField
{
	ContactField(std::nullptr_t) noexcept {}
	ContactField(const ContactField& other) noexcept {}
	ContactField(void* ptr, take_ownership_from_abi_t) noexcept : IContactField(ptr, take_ownership_from_abi) {}
};

struct base
{
	base() {}
	base(const base& other) noexcept {}
};

struct derived : base
{
	int data;
	derived(int in) : base() { data = in; }
	derived(const derived& other) : base(other) { this->data = other.data; }
};

int main()
{
	ContactField field(nullptr);
	auto result = field.Name();

	int size = sizeof(field);

	std::vector<winrt::IContactField> myvec(2);

	const winrt::IContactField& ref = field;

	myvec.push_back(ref);
	myvec.push_back(field);

	std::vector<base> bases;

	derived d1(10);
	base b1;
	derived d2(20);

	const derived& dref1 = d1;

	bases.push_back(d1);
	bases.push_back(d2);
	bases.push_back(b1);
	bases.push_back(dref1);

	
}


