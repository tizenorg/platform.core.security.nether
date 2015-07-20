MESSAGE(STATUS "Installing config files")

CONFIGURE_FILE(systemd/nether.service.in systemd/nether.service)

INSTALL(FILES nether.policy DESTINATION ${SYSCONF_INSTALL_DIR}/nether)
INSTALL(FILES nether.rules DESTINATION ${SYSCONF_INSTALL_DIR}/nether)
INSTALL(FILES systemd/nether.service DESTINATION ${SYSTEMD_UNIT_DIR})
INSTALL(FILES systemd/nether.service DESTINATION ${SYSTEMD_UNIT_DIR}/multi-user.target.wants)