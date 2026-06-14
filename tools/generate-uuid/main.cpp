#include <array>
#include <chrono>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

static bool isHexDigit(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F');
}

static std::string normalizePrefix(std::string prefix) {
    for (char &c : prefix) {
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }
    return prefix;
}

static bool validPrefix(const std::string &prefix) {
    if (prefix.size() != 3) {
        return false;
    }
    for (char c : prefix) {
        if (!isHexDigit(c)) {
            return false;
        }
    }
    return true;
}

static std::string toHex(uint64_t value, int width) {
    std::ostringstream ss;
    ss << std::uppercase << std::hex << std::setw(width) << std::setfill('0') << value;
    return ss.str();
}

static std::string formatUuid(const std::string &hex32) {
    return hex32.substr(0, 8) + "-" + hex32.substr(8, 4) + "-" + hex32.substr(12, 4) + "-" +
           hex32.substr(16, 4) + "-" + hex32.substr(20, 12);
}

static std::string generateTimeBasedUuid(const std::string &prefix, uint16_t sequence) {
    using namespace std::chrono;
    const auto now = system_clock::now();
    const auto ns = duration_cast<nanoseconds>(now.time_since_epoch()).count();

    std::random_device rd;
    const uint32_t randomLow = rd();
    const uint32_t randomHigh = rd();

    uint64_t timePart = static_cast<uint64_t>(ns);
    uint32_t sequencePart = static_cast<uint32_t>(sequence);
    uint32_t mixed = static_cast<uint32_t>((timePart >> 32) ^ sequencePart ^ randomLow);

    std::array<uint8_t, 16> bytes{};
    for (int i = 0; i < 8; ++i) {
        bytes[i] = static_cast<uint8_t>((timePart >> ((7 - i) * 8)) & 0xFFu);
    }
    bytes[8] = static_cast<uint8_t>((randomHigh >> 24) & 0xFFu);
    bytes[9] = static_cast<uint8_t>((randomHigh >> 16) & 0xFFu);
    bytes[10] = static_cast<uint8_t>((randomHigh >> 8) & 0xFFu);
    bytes[11] = static_cast<uint8_t>(randomHigh & 0xFFu);
    bytes[12] = static_cast<uint8_t>((sequencePart >> 8) & 0xFFu);
    bytes[13] = static_cast<uint8_t>(sequencePart & 0xFFu);
    bytes[14] = static_cast<uint8_t>((mixed >> 8) & 0xFFu);
    bytes[15] = static_cast<uint8_t>(mixed & 0xFFu);

    std::ostringstream hex;
    hex << std::uppercase << std::hex << std::setfill('0');
    for (uint8_t byte : bytes) {
        hex << std::setw(2) << static_cast<int>(byte);
    }

    std::string result = hex.str();
    result[0] = prefix[0];
    result[1] = prefix[1];
    result[2] = prefix[2];

    return formatUuid(result);
}

int main(int argc, char *argv[]) {
    std::string prefix;

    if (argc > 1) {
        prefix = argv[1];
    } else {
        std::cout << "Nhap prefix 3 ky tu hex (VD: D60): ";
        if (!std::getline(std::cin, prefix)) {
            return EXIT_FAILURE;
        }
    }

    prefix = normalizePrefix(prefix);
    if (!validPrefix(prefix)) {
        std::cerr << "Prefix khong hop le. Hay nhap 3 ky tu hex (0-9, A-F)." << std::endl;
        return EXIT_FAILURE;
    }

    for (uint16_t i = 0; i < 10; ++i) {
        std::cout << generateTimeBasedUuid(prefix, i) << std::endl;
    }

    return EXIT_SUCCESS;
}
