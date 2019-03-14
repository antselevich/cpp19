#define ARRAYSIZE(x) (sizeof(x) / sizeof(x[0]))

#define FOREACH(i, x) \
  for (size_t i = 0; i != ARRAYSIZE(x); ++i)

#define RAW(ptr) ((char *)ptr)
#define UPCAST(type, basetype, ptr) \
  ((basetype *) (RAW(ptr) + offsetof(type, base)))
#define DOWNCAST(type, ptr) \
  ((type *) (RAW(ptr) - offsetof(type, base)))
