FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append = " file://0001-Make-compiler-target-aarch64-agl-linux-be-recognized.patch"

EXTRA_OEMAKE += "BIN_DESTDIR=${localstatedir}/local/bin"
EXTRA_OEMAKE += "SHARE_DESTDIR=${localstatedir}/local/share"

FILES_${PN}_append = "${localstatedir}/local/share/* \
                      ${localstatedir}/local/bin/* \
"
