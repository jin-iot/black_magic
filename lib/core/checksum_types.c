#include <sentient/core/checksum_types.h>

static
snt_bool
snt_match_checksum_crc1(snt_void* data,
                             snt_size data_size)
{
    bool result = false;

    return result;
}

static
snt_bool
snt_match_checksum_crc5(snt_void* data,
                             snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc7(snt_void* data,
                             snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc8(snt_void* data,
                             snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc8_fletcher(snt_void* data,
                                      snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc16_fletcher(snt_void* data,
                                       snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc16_adler_a(snt_void* data,
                                      snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc16_adler_b(snt_void* data,
                                      snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc16_ccitt(snt_void* data,
                                    snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc16_ibm(snt_void* data,
                                  snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc32_adler(snt_void* data,
                                    snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc32_ieee_802_3(snt_void* data,
                                         snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc32_castagnoli(snt_void* data,
                                         snt_size data_size)
{
    bool result = false;

    return result;
}

static
snt_bool
snt_match_checksum_crc64_iso(snt_void* data,
                                  snt_size data_size)
{
    bool result = false;

    return result;
}
static
snt_bool
snt_match_checksum_crc64_ecma_182(snt_void* data,
                                       snt_size data_size)
{
    bool result = false;

    return result;
}

static
snt_bool
snt_match_checksum_crc128(snt_void* data,
                               snt_size data_size)
{
    bool result = false;

    return result;
}

snt_bool
snt_match_checksum(enum snt_checksum_types cs_type,
                        snt_void* cs_data,
                        snt_size  cs_data_size)
{
    snt_bool result = true;

    switch(cs_type)
    {
    case SENTIENT_CHECKSUM_TYPES_NONE:
    {
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC1:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC5:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC7:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC8:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC8_FLETCHER:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC16_FLETCHER:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC16_ADLER_A:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC16_ADLER_B:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC16_CCITT:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC16_IBM:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC32_ADLER:
    {
        result = snt_match_checksum_crc1(cs_data, cs_data_size);
        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC32_IEEE_802_3:
    {

        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC32_CASTAGNOLI:
    {

        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC64_ISO:
    {

        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC64_ECMA_182:
    {

        break;
    }
    case SENTIENT_CHECKSUM_TYPES_CRC128:
    {

        break;
    }
    }

    return result;
}