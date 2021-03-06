IMAGE_INSTALL_append = " \
    guest-addons \
    guest-addons-display-manager-service \
    guest-addons-bridge-up-notification-service \
    guest-addons-bridge-config \
    kmscube \
    logrotate \
    pulseaudio \
    alsa-utils \
    packagegroup-xt-core-guest-addons \
    packagegroup-xt-core-xen \
    packagegroup-xt-core-pv \
    packagegroup-xt-core-network \
    displaymanager \
"

#Add Xen and additional packages to build
IMAGE_INSTALL_append = " \
    dnsmasq \
    nftables \
    ntpdate-systemd \
    tzdata \
    xen-base \
    xen-flask \
    xen-xenstat \
"

# Configuration for ARM Trusted Firmware
EXTRA_IMAGEDEPENDS += " arm-trusted-firmware optee-os"

# u-boot
DEPENDS += " u-boot"

# Dom0 is a generic ARMv8 machine w/o machine overrides,
# but still needs to know which system we are building,
# e.g. Salvator-X M3 or H3, for instance
# So, we provide machine overrides from this build to Dom0
EXTRA_IMAGEDEPENDS += " domd-install-machine-overrides"

# We use systemd-networkd so we need to remove connman
IMAGE_INSTALL_remove = " \
    connman \
    connman-client \
    connman-tests \
    connman-tools \
    connman-ncurses \
    connman-conf \
    connman-gnome \
    cluster-connman-conf \
    libconnman-qt5_git \
"

# Do not support secure environment
IMAGE_INSTALL_remove = " \
    optee-linuxdriver \
    optee-linuxdriver-armtz \
    optee-client \
"

CORE_IMAGE_BASE_INSTALL_remove += "gtk+3-demo clutter-1.0-examples"

populate_vmlinux () {
    find ${STAGING_KERNEL_BUILDDIR} -iname "vmlinux*" -exec mv {} ${DEPLOY_DIR_IMAGE} \; || true
}

IMAGE_POSTPROCESS_COMMAND += "populate_vmlinux; "

