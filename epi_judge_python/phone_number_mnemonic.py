def phone_mnemonic(phone_number):
    # Implement this placeholder.
    return []


from test_framework import generic_test, test_utils

if __name__ == '__main__':
    generic_test.generic_test_main(
        'phone_number_mnemonic.tsv',
        phone_mnemonic,
        comparator=test_utils.unordered_compare)
