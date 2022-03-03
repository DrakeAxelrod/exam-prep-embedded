# DIT635 Software Quality and Testing

> study guide

# Verification, Validation, and Defects
 Most relevant for this course: *dependability*
- Ability to consistently offer correct functionality, even under unforeseen or unsafe conditions.

## Quality Attributes
- Performance
  - Ability to meet timing requirements. When events occur, the system must respond quickly.
- Security
  - Ability to protect information from unauthorized access while providing service to authorized users.
- Scalability
  - Ability to “grow” the system to process more concurrent requests.

- Availability
  - Ability to carry out a task when needed, to minimize “downtime”, and to recover from failures.
- Modifiability
  - Ability to enhance software by fixing issues, adding features, and adapting to new environments.
- Testability
  - Ability to easily identify faults in a system.
  - Probability that a fault will result in a visible failure.
- Interoperability
  - Ability to exchange information with and provide functionality to other systems.
- Usability
  - Ability to enable users to perform tasks and provide support to users.
  - How easy it is to use the system, learn features, adapt to meet user needs, and increase confidence and satisfaction in usage.
- Resilience
- Supportability
- Portability
- Development Efficiency
- Time to Deliver
- Tool Support
- Geographic Distribution

### These qualities often conflict.
- Fewer subsystems improves performance, but hurts modifiability.
- Redundant data helps availability, but lessens security.
- Localizing safety-critical features ensures safety, but degrades performance.
- Important to decide what is important, and set a threshold on when it is “good enough”.

> Software is ready for release when you can argue that it is dependable.
> - Correct, reliable, safe, and robust.
> - Shown through Verification and Validation

## Verification and Validation
Activities that must be performed to consider the software “done.”
### Software Verification
> “Are we building the product right?”
The process of proving that the software conforms to its specified functional and non-functional requirements.
- Is the implementation consistent with its specification?
- Does the software work under conditions we set? (usually based on requirements)

Verification is an experiment.
- Perform trials, evaluate results, gather evidence.
- “Specification” and “implementation” are roles.

Usually source code and requirement specification. But also...

- Detailed design and high-level architecture.
- Design and requirements.
- Test cases and requirements.
- Source code and user manuals.

#### Software Testing

- An investigation into system quality.
- Based on sequences of stimuli and observations.
- Stimuli that the system must react to.
- Observations of system reactions.
- Verdicts on correctness.

### Software Validation
> “Are we building the right product?”

The process of proving that the software meets the customer’s true requirements, needs, and expectations.

# Software Quality

- internal quality
- external quality
- quality-in use

- fault
- failure

## Maintainability of your system

## Goal-question-metric approach

## How to draw GQM-graph





# Software Measurement & Analysis

## measurement scale

## cyclomatic complexity measures

## explore relationships in measurement data (techniques)

- list

## confirming a theory using measurement data (techniques)

- list

# Testing Basics

## Robust Equivalence-Class Testing

## All-Uses Coverage Criterion

## Equivalence class testing

1) Weak normal equivalence class testing
2) Weak robust equivalence class testing
3) Strong normal equivalence class testing
4) Strong robust equivalence class testing

## coverage criteria
> specify the minimum number of required test cases required in the test suite

## Drawing a classification tree with a decision table

# Test-Driven Development & Mocking

## Explain the test-driven development process

## strengths and weaknesses of test-driven development

# Path-Testing

## Drawing a control-flow graph

## Calculating all prime paths of the control-flow graph

## Computing the McCabe cyclomatic complexity

# Other Testing

## A/B testing

## Mutation testing

## Steps involved in the inspection procedure according to Fagan
