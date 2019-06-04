namespace Stuff {
   export class Widget {};

   class Gadget {};

   namespace {

      class Gizmo {};

   } // namespace

} // namespace Stuff

export using Stuff::Widget; // Okay

export using Stuff::Gadget; // Not okay
export using Stuff::Gizmo; // Bad
export using namespace Stuff; // Nope

// internal, module linkage
