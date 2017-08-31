cc_library(
  name = 'KVSchedule',
  srcs = [
        'KVSchedule.cc',
  ],
  deps = [
    '//Common/Base:Base',
  ],
  extra_cppflags = ['-Werror=write-strings'],
)

cc_binary(name = 'KVTest',
    srcs = ['KVTest.cc'],
    deps = [
        ':KVSchedule',
        '//Common/Base:Base',
        '//Common/ThirdParty/gperftools-2.0/src:tcmalloc_minimal',
    ],
    optimize = ['O3'],
    extra_cppflags = ['-fno-omit-frame-pointer','-Wl,--eh-frame-hdr', '-ltcmalloc'],
)