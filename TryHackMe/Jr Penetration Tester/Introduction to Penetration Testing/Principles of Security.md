
## The CIA Triad

## Principles of Privileges

- Privileged Identity Management
	- The role of a user in an organization
- Privileged Access Management 
	- The privileges given to a certain role
	- This also includes password management, auditing policies and reducing the attack surface of a system


## Security Models Continued 

#### The Bell-LaPadula Model 

- Used to achieve confidentiality 
 - The models grants pieces of data known as objects in this case, access. 
 - It's simple to implement and understand
 - Policies in this model can be replicated to real life organizations. 
 - In this model a user would know about it's existence so it's technically not confidential 
 - Relies on trust within an organization
 - This model is best for organizations where the employees have been properly vetted, the military for example. 

#### Biba Model 

- For integrity
- Applies rules to data and users
- "No write up, no read down"
- The user can create objects below or at their level but can only read objects above their level. 
- Simple to implement 


## Threat Modeling and Incident Response

Threat Modeling Process
 - Preparation
 - Identification 
 - Mitigations 
 - Review

Effective Threat Models Include: 
- Threat Intelligence
- Asset Identification
- Mitigation Capabilities
- Risk Assessment

#### STRIDE

Spoofing - A malicious user poses as a legitimate  
Tampering - When data or a system has been altered in some way
Repudiation - Documentation and tracking of systems 
Information Disclosure - Relevant information should only be shown to specific users
Denial of Service - An application is overloaded by requests (this is an example)
Elevation of Privilege - A malicious user is granted root or admin access (or can just be above that of the user they exploited). 

#### CSIRT  (Computer Security Incident Response Team)

Preparation  - Are plans in place to mitigate an issue
Identification - Are users able to properly authenticate themselves against our system
Containment - Can the incident be isolated
Eradication  - Can the exposure be removed 
Recovery - Can systems be brought back to normal operating standards
Lessons Learned - How can systems be better protected in the future