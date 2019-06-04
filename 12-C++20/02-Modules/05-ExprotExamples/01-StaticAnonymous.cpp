
// ANONYMOUS NAMESPACE
namespace {

   export void do_stuff() {
       // ...
   }

   export int five = 5;

   export class stuff {
       // ...
   };

}

export static void do_more_stuff() {
    // ...
}

export static int twelve = 12;

export namespace foo {

   int eight = 8; // Exported as `foo::eight`.

   static int nine = 0; 

   namespace {
      void do_stuff() {
        // ... 
      }
   }

}