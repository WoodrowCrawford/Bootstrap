#version 410

in vec4 fPosition;
in vec4 fNormal;
in vec4 fColor;

uniform vec3 kAmbient;
uniform vec3 kDiffuse;
uniform vec3 kSpecular;
uniform float kSpecularPower;

uniform vec3 iDirection;
uniform vec3 iAmbient;
uniform vec3 iDiffuse;
uniform vec3 iSpecular;

uniform vec3 cameraPosition;

out vec4 pColor;

void main() {
	vec3 kNormal = normalize(fNormal.xyz);
	vec3 iNormal = normalize(iDirection);

	

	//Calculate ambient color
	vec3 ambientColor = (fColor.xyz + kAmbient) * iAmbient;

	//Calculate diffuse color
	float lambertTerm = dot(kNormal, -iNormal);
	lambertTerm = max(0.0f, min(1.0f, lambertTerm));
	vec3 diffuseColor = (fColor.xyz + kDiffuse) * iDiffuse * lambertTerm;

	//Calculate specular color
	vec3 surfaceToView = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal = reflect(iNormal, kNormal);
	float specularTerm = dot(surfaceToView, reflectionNormal);
	specularTerm = max(0.0f, specularTerm);
	specularTerm = pow(specularTerm, kSpecularPower);
	vec3 specularColor = (fColor.xyz + kSpecular) * iSpecular * specularTerm;

	




	//Second color
	///////////////////////////////////////////////////////////////////////////

	//Calculate ambient color for the second light
	vec3 ambientColor2 = (fColor.xyz + kAmbient) * iAmbient;

	//Calculate diffuse color for the second light
	float lambertTerm2 = dot(kNormal, -iNormal);
	lambertTerm2 = max(0.0f, min(1.0f, lambertTerm));
	vec3 diffuseColor2 = (fColor.xyz + kDiffuse) * iDiffuse * lambertTerm;


	//Calculate specular color for the second light
	vec3 surfaceToView2 = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal2 = reflect(iNormal, kNormal);
	float specularTerm2 = dot(surfaceToView2, reflectionNormal2);
	specularTerm2 = max(0.0f, specularTerm2);
	specularTerm2 = pow(specularTerm2, kSpecularPower);
	vec3 specularColor2 = (fColor.xyz + kSpecular) * iSpecular * specularTerm2;





	pColor = vec4(ambientColor2 + diffuseColor + specularColor, 1.0f);

}
