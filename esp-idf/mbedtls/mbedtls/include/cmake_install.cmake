# Install script for directory: /media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aes.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aesni.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/arc4.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aria.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1write.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/base64.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bignum.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/blowfish.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bn_mul.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/camellia.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ccm.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/certs.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chacha20.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chachapoly.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/check_config.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher_internal.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cmac.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/compat-1.3.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ctr_drbg.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/debug.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/des.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/dhm.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdh.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdsa.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecjpake.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp_internal.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy_poll.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/error.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/gcm.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/havege.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hkdf.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hmac_drbg.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md2.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md4.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md5.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md_internal.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net_sockets.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/nist_kw.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/oid.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/padlock.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pem.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk_internal.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs11.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs12.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs5.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_time.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_util.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/poly1305.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ripemd160.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa_internal.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha1.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha256.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha512.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cache.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cookie.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_internal.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ticket.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/threading.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/timing.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/version.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crl.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crt.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_csr.h"
    "/media/f73377/HDD/projects/heatter/esp-idf/components/mbedtls/mbedtls/include/mbedtls/xtea.h"
    )
endif()

