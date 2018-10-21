#include "bindings.h"

#pragma once

#if defined(ON_PYTHON_COMPILE)
void initExtrusionBindings(pybind11::module& m);
#else
void initExtrusionBindings(void* m);
#endif

class BND_Extrusion : public BND_Surface
{
  ON_Extrusion* m_extrusion = nullptr;
protected:
  void SetTrackedPointer(ON_Extrusion* extrusion, const ON_ModelComponentReference* compref);

public:
  static BND_Extrusion* Create(const class BND_Curve& planarCurve, double height, bool cap);
  //static BND_Extrusion* CreateBoxExtrusion(Box box, bool cap = true);
  static BND_Extrusion* CreateCylinderExtrusion(const class BND_Cylinder& cylinder, bool capBottom, bool capTop);
  static BND_Extrusion* CreatePipeExtrusion(const class BND_Cylinder& cylinder, double otherRadius, bool capTop, bool capBottom);
  BND_Extrusion();
  class BND_Brep* ToBrep(bool splitKinkyFaces) const;
  bool SetPathAndUp(ON_3dPoint a, ON_3dPoint b, ON_3dVector up);
  ON_3dPoint PathStart() const { return m_extrusion->PathStart(); }
  ON_3dPoint PathEnd() const { return m_extrusion->PathEnd(); }
  ON_3dVector PathTangent() const { return m_extrusion->PathTangent(); }
  //ON_3dVector MiterPlaneNormalAtStart() const;
  //void SetMiterPlaneNormalAtStart(ON_3dVector v);
  //ON_3dVector MiterPlaneNormalAtEnd() const;
  //void SetMiterPlaneNormalAtEnd(ON_3dVector v);
  //bool IsMiteredAtStart() const;
  //bool IsMiteredAtEnd() const;
  bool IsSolid() const { return m_extrusion->IsSolid(); }
  //bool IsCappedAtBottom() const;
  //bool IsCappedAtTop() const;
  int CapCount() const { return m_extrusion->CapCount(); }
  //Transform GetProfileTransformation(double s)
  //Plane GetProfilePlane(double s)
  //Plane GetPathPlane(double s)
  //bool SetOuterProfile(Curve outerProfile, bool cap)
  //bool AddInnerProfile(Curve innerProfile)
  //int ProfileCount | get;
  //Curve Profile3d(int profileIndex, double s)
  //Curve Profile3d(ComponentIndex ci)
  //Curve WallEdge(ComponentIndex ci)
  //Surface WallSurface(ComponentIndex ci)
  //LineCurve PathLineCurve()
  //int ProfileIndex(double profileParameter)
  class BND_Mesh* GetMesh(ON::mesh_type meshType);

  BND_Extrusion(ON_Extrusion* extrusion, const ON_ModelComponentReference* compref);

};
