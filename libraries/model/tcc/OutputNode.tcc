////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     OutputNode.tcc (model)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

/// <summary> model namespace </summary>
namespace model
{
    template <typename ValueType>
    OutputNode<ValueType>::OutputNode(const model::OutputPortElements<ValueType>& input) : Node({&_input}, { &_output }), _input(this, input, inputPortName), _output(this, outputPortName, input.Size()){};

    template <typename ValueType>
    void OutputNode<ValueType>::Compute() const
    {
        _output.SetOutput(_input.GetValue());
    }

    template <typename ValueType>
    void OutputNode<ValueType>::Copy(ModelTransformer& transformer) const
    {
        auto newOutputPortElements = transformer.TransformOutputPortElements(_input.GetOutputPortElements());
        auto newNode = transformer.AddNode<OutputNode<ValueType>>(newOutputPortElements);
        transformer.MapOutputPort(output, newNode->output);
    }
}